/*
 * cguess - C/C++/Java(tm) auto-completion tool for VIM
 * Copyright (C) 2005 Andrzej Zaborowski <balrogg@gmail.com>
 * All Rights Reserved
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/*
 * The syntactic analyser.
 *
 * Loosely based on the ISO/IEC C++ grammar, GCC's grammar and also the
 * writings of James A. Roskind.
 */
%{
#	include <string.h>
#	include <stdio.h>

#	include "parser.h"
#	include "cguess.h"
#	include "scope.h"
#	include "sstack.h"
#	include "fifo.h"
#	include "type.h"
#	include "language.h"

#	define YYSTYPE	token_val_t
#	define yyparse	parse
#	define yyerror	error
#	define yydebug	debug
#	define yylex	lexer

#	define PARSER_INIT()	\
		scope_init();	\
		sstack_init(&id_stack, sizeof(char *));	\
		sstack_init(&type_stack, sizeof(struct type_s));	\
		fifo_init(id_fifo)

#	define PARSER_DONE()	\
		scope_done();	\
		sstack_done(&id_stack);	\
		sstack_done(&type_stack)

#	define IDENTIFIER_EMPTY()	\
		last_id[0] = 0

#	define IDENTIFIER_AUTO()	\
		sprintf(last_id, "%i", auto_id ++)

#	define IDENTIFIER(str)	\
		strncpy(last_id, str, MAX_ID_LEN)

#	define PUSH_ID(x)	\
		*(char **) sstack_push(&id_stack) = x

#	define PUSH_AUTO_ID()	\
		PUSH_ID(0)
/* TODO: remove. move all automatic ID generation to scope.c */

#	define PUSH_AUTO_NUM_ID()	\
		PUSH_ID("?")

#	define PUSH_OP_ID(op)	/* TODO */	\
		PUSH_ID(op.definition->name)

#	define POP_ID()	\
		(*(char **) sstack_pop(&id_stack))

#	define TOP_ID()	\
		(*(char **) sstack_top(&id_stack))

#	define POPFREE_ID()	\
		sstack_pop(&id_stack)

#	define PUSH_TYPE(x)	\
		(*(struct type_s *) sstack_push(&type_stack)) = x

#	define POP_TYPE()	\
		(*(struct type_s *) sstack_pop(&type_stack))

#	define TOP_TYPE()	\
		(*(struct type_s *) sstack_top(&type_stack))

#	define PASS_ID()	\
		PUSH_ID(fifo_pop(id_fifo))

#	define POPFREE_TYPE()	\
		type_dispose(POP_TYPE())

#	define ENTER(class)	\
		scope_open(POP_ID(), class, POP_TYPE())

#	define ENTER_ANONYMOUS()	/* TODO: Assign an AUTO_ID */	\
		scope_open(0, unnamed_c, type_simple(void_t))

#	define LEAVE()	\
		scope_close()

#	define ENTER_PARAMS_AT(type)	\
		type.nested ? scope_open_params(type.definition) : \
		scope_open_params(0)

#	define ENTER_PARAMS()	\
		scope_open_params(0)

#	define TYPE_SET(type)	\
		type_dispose(last_type); \
		last_type = type

#	define TYPE_GET()	/* TODO: */	\
		(__extension__ ({ struct identifier_s *__id =	\
			scope_lookup(TOP_ID());	\
			__id ? type_copy(__id->type) :	\
					type_simple(void_t); }))

#	define TYPE_THIS()	\
		scope_this()

#	define TYPE_LOOKUP(class)	\
		type_copy(scope_local_lookup(class, POP_ID()))

#	define TYPE_FN_OR_CTOR(type, is_ctor)	\
		is_ctor.nested ? type_return(type) : type

#	define TYPE_OP(op)	\
		({ scope_stmt_pop(); scope_define_operator(op); })

#	define DEFINE(class)	\
		type_copy(scope_define(POP_ID(), class, POP_TYPE()))

#	define DEFINE_VAR_OR_FUNC(x)	\
		if (is_type_def)	\
			scope_define(POP_ID(), typename_c,	\
			type_connect(type_copy(TOP_TYPE()), x));	\
		else	\
			scope_define(POP_ID(), variable_c, \
			type_connect(type_copy(TOP_TYPE()), x))

#	define DEFINE_VA_LIST()	\
		scope_define("...", variable_c, type_simple(void_t))

#	define USING()	\
		scope_using(POP_TYPE())

#	define USING_ID(type)	\
		scope_using_id(type, id_class, POP_ID())

#	define DESTRUCTOR_ID()	\
		POPFREE_TYPE();	\
		TOP_ID() = identifier_destructor(TOP_ID())

#	define ID_CLASS(class)	\
		id_class = class

#	define ID_MANGLE()	\
		TOP_ID() = is_destructor ? identifier_destructor(TOP_ID()) : \
			identifier_constructor(TOP_ID()); is_destructor = 0

/* TODO: check for destructors */
#	define ID_FROM_TYPE()	\
		(__extension__ ({ struct identifier_s *__id =	\
			POP_TYPE().definition;	\
			if (!__id)	\
				PUSH_ID("bad_constructor");	\
			else if (__id->name[0] == '%')	\
				PUSH_ID(__id->name + 1);	\
			else	\
				PUSH_ID(__id->name); }))

#	define SET_CV(type)	\
		type.is_const |= is_const;	\
		is_const = 0;	\
		type.is_static |= is_static;	\
		is_static = 0

#	define SET_FSPEC(type)	\
		if (is_virtual)	\
			type = type_virtual(type);	\
		is_virtual = 0;	\
		if (is_const)	\
			type = type_function_const(type);	\
		is_const = 0;	\
		type_fn_reference(type)

#	define GNU_ANONYMOUS_UNION(tp)	\
		if (tp.category == classy_t &&	\
				tp.class_type.type == union_t &&	\
				tp.definition &&	\
/* TODO: Change the following condition when AUTO_IDs will be done */	\
				!tp.definition->name)	\
			scope_using(tp);	\
		else	\
			type_dispose(tp)

	/*
	 * This controls if enumerators are accessible from
	 * the enum type's parents scope. This is practically
	 * useless in cguess and adds a serious speed overhead.
	 */
#	ifndef NDEBUG
#	 define USING_ENUMS
#	endif /* NDEBUG */

	/*
	 * We have these global variables for the purpose of
	 * inheritance of attributes between siblings in the
	 * grammar tree.
	 */
	int is_type_def = 0;
	int is_const = 0;
	int is_static = 0;
	int is_virtual = 0;

	/*
	 * The stacks of attributes.
	 */
	struct sstack_s id_stack;
	struct sstack_s type_stack;
	fifo(char *) id_fifo;

	/*
	 * The class of identifier returned by
	 * NESTED_TYPE_OR_NAME_SPECIFIER.
	 */
	identifier_class_t id_class;
	int is_destructor = 0;
	extern char* last_string;

	/*
	 * yydebug tells the parser if it should display information
	 * on the shifts and reductions that it is doing on stderr.
	 */
	int yydebug = 1;
%}

/*
 * TODO: Optimize the grammar:
 * make all _LIST, _SEQ style rules right-side,
 * remove useless symbols,
 * move the ENTER & LEAVE tags to COMPOUND_STATEMENT (beware functions tho),
 * remove FUNCTION and SUBSCRIPT, and others,
 * make sure type_dispose() is called for all $$ when not used,
 * for unnamed namespaces set the id to <unnamed>,
 * two-stage (dependent) identifier lookup (gcc info pages),
 * resolve conflicts,
 * move nested names to the lexer (not necesarily),
 * some basic error recovery (pronounce: error ignoring),
 * make two types of symbol tables, those ordered and normal (for params),
 * signal the lexer when we don't need to PUSH the ID for sure so we can
 * save some time,
 * add ansi Old-style parameter lists (protoize?),
 * add a C mode for the lexer,
 * copy (malloc & strcpy) ids where typenames are redefined, to be able to
 * normally free ids memory when freeing symbols,
 * get rid of IDENTIFIER_OPT,
 * use %destructor for freeing semantic values,
 * correctly distribute the reference depth between a function type and
 * its return type,
 * support for .fieldname in struct initializers like in kernel modules,
 * correctly ignore all __attribute__ ((stuff)),
 * pointers to labels,
 * support for GNU case ranges,
 * support for .gch precompiled headers,
 * other
 *
 */

/*%debug*/
%error-verbose
%expect 69

/* Parser's input tokens, the grammar's terminal symbols */
%token T_IDENTIFIER

%token T_TYPEDEF_ID
%token T_ENUM_ID
%token T_NAMESPACE_ID
%token T_ALIAS_ID
%token T_CLASS_ID
%token T_TEMPLATE_ID
/* possibly MEM_INITIALIZER_ID or something */

/* C++ literal constants */
%token T_NUM_LITERAL
%token T_CHAR_LITERAL
%token T_STRING_LITERAL
%token T_BOOLEAN_LITERAL

/* Operators & symbols */
%token T_LANGLE
%token T_RANGLE
%token T_LPAREN
%token T_RPAREN
%token T_ELIPSIS
%token T_COMMA
%token T_LBRACK
%token T_RBRACK
%token T_LBRACE
%token T_RBRACE
%token T_EQ
%token T_SCOPE
%token T_SEMIC
%token T_COLON
%token T_DOTSTAR
%token T_QUESTION
%token T_DOT

/* Keywords [gram.key] */
%token T_DYNAMIC_CAST
%token T_STATIC_CAST
%token T_REINTERPRET_CAST
%token T_CONST_CAST
%token T_TYPEID
%token T_THIS
%token T_TEMPLATE
%token T_TYPENAME
%token T_THROW
%token T_TRY
%token T_CATCH
%token T_TYPEDEF
%token T_FRIEND
%token T_CLASS
%token T_NAMESPACE
%token T_ENUM
%token T_STRUCT
%token T_UNION
%token T_VIRTUAL
%token T_PRIVATE
%token T_PROTECTED
%token T_PUBLIC
%token T_EXPORT
%token T_AUTO
%token T_REGISTER
%token T_EXTERN
%token T_MUTABLE
%token T_ASM
%token T_USING
%token T_INLINE
%token T_EXPLICIT
%token T_STATIC
%token T_CONST
%token T_VOLATILE
%token T_OVERLOAD	/* This is from ANSI, not in ISO */
%token T_OPERATOR
%token T_SIZEOF
%token T_NEW
%token T_DELETE

/* Operators */
%token T_PLUS
%token T_MINUS
%token T_STAR
%token T_SLASH
%token T_PERCENT
%token T_HAT
%token T_AND
%token T_OR
%token T_TILDE
%token T_NOT
%token T_PLUS_EQ
%token T_MINUS_EQ
%token T_STAR_EQ
%token T_SLASH_EQ
%token T_PERCENT_EQ
%token T_HAT_EQ
%token T_AND_EQ
%token T_OR_EQ
%token T_LTLT
%token T_GTGT
%token T_GTGT_EQ
%token T_LTLT_EQ
%token T_EQEQ
%token T_NE
%token T_LE
%token T_GE
%token T_ANDAND
%token T_OROR
%token T_INCR
%token T_DECR
%token T_ARROW_STAR
%token T_ARROW
%token T_FUNCTION
%token T_SUBSCRIPT

/* Predefined (primitive) type names */
%token T_CHAR
%token T_WCHAR
%token T_BOOL
%token T_SHORT
%token T_INT
%token T_LONG
%token T_SIGNED
%token T_UNSIGNED
%token T_FLOAT
%token T_DOUBLE
%token T_VOID

/* Keywords */
%token T_CASE
%token T_DEFAULT
%token T_IF
%token T_ELSE
%token T_SWITCH
%token T_WHILE
%token T_DO
%token T_FOR
%token T_BREAK
%token T_CONTINUE
%token T_GOTO
%token T_RETURN

/* Some GNU extensions. We don't support all of them. */
%token T_TYPEOF
%token T_THREAD
%token T_MINIMUM
%token T_MAXIMUM

/* ISO C */
%token T_RESTRICT

/* Additional token that signals end of the file */
%token T_SPECIAL

/* The token with the highest number for defining tables */
%token T_LAST_TOKEN

/*
 * Add precedence rules to solve dangling else s/r conflict
 * (GCC uses %nonassoc but we can't be that sensitive)
 */
%left T_ELSE
%left T_IF

/*
 * These help yacc to resolve the SR conflict between
 * expressions and declarations (in favour of declaration).
 *
 * TODO: don't use precedence for this, expand the grammar.
 */
%left T_COMMA T_RANGLE
%left T_SCOPE T_LPAREN T_FUNCTION
%left PREC

%%

/* Basic Concepts [gram.basic] */

TRANSLATION_UNIT:			{ PARSER_INIT(); }
	DECLARATION_SEQ T_SPECIAL	{ PARSER_DONE(); }
;

/* Lexical Conventions [gram.lex] */

LITERAL:
	T_NUM_LITERAL			{ $$ = type_simple(int_t); }
|	T_CHAR_LITERAL			{ $$ = type_simple(char_t); }
|	T_STRING_LITERAL STRING_LIST	{ $$ = type_string(); }
|	T_BOOLEAN_LITERAL		{ $$ = type_simple(int_t); }
;

/* TODO: move to the lexer or somewhere */
STRING_LIST:
	/* Empty */
|	T_STRING_LITERAL STRING_LIST
;

IDENTIFIER_OPT:
	/* Empty */			{ PUSH_AUTO_ID(); }
|	IDENTIFIER_C			{ type_dispose($1); }
;

IDENTIFIER_C:
	T_IDENTIFIER			{ PASS_ID(); $$ = $1; }
;

ELIPSIS_OPT:
	/* Empty */
|	T_ELIPSIS			{ DEFINE_VA_LIST(); }
;

TYPENAME_OPT:
	/* Empty */
|	T_TYPENAME
;

/* Declarations [gram.dcl.dcl] */

/*
 * Must be left recursive or we'll most probably get stack overflow.
 */
DECLARATION_SEQ:
	DECLARATION
|	DECLARATION_SEQ DECLARATION
;

DECLARATION_SEQ_OPT:
	/* Empty */
|	DECLARATION_SEQ
;

DECLARATION:
	BLOCK_DECLARATION
|	FUNCTION_DEFINITION
|	TEMPLATE_DECLARATION
|	EXPLICIT_INSTANTIATION
|	EXPLICIT_SPECIALIZATION
|	LINKAGE_SPECIFICATION
|	NAMESPACE_DEFINITION
;

BLOCK_DECLARATION:
	SIMPLE_DECLARATION
|	ASM_DEFINITION
|	NAMESPACE_ALIAS_DEFINITION
|	USING_DECLARATION
|	USING_DIRECTIVE
;

/*
 * Inline expanded to disallow redefinitions with no type given.
 * I believe it won't hurt.
 *
 * TODO: Inline expand even more to forbid the first declarator
 * to start with :: (it should then have a trailing asterisk or
 * T_LPAREN or something) when the last part of the declarator
 * was a typedef name or other.
 *
 * TODO: In case of a lone declaration specifier without any
 * declarators, make a declaration in the current scope, if it
 * is a class, and if the name is not nested.
 *
 * TODO: In case of OBVIOUSLY_A_DECLARATOR allow INITIALIZER_OPT,
 * same for member declarations.
 */
SIMPLE_DECLARATION:
	DECL_SPECIFIER_SEQ_START
	T_SEMIC				{ $$ = POP_TYPE();
					  GNU_ANONYMOUS_UNION($$);
					  is_type_def = 0; }
|	DECL_SPECIFIER_SEQ_START NON_PAREN_INIT_DECLARATOR
	COMMA_INIT_DECLARATOR_LIST_OPT
	T_SEMIC				{ POPFREE_TYPE(); is_type_def = 0; }
|	DECL_SPECIFIER_SEQ_START PAREN_NON_REDEF_INIT_DECLARATOR
	COMMA_INIT_DECLARATOR_LIST_OPT
	T_SEMIC				{ POPFREE_TYPE(); is_type_def = 0; }
|	DECL_SPECIFIER_SEQ_START PARAMETER_LIST_MEMBER_DECLARATOR
	COMMA_INIT_DECLARATOR_LIST_OPT
	T_SEMIC				{ POPFREE_TYPE(); is_type_def = 0; }
|	OBVIOUSLY_A_DECLARATOR COMMA_INIT_DECLARATOR_LIST_OPT
	T_SEMIC				{ DEFINE(variable_c); }
|	T_SEMIC
;

/*
 * This part is quite different from the ISO/IEC version. It has
 * been modified to accept only one real declaration specifier and
 * not a list of them. This helps to disambiguate the grammar in
 * many places. It is based on how GCC parses declaration
 * specifiers but trying to ignore the semantic contraints of
 * GCC. This involves allowing any list of predefined type names
 * and modifiers (mixed), however nonsense. But if the list of
 * type names contains a non-predefined type name then this name
 * can be preceded only by modifiers and no predefined type names
 * (See tests/tst5/f.C). This may seem strange but it resolves
 * several conflicts, and correctly disambiguates situations like:
 *
 *		void class1::member_function1()
 *
 * and at the same time is almost as flexible as the ISO/IEC
 * version.
 *
 * Note: remember to move this rule if the whole "expressions"
 * section is moved before "declarations" section. James A. Roskind
 * writes: The following production for type_qualifier_list was
 * specially placed BEFORE the definition of postfix_expression to
 * resolve a reduce-reduce conflict set correctly. Note that a
 * type_qualifier_list is only used in a declaration, whereas a
 * postfix_expression is clearly an example of an expression. Hence
 * we are helping with the "if it can be a declaration, then it is"
 * rule. The reduce conflicts are on ')', ',' and '='. Do not move
 * the following productions.
 *
 * When modifying DECL_SPECIFIER_SEQ remember to apply respective
 * changes to TEMPLATE_DECL_SPECIFIER_SEQ too.
 */
DECL_SPECIFIER_SEQ_START:
	DECL_SPECIFIER_SEQ		{ PUSH_TYPE($1); }
;

DECL_SPECIFIER_SEQ:
	T_FRIEND
	DECL_SPECIFIER_SEQ_RIGHT	{ $$ = $2; }
|	T_TYPEDEF
	DECL_SPECIFIER_SEQ_RIGHT	{ $$ = $2;
					  is_type_def = 1; }
|	STORAGE_CLASS_SPECIFIER
	DECL_SPECIFIER_SEQ_RIGHT	{ $$ = $2; }
|	FUNCTION_SPECIFIER
	DECL_SPECIFIER_SEQ_RIGHT	{ $$ = $2; }
|	CV_QUALIFIER
	DECL_SPECIFIER_SEQ_RIGHT	{ $$ = $2; }
|	SIMPLE_TYPE_SPECIFIER
	STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_BIT_FLD_OR_SIMPLE_SPEC_LIST_OPT
					{ $$ = type_connect($1, $2);
					  SET_CV($$); }
|	NAMED_TYPE_SPECIFIER
	STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_OR_SIMPLE_SPEC_LIST_OPT
					{ $$ = type_connect($1, $2);
					  SET_CV($$); }
;

DECL_SPECIFIER_SEQ_RIGHT:
	STORAGE_CLASS_FUNCTION_FRIEND_OR_TYPEDEF_SPEC_LIST_OPT
					{ $$ = type_simple(void_t);
					  SET_CV($$); }
|	STORAGE_CLASS_FUNCTION_FRIEND_OR_TYPEDEF_SPEC_LIST_OPT
	SIMPLE_TYPE_SPECIFIER
	STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_BIT_FLD_OR_SIMPLE_SPEC_LIST_OPT
					{ $$ = type_connect($2, $3);
					  SET_CV($$); }
|	STORAGE_CLASS_FUNCTION_FRIEND_OR_TYPEDEF_SPEC_LIST_OPT
	NAMED_TYPE_SPECIFIER
	STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_OR_SIMPLE_SPEC_LIST_OPT
					{ $$ = type_connect($2, $3);
					  SET_CV($$); }
;

/*
 * Must be right recursive.
 */
STORAGE_CLASS_FUNCTION_FRIEND_OR_TYPEDEF_SPEC_LIST_OPT:
	/* Empty */
|	T_FRIEND STORAGE_CLASS_FUNCTION_FRIEND_OR_TYPEDEF_SPEC_LIST_OPT
|	T_TYPEDEF STORAGE_CLASS_FUNCTION_FRIEND_OR_TYPEDEF_SPEC_LIST_OPT
					{ is_type_def = 1; }
|	STORAGE_CLASS_SPECIFIER
	STORAGE_CLASS_FUNCTION_FRIEND_OR_TYPEDEF_SPEC_LIST_OPT
|	FUNCTION_SPECIFIER
	STORAGE_CLASS_FUNCTION_FRIEND_OR_TYPEDEF_SPEC_LIST_OPT
|	CV_QUALIFIER
	STORAGE_CLASS_FUNCTION_FRIEND_OR_TYPEDEF_SPEC_LIST_OPT
;

/*
 * Must be right recursive.
 *
 * TODO: it should perhaps be int and not void.
 */
STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_OR_SIMPLE_SPEC_LIST_OPT:
	/* Empty */ %prec PREC		{ $$ = type_simple(void_t); }
|	T_FRIEND
	STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_OR_SIMPLE_SPEC_LIST_OPT
	%prec PREC			{ $$ = $2; }
|	T_TYPEDEF
	STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_OR_SIMPLE_SPEC_LIST_OPT
	%prec PREC			{ $$ = $2; is_type_def = 1; }
|	STORAGE_CLASS_SPECIFIER
	STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_OR_SIMPLE_SPEC_LIST_OPT
	%prec PREC			{ $$ = $2; }
|	FUNCTION_SPECIFIER
	STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_OR_SIMPLE_SPEC_LIST_OPT
	%prec PREC			{ $$ = $2; }
|	CV_QUALIFIER
	STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_OR_SIMPLE_SPEC_LIST_OPT
	%prec PREC			{ $$ = $2; }
|	SIMPLE_TYPE_SPECIFIER
	STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_OR_SIMPLE_SPEC_LIST_OPT
	%prec PREC			{ $$ = type_connect($1, $2); }
;

/*
 * Unnamed bit fields are here, to avoid ambiguities. We don't
 * need any action for unnamed bit fields. TODO: place this
 * elsewhere and make a separate DECL_SPECIFIER_SEQ that doesn't
 * allow structs.
 */
STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_BIT_FLD_OR_SIMPLE_SPEC_LIST_OPT:
	STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_OR_SIMPLE_SPEC_LIST_OPT
					{ $$ = $1; }
|	STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_OR_SIMPLE_SPEC_LIST_OPT
	BIT_FIELD_DECLARATOR		{ $$ = $1; }
;

STORAGE_CLASS_SPECIFIER:
	T_AUTO
|	T_REGISTER
|	T_STATIC			{ is_static = 1; }
|	T_EXTERN
|	T_MUTABLE
|	T_THREAD
;

FUNCTION_SPECIFIER:
	T_INLINE
|	T_VIRTUAL			{ is_virtual = 1; }
|	T_EXPLICIT
;

TYPEDEF_NAME:
	T_TYPEDEF_ID			{ PUSH_TYPE($1); PASS_ID(); }
;

/*
 * Changed CLASS_SPECIFIER, ENUM_SPECIFIER and
 * ELABORATED_TYPE_SPECIFIER for CLASS_ENUM_OR_ET_SPECIFIER.
 * CV_QUALIFIER and SIMPLE_TYPE_SPECIFIER has been moved to
 * STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_OR_SIMPLE_SPEC_LIST_OPT
 *
 * The precedence modifier here is to assure that
 * NAMED_TYPE_SPECIFIER gets priority over POSTFIX_EXPRESSION
 * in the conflicts between an expression and a declaration (like
 * the ambiguity of a parameter list and call to constructor).
 *
 * TODO: don't use precedence.
 *
 * TODO: T_TYPEOF T_LPAREN TYPE_SPECIFIER_SEQ
 * ABSTRACT_DECLARATOR_OPT T_RPAREN possibly non abstract too.
 */
NAMED_TYPE_SPECIFIER:
	NESTED_TYPE_NAME_SPECIFIER
	%prec PREC			{ $$ = POP_TYPE(); POPFREE_ID();
					  $$.nested = $1.nested; }
|	CLASS_ENUM_OR_ET_SPECIFIER	{ $$ = $1; }
|	T_TYPEOF T_LPAREN UNQUALIFIED_ID
	T_RPAREN			{ $$ = $3; }
;

/*
 * A NAMED_TYPE_SPECIFIER that doesn't allow a name starting with
 * T_TYPENAME, for use in template parameters lists.
 */
STRICT_NAMED_TYPE_SPECIFIER:
	STRICT_NESTED_TYPE_NAME_SPECIFIER
					{ $$ = POP_TYPE(); POPFREE_ID(); }
|	CLASS_ENUM_OR_ET_SPECIFIER	{ $$ = $1; }
|	T_TYPEOF T_LPAREN UNQUALIFIED_ID
	T_RPAREN			{ $$ = $3; }
;

/*
 * Changed CLASS_SPECIFIER, ENUM_SPECIFIER and
 * ELABORATED_TYPE_SPECIFIER for CLASS_ENUM_OR_ET_SPECIFIER.
 *
 * When making any changes here, remeber to apply respective
 * changes to NON_ELABORATING_TYPE_SPECIFIERS as well.
 */
TYPE_SPECIFIER:
	NESTED_TYPE_NAME_SPECIFIER	{ $$ = POP_TYPE(); POPFREE_ID(); }
|	SIMPLE_TYPE_SPECIFIER		{ $$ = $1; }
|	CLASS_ENUM_OR_ET_SPECIFIER	{ $$ = $1; }
|	CV_QUALIFIER			{ $$ = type_simple(void_t);
					  SET_CV($$); }
;

/*
 * TODO: before allowing only one SIMPLE_TYPE_SPECIFIER per
 * DECL_SPECIFIER_SEQ, remember to move T_SIGNED, T_UNSIGNED
 * and T_LONG to some list. - Obsoleted
 *
 * TEMPLATE_ID stuff is commented out for now cause it
 * conflicts with TYPE_NAME, as TYPE_NAME can be a CLASS_NAME
 * which in turn can be TEMPLATE_ID.
 *
 * SCOPE_OPT NESTED_NAME_SPECIFIER T_TEMPLATE TEMPLATE_ID has
 * been removed because it is now contained in the first rule.
 *
 * NESTED_TYPE_NAME_SPECIFIER has moved out to TYPE_SPECIFIER.
 */
SIMPLE_TYPE_SPECIFIER:
	T_CHAR				{ $$ = type_simple(char_t); }
|	T_WCHAR				{ $$ = type_simple(char_t); }
|	T_BOOL				{ $$ = type_simple(bool_t); }
|	T_SHORT				{ $$ = type_simple(short_t); }
|	T_INT				{ $$ = type_simple(int_t); }
|	T_LONG				{ $$ = type_simple(int_t); }
|	T_SIGNED			{ $$ = type_simple(int_t);
					  $$ = type_signed($$); }
|	T_UNSIGNED			{ $$ = type_simple(int_t);
					  $$ = type_unsigned($$); }
|	T_FLOAT				{ $$ = type_simple(float_t); }
|	T_DOUBLE			{ $$ = type_simple(double_t); }
|	T_VOID				{ $$ = type_simple(void_t); }
;

TYPE_NAME:
	CLASS_NAME
|	CLASS_NAME T_LANGLE TEMPLATE_ARGUMENT_LIST_OPT T_RANGLE
|	ENUM_NAME
|	TYPEDEF_NAME
|	TYPEDEF_NAME T_LANGLE TEMPLATE_ARGUMENT_LIST_OPT T_RANGLE
;

/*
 * Substitutes the original CLASS_SPECIFIER, ENUM_SPECIFIER and
 * ELABORATED_TYPE_SPECIFIER to resolve the CLASS_KEY, T_ENUM and
 * CLASS_HEAD conflicts.
 *
 * The type of the class is inherited by CLASS_ET_SHORT from
 * CLASS_KEY_ID here, by the stack so we skip it here.
 *
 * T_TYPENAME productions now obsoleted by new
 * NESTED_TYPE_NAME_SPECIFIER.
 */
CLASS_ENUM_OR_ET_SPECIFIER:
	CLASS_KEY CLASS_ET_SHORT	{ $$ = $2; }
|	ENUM_PUSH ENUM_ET_SHORT		{ $$ = $2; }
;

/*
 * TODO: This will push a type later.
 */
ENUM_PUSH:
	T_ENUM
;

/*
 * Substitutes CLASS_SPECIFIER and the ELABORATED_TYPE_SPECIFIER
 * when we know that CLASS_KEY token has been consumed.
 *
 * The first production has CLASS_OR_ET_SHORT in case the class
 * was declared before and is being define now.
 *
 * TODO: there is some production that has a conflict with this
 * CLASS_OR_ET_SHORT (which can only start with a T_COLON or
 * T_LBRACE) in the first production here. Check where and why.
 * (same for enums, it appears, but maybe not).
 */
CLASS_ET_SHORT:
	CLASS_REDEF_OR_ET		{ $$ = $1; }
|	IDENTIFIER_C CLASS_OR_ET_SHORT	{ $$ = $2; type_dispose($1); }
|	TEMP_ID CLASS_SPECIFIER_SHORT	{ $$ = $2; }
;

/*
 * Now we know that CLASS_KEY and identifier have been consumed
 * in this order. It may now be an elaborated type specifier or,
 * if there's class stuff next (COMPOUND_STMT or BASE_SPEC), a
 * class specifier.
 *
 * We reserve place for future declarations because they may be
 * used for drawing a pretty identifier tree...
 */ 
CLASS_OR_ET_SHORT:
	CLASS_SPECIFIER_SHORT		{ $$ = $1; }
|	/* Empty */			{ $$ = DEFINE(class_c); }
;

/*
 * Same as above but in this case the type has been declared
 * earlier and we won't store it again because it may have been
 * declared outside the current namespace.
 *
 * Here we are incompatible with the standards because in C++
 * if x has been defined in a different scope but is accessible,
 * class x; will be a declaration a new class x in the current
 * scope, but if it is followed by an identifier (class x y;),
 * it doesn't declare anything, it is a definition of y.
 * TODO: We opt for the latter case for now. It should be
 * resolved later, in SIMPLE_DECLARATION.
 */
CLASS_REDEF_OR_ET:
	TYPE_POP CLASS_SPECIFIER_SHORT	{ $$ = $2; }
|	NESTED_TYPE_NAME_SPECIFIER	{ $$ = POP_TYPE();
					  $$ = type_connect($$, POP_TYPE());
					  POPFREE_ID(); }
;

/*
 * For this to be reduced the T_LBRACE or T_COLON will already have
 * to be read. We free the top type on the stack, so the one that's
 * left on stack is a new type, pushed by CLASS_KEY. This way, the
 * new class is connected with the old one that's being redefined.
 */
TYPE_POP:
	NESTED_TYPE_NAME_SPECIFIER	{ $$ = POP_TYPE();
					  $$.nested = $1.nested;
					  $$ = type_connect($$, POP_TYPE());
					  PUSH_TYPE($$); }
;

ENUM_NAME:
	T_ENUM_ID			{ PUSH_TYPE($1); PASS_ID(); }
;

/*
 * Substitutes ENUM_SPECIFIER and the ELABORATED_TYPE_SPECIFIER
 * when we know that T_ENUM token has been consumed.
 *
 * The first production has ENUM_OR_ET_SHORT in case the enum
 * was declared before and is being defined now.
 *
 * Here it doesn't matter if we're inside a typedef construct
 * cause all enums are type names and the grammar takes care
 * of it (I hope!).
 *
 * The DEFINE() can come after the whole ENUM_CLAUSE (contrary
 * to the case of classes) because there is no content in this
 * clause that could refer to this definition.
 *
 * Not true! Roskind states "enum A { first = sizeof(A) };" as
 * an example, but for now we don't care about the values.
 * Also GCC chokes on this particular example. When compiled as
 * C, the A inside is reported undeclared, and for C++ it is an
 * incomplete type and thus sizeof fails during semantic check,
 * but the identifier is declared. Well, we prefer the latter
 * for this parser but for now it is the former.
 */
ENUM_ET_SHORT:
	NESTED_TYPE_NAME_SPECIFIER
	ENUM_REDEF_OR_ET		{ $$ = $2; }
|	IDENTIFIER_C ENUM_OR_ET_SHORT	{ $$ = $2; type_dispose($1); }
|	TEMP_ID ENUM_SPECIFIER_SHORT	{ $$ = $2;
#ifdef USING_ENUMS
					  PUSH_TYPE($2); USING();
#endif /* USING_ENUMS */
					}
;

TEMP_ID:
	/* Empty */			{ PUSH_AUTO_ID(); }
;

/*
 * Now we know that ENUM_T and an identifier have been consumed
 * in this order. It may now be an elaborated type or, if there's
 * enum stuff next (ENUMERATOR_CLAUSE), an enum specifier
 * (or what's left of it).
 *
 * In case the type has not yet been defined, we will only
 * store it's name and look it up when the type is used for some
 * variable.
 */ 
ENUM_OR_ET_SHORT:
	ENUM_SPECIFIER_SHORT		{ $$ = $1;
#ifndef USING_ENUMS
					  PUSH_TYPE($1); USING();
#endif /* USING_ENUMS */
					}
|	/* Empty */			{ PUSH_TYPE(type_enum());
					  $$ = DEFINE(enum_c); }
;

/*
 * Same as above but in this case the type has been declared
 * earlier and we won't store it in this context, again.
 *
 * TODO:
 * There is an ambiguity here, in the second production. For
 * now we will go the easy and ANSI incompatible way, and
 * return the type not defining it, but this must change later.
 * it is the same case that in CLASS_REDEF_OR_ET.
 *
 * TODO: also here and above applies perhaps the same that to
 * UNNAMED_NAMESPACE_DEFINITIONs - the USING() should appear
 * before entering the enum's scope so that the enumerators
 * are from the beginning accessible in both scopes.
 */
ENUM_REDEF_OR_ET:
	TYPE_TO_ENUM
	ENUM_SPECIFIER_SHORT		{ $$ = $2;
#ifndef USING_ENUMS
					  PUSH_TYPE($2); USING();
#endif /* USING_ENUMS */
					}
|	/* Empty */			{ $$ = type_connect(POP_TYPE(),
							type_enum());
					  POPFREE_ID(); }
;

TYPE_TO_ENUM:
	/* Empty */			{ POPFREE_TYPE(); }
;

/*
 * The right part of the ENUM_SPECIFIER production.
 */
ENUM_SPECIFIER_SHORT:
	ENUMERATOR_CLAUSE_LEFT
	ENUMERATOR_CLAUSE_RIGHT		{ $$ = $1; }
;

/*
 * The opening of the enumerator type's clause.
 *
 * By returning the same type that we name the new scope,
 * we assure that they will be associated.
 */
ENUMERATOR_CLAUSE_LEFT:
	T_LBRACE			{ PUSH_TYPE(type_enum());
					  $$ = type_copy(ENTER(enum_c)); }
;

/*
 * The interior and the closing of the enumerator type's clause.
 * Modified to accept one excessive T_COMMA.
 */
ENUMERATOR_CLAUSE_RIGHT:
	ENUMERATOR_LIST T_RBRACE	{ LEAVE(); }
|	ENUMERATOR_LIST T_COMMA
	T_RBRACE			{ LEAVE(); }
|	T_RBRACE			{ LEAVE(); }
;

/*
 * Modified to be left side recursive.
 */
ENUMERATOR_LIST:
	ENUMERATOR_DEFINITION
|	ENUMERATOR_LIST T_COMMA ENUMERATOR_DEFINITION
;

/*
 * TODO: Add something like this to the second one here:
 * |	ENUMERATOR T_EQ error (T_COMMA)
 * |	ENUMERATOR T_EQ error (T_LBRACE)
 * This could maybe even speed parsing up if the current second
 * production is removed, but it also may provoke a syntax error
 * where there isn't any
 */
ENUMERATOR_DEFINITION:
	ENUMERATOR
|	ENUMERATOR T_EQ CONSTANT_EXPRESSION
;

/*
 * We treat enumerator constants as variables.
 */
ENUMERATOR:
	IDENTIFIER_C			{ PUSH_TYPE(type_simple(int_t));
					  type_dispose(DEFINE(variable_c));
					  type_dispose($1); }
;

NAMESPACE_NAME:
	ORIGINAL_NAMESPACE_NAME
|	NAMESPACE_ALIAS
;

ORIGINAL_NAMESPACE_NAME:
	T_NAMESPACE_ID			{ PUSH_TYPE($1); PASS_ID(); }
;

NAMESPACE_DEFINITION:
	NAMED_NAMESPACE_DEFINITION
|	UNNAMED_NAMESPACE_DEFINITION
;

NAMED_NAMESPACE_DEFINITION:
	ORIGINAL_NAMESPACE_DEFINITION
|	EXTENSION_NAMESPACE_DEFINITION
;

/*
 * TODO: Remember tests/tst4/k.C
 */
ORIGINAL_NAMESPACE_DEFINITION:
	T_NAMESPACE IDENTIFIER_C
	T_LBRACE			{ PUSH_TYPE(type_simple(void_t));
					  ENTER(namespace_c); }
	NAMESPACE_BODY T_RBRACE		{ LEAVE(); type_dispose($2); }
;

/*
 * TODO: We could allow NAMESPACE_NAME instead of
 * ORIGINAL_NAMESPACE_NAME here for some error resistence.
 */
EXTENSION_NAMESPACE_DEFINITION:
	T_NAMESPACE
	NESTED_ORIGINAL_NAMESPACE_NAME_SPECIFIER
	T_LBRACE			{ ENTER(namespace_c); }
	NAMESPACE_BODY T_RBRACE		{ LEAVE(); }
;

/*
 * namespace_c is used instead of none_c, because
 * it appears that in many cases the contents of an unnamed
 * namespace are still accessible after closing it. GCC kindof
 * merges it to the parent scope adding <unnamed>:: before the
 * identifiers.
 *
 * It also appears that there can only be one unnamed
 * namespace inside each scope (or there always is one). So
 * when entering an unnamed namespace the second time in the
 * same scope it is actually an extension namespace for the
 * first one, called <unnamed> (as in tests/tst4/b.C).
 *
 * TODO: The USING() must be executed at entering cause its
 * identifiers should be accessible as its parent's identifiers
 * from inside too (as in tests/tst4/q.C).
 */
UNNAMED_NAMESPACE_DEFINITION:
	T_NAMESPACE T_LBRACE		{ PUSH_ID(UNNAMED_ID);
					  PUSH_TYPE(type_simple(void_t));
					  $2 = ENTER(namespace_c);
					  PUSH_TYPE($2); }
	NAMESPACE_BODY T_RBRACE		{ LEAVE(); USING(); }
;

NAMESPACE_BODY:
	DECLARATION_SEQ_OPT
;

NAMESPACE_ALIAS:
	T_ALIAS_ID			{ PUSH_TYPE($1); PASS_ID(); }
;

NAMESPACE_ALIAS_DEFINITION:
	T_NAMESPACE IDENTIFIER_C T_EQ QUALIFIED_NAMESPACE_SPECIFIER
	T_SEMIC				{ POPFREE_ID();
					  type_dispose(DEFINE(link_c));
					  type_dispose($2); }
;

QUALIFIED_NAMESPACE_SPECIFIER:
	NESTED_ORIGINAL_NAMESPACE_NAME_SPECIFIER
|	NESTED_NAMESPACE_ALIAS_SPECIFIER
;

/*
 * Second rule removed because it was obsoleted by the first one.
 *
 * TODO: check what else can be imported with using.
 */
USING_DECLARATION:
	T_USING TYPENAME_OPT NESTED_TYPE_OR_NAME_SPECIFIER
	T_SEMIC				{ USING_ID($3); }
;

USING_DIRECTIVE:
	T_USING T_NAMESPACE QUALIFIED_NAMESPACE_SPECIFIER
	T_SEMIC				{ USING(); POPFREE_ID(); }
;

/*
 * No action.
 *
 * TODO: check what other modifiers or attributes or whatever
 * does GNU asm allow.
 */
ASM_DEFINITION:
	T_ASM T_LPAREN T_STRING_LITERAL ASM_EXTENSION_LIST_OPT
	T_RPAREN T_SEMIC
|	T_ASM T_VOLATILE T_LPAREN T_STRING_LITERAL
	ASM_EXTENSION_LIST_OPT T_RPAREN T_SEMIC
;

/*
 * See GCC's info pages for a (not very complete) description of
 * the syntax of extended asm.
 *
 * TODO: something is surely missing.
 */
ASM_EXTENSION_LIST_OPT:
	/* Empty */
|	ASM_EXTENSION_LIST_OPT T_COLON ASM_EXTENSION
|	ASM_EXTENSION_LIST_OPT T_COMMA ASM_EXTENSION
;

ASM_EXTENSION:
	/* Empty */
|	ASM_OPERAND_CONSTRAINT_STRING
|	ASM_OPERAND_CONSTRAINT_STRING ASM_OPERAND_EXPRESSION
|	ASM_OPERAND_SYMBOLIC ASM_OPERAND_CONSTRAINT_STRING
	ASM_OPERAND_EXPRESSION
;

ASM_OPERAND_CONSTRAINT_STRING:
	T_STRING_LITERAL STRING_LIST
;

/*
 * TODO: is it an expression or a declarator?
 */
ASM_OPERAND_EXPRESSION:
	T_LPAREN PM_EXPRESSION T_RPAREN	{ type_dispose($2); }
;

ASM_OPERAND_SYMBOLIC:
	T_LBRACK ID_EXPRESSION T_RBRACK	{ type_dispose($2); POPFREE_ID(); }
;

/*
 * Really, we only need to notify lexer about this because
 * other than the keyword names there should be no problem
 * parsing C as C++.
 *
 * On the other hand when ANSI old-style parameter lists
 * are supported the language (C/C++) information can be used
 * to disambiguate between declarators with parens and
 * constructors.
 *
 * There should be a stack of languages or they should be
 * somehow stored on the yacc's stack (inheriting attributes
 * of LANGUAGE_STRING) because nested LINKAGE_SPECIFICATIONs
 * are allowed. This is not very useful thou, so we just go
 * back to the file's language after leaving.
 *
 * TODO: add empty LINKAGE_SPECIFICATIONs for the unrecognized
 * language (``skip'') but then we need to keep track of the
 * count of braces and/or T_SEMICs.
 */
LINKAGE_SPECIFICATION: /* These don't define a scope */
	T_EXTERN LANGUAGE_STRING T_LBRACE
	DECLARATION_SEQ_OPT T_RBRACE	{ language_set_local(lang_global); }
|	T_EXTERN LANGUAGE_STRING
	DECLARATION			{ language_set_local(lang_global); }
;

/*
 * With the current lexer not caching strings, we have to be
 * sure that no lookahead is done after T_EXTERN followed by
 * T_STRING_LITERAL.
 */
LANGUAGE_STRING:
	T_STRING_LITERAL		{ language_set_local(
						language_from_name(
							last_string)); }
;

/* Declarators [gram.dcl.decl] */

COMMA_INIT_DECLARATOR_LIST_OPT:
	/* Empty */
|	COMMA_INIT_DECLARATOR_LIST_OPT T_COMMA INIT_DECLARATOR
;

INIT_DECLARATOR_LIST_OPT:
	/* Empty */
|	INIT_DECLARATOR_LIST
;

INIT_DECLARATOR_LIST:
	INIT_DECLARATOR
|	INIT_DECLARATOR_LIST T_COMMA INIT_DECLARATOR
;

/*
 * TODO: can something else than variable and a typedef be defined
 * in INIT_DECLARATOR?
 */
INIT_DECLARATOR:
	DECLARATOR INITIALIZER_OPT	{ DEFINE_VAR_OR_FUNC($1); }
;

NON_PAREN_INIT_DECLARATOR:
	NON_PAREN_DECLARATOR
	INITIALIZER_OPT			{ DEFINE_VAR_OR_FUNC($1); }
;

PAREN_NON_REDEF_INIT_DECLARATOR:
	PAREN_NON_REDEF_DECLARATOR
	INITIALIZER_OPT			{ DEFINE_VAR_OR_FUNC($1); }
;

/*
 * We put the bit-field declaration here for now but there may be
 * a better place for it. Moreover James A. Roskind says that the
 * symbol should be added to the symbol table before the bit-field
 * specification is actually read because it should be recognised
 * in a code like the following:
 *
 *		foo : sizeof(foo - 1);
 *
 * but neither gcc nor g++ parser accept this.
 *
 * We also have CTOR_INITIALIZER header here instead of in the
 * FUNCTION_DEFINITION to avoid conflicts with bit-fields.
 *
 * These changes partially syntactically forbid to define a bit-
 * field with a pointer type or a constructor returning a pointer
 * type, but this is alright in C++ because otherwise these would
 * cause a semantical error later. On the other hand they allow
 * some new incorrect definitions, but this is all Ok because it
 * can be weeded out semantically.
 */
DECLARATOR: /* TODO: conflict */
	DIRECT_DECLARATOR		{ $$ = $1; }
|	PTR_OPERATOR DECLARATOR		{ $$ = type_reference($2); }
|	DIRECT_DECLARATOR
	BIT_FIELD_DECLARATOR		{ $$ = $1; }
|	DIRECT_DECLARATOR
	CTOR_INITIALIZER		{ $$ = $1; }
;

/*
 * After a PTR_OPERATOR a redefinition is allowed because it doesn't
 * do harm. After a T_LPAREN likewise.
 */
NON_REDEF_DECLARATOR:
	DIRECT_NON_REDEF_DECLARATOR	{ $$ = $1; }
|	PTR_OPERATOR
	DECLARATOR			{ $$ = type_reference($2); }
|	DIRECT_NON_REDEF_DECLARATOR
	BIT_FIELD_DECLARATOR		{ $$ = $1; }
|	DIRECT_NON_REDEF_DECLARATOR
	CTOR_INITIALIZER		{ $$ = $1; }
;

/*
 * A declarator that doesn't start with a T_LPAREN.
 */
NON_PAREN_DECLARATOR:
	DIRECT_NON_PAREN_DECLARATOR	{ $$ = $1; }
|	PTR_OPERATOR DECLARATOR		{ $$ = type_reference($2); }
|	DIRECT_NON_PAREN_DECLARATOR
	BIT_FIELD_DECLARATOR		{ $$ = $1; }
|	DIRECT_NON_PAREN_DECLARATOR
	CTOR_INITIALIZER		{ $$ = $1; }
;

/*
 * A declarator that does start with a T_LPAREN.
 */
PAREN_NON_REDEF_DECLARATOR:
	DIRECT_PAREN_NON_REDEF_DECLARATOR
					{ $$ = $1; }
|	DIRECT_PAREN_NON_REDEF_DECLARATOR
	BIT_FIELD_DECLARATOR		{ $$ = $1; }
|	DIRECT_PAREN_NON_REDEF_DECLARATOR
	CTOR_INITIALIZER		{ $$ = $1; }
;

/*
 * A declarator that can be distinguished from a declaration
 * sequence by the first token.
 */
OBVIOUSLY_A_DECLARATOR:
	NON_REDEF_DECLARATOR		{ PUSH_TYPE($1); }
;

/*
 * TODO: should be CONSTANT_EXPRESSION as GCC info pages states.
 */
BIT_FIELD_DECLARATOR:
	T_COLON T_NUM_LITERAL
;

/*
 * In 2, 3, 4 and 5 we assume that the first token (DIRECT_DECLARATOR)
 * doesn't have the field "name" set to anything significant and we can
 * reuse this field. TODO: check if it is correct to do this. - Obsolete
 *
 * XXX: investigate why we can't have that type_dispose($3) there :-( -
 * Obsolete as well
 *
 * TODO: make a different ENTER() macro for this.
 *
 * TODO: Exceptions and stuff shall be outside params list.
 *
 * TODO: Add some stupid tip about params on DIRECT_DECLARATOR T_LPAREN
 * T_SPECIAL.
 */
DIRECT_DECLARATOR: /* TODO: CONFLICTZ !@@! */
	DECLARATOR_ID			{ $$ = $1; }
|	DIRECT_DECLARATOR_PARAMETRIZED_LEFT
	PARAMETER_DECLARATION_CLAUSE_OR_CONTRUCTOR_CALL
	T_RPAREN CV_QUALIFIER_SEQ_OPT
	EXCEPTION_SPECIFICATION_OPT	{ LEAVE();
					  $$ = TYPE_FN_OR_CTOR($1, $2);
					  SET_FSPEC($$); }
|	DIRECT_DECLARATOR T_FUNCTION CV_QUALIFIER_SEQ_OPT
	EXCEPTION_SPECIFICATION_OPT	{ $$ = type_parametrized($1, 0);
					  SET_FSPEC($$); }
|	DIRECT_DECLARATOR T_LBRACK CONSTANT_EXPRESSION_OPT
	T_RBRACK			{ $$ = type_reference($1);
					  type_dispose($3); }
|	DIRECT_DECLARATOR T_SUBSCRIPT	{ $$ = type_reference($1); }
|	T_LPAREN DECLARATOR T_RPAREN	{ $$ = $2; }
;

/*
 * We use non redefining declarators only to disambiguate
 * some conflictive places in the grammar, so it is safe
 * to allow redfinitions after a T_LPAREN.
 */
DIRECT_NON_REDEF_DECLARATOR:
	NON_REDEF_DECLARATOR_ID		{ $$ = $1; }
|	DIRECT_NON_REDEF_DECLARATOR_PARAMETRIZED_LEFT
	PARAMETER_DECLARATION_CLAUSE T_RPAREN CV_QUALIFIER_SEQ_OPT
	EXCEPTION_SPECIFICATION_OPT	{ LEAVE(); $$ = $1;
					  SET_FSPEC($$); }
|	DIRECT_NON_REDEF_DECLARATOR T_FUNCTION CV_QUALIFIER_SEQ_OPT
	EXCEPTION_SPECIFICATION_OPT	{ $$ = type_parametrized($1, 0);
					  SET_FSPEC($$); }
|	DIRECT_NON_REDEF_DECLARATOR T_LBRACK CONSTANT_EXPRESSION_OPT
	T_RBRACK			{ $$ = type_reference($1);
					  type_dispose($3); }
|	DIRECT_NON_REDEF_DECLARATOR
	T_SUBSCRIPT			{ $$ = type_reference($1); }
|	T_LPAREN DECLARATOR T_RPAREN	{ $$ = $2; }
;

DIRECT_NON_PAREN_DECLARATOR: 
	DECLARATOR_ID			{ $$ = $1; }
|	DIRECT_NON_PAREN_DECLARATOR_PARAMETRIZED_LEFT
	PARAMETER_DECLARATION_CLAUSE_OR_CONTRUCTOR_CALL
	T_RPAREN CV_QUALIFIER_SEQ_OPT
	EXCEPTION_SPECIFICATION_OPT	{ LEAVE();
					  $$ = TYPE_FN_OR_CTOR($1, $2);
					  SET_FSPEC($$); }
|	DIRECT_NON_PAREN_DECLARATOR T_FUNCTION CV_QUALIFIER_SEQ_OPT
	EXCEPTION_SPECIFICATION_OPT	{ $$ = type_parametrized($1, 0);
					  SET_FSPEC($$); }
|	DIRECT_NON_PAREN_DECLARATOR T_LBRACK CONSTANT_EXPRESSION_OPT
	T_RBRACK			{ $$ = type_reference($1);
					  type_dispose($3); }
|	DIRECT_NON_PAREN_DECLARATOR
	T_SUBSCRIPT			{ $$ = type_reference($1); }
;

DIRECT_PAREN_NON_REDEF_DECLARATOR:
	DIRECT_PAREN_NON_REDEF_DECLARATOR_PARAMETRIZED_LEFT
	PARAMETER_DECLARATION_CLAUSE_OR_CONTRUCTOR_CALL
	T_RPAREN CV_QUALIFIER_SEQ_OPT
	EXCEPTION_SPECIFICATION_OPT	{ LEAVE();
					  $$ = TYPE_FN_OR_CTOR($1, $2);
					  SET_FSPEC($$); }
|	DIRECT_PAREN_NON_REDEF_DECLARATOR T_FUNCTION CV_QUALIFIER_SEQ_OPT
	EXCEPTION_SPECIFICATION_OPT	{ $$ = type_parametrized($1, 0);
					  SET_FSPEC($$); }
|	DIRECT_PAREN_NON_REDEF_DECLARATOR T_LBRACK CONSTANT_EXPRESSION_OPT
	T_RBRACK			{ $$ = type_reference($1);
					  type_dispose($3); }
|	DIRECT_PAREN_NON_REDEF_DECLARATOR
	T_SUBSCRIPT			{ $$ = type_reference($1); }
|	PARAM_PAREN T_LPAREN NON_REDEF_DECLARATOR T_RPAREN
					{ $$ = $3;
					  type_dispose($1);
					  LEAVE(); }
;

DIRECT_DECLARATOR_PARAMETRIZED_LEFT:
	DIRECT_DECLARATOR T_LPAREN	{ $$ = type_parametrized($1,
							ENTER_PARAMS_AT($1)); }
;

DIRECT_NON_REDEF_DECLARATOR_PARAMETRIZED_LEFT:
	DIRECT_NON_REDEF_DECLARATOR
	T_LPAREN			{ $$ = type_parametrized($1,
							ENTER_PARAMS_AT($1)); }
;

DIRECT_NON_PAREN_DECLARATOR_PARAMETRIZED_LEFT:
	DIRECT_NON_PAREN_DECLARATOR
	T_LPAREN			{ $$ = type_parametrized($1,
							ENTER_PARAMS_AT($1)); }
;

DIRECT_PAREN_NON_REDEF_DECLARATOR_PARAMETRIZED_LEFT:
	DIRECT_PAREN_NON_REDEF_DECLARATOR
	T_LPAREN			{ $$ = type_parametrized($1,
							ENTER_PARAMS_AT($1)); }
;

/* TODO: store all the details in a list or a table */
PTR_OPERATOR:
	T_STAR CV_QUALIFIER_SEQ_OPT	{ is_const = 0; }
|	T_AND
|	NESTED_SCOPE_SPECIFIER T_STAR
	CV_QUALIFIER_SEQ_OPT		{ scope_stmt_reset(); is_const = 0; }
;

CV_QUALIFIER:
	T_CONST				{ is_const = 1; }
|	T_VOLATILE
|	T_OVERLOAD	/* ANSI */
;

/*
 * Left recursion saves some SR conflicts.
 *
 * CV_QUALIFIER_SEQ was merged into here.
 */
CV_QUALIFIER_SEQ_OPT:
	/* Empty */
|	CV_QUALIFIER_SEQ_OPT CV_QUALIFIER
;

/*
 * TODO: check what else can be redefined.
 */
DECLARATOR_ID:
	NESTED_TYPE_OR_NAME_SPECIFIER	{ $$ = $1; $$.ref_depth = 0; }
;

/*
 * Allowing nested names here adds several new conflict.
 */
NON_REDEF_DECLARATOR_ID:
	NESTED_NAME_SPECIFIER		{ $$ = $1; $$.ref_depth = 0; }
;

/*
 * For now we don't need to analyse TYPE_ID semantically and the
 * ABSTRACT stuff.
 * Later we could join all the DECLARATOR and ABSTRACT_DECLARATOR
 * stuffs together into ABSTRACT_OR_NOT_DECLARATOR, to avoid
 * many conflicts, e.g. those in PARAMETER_DECLARATION. on the other
 * hand it will be new conflicts, cause ABSTRACT_DECLARATOR can well
 * be empty. We would rather modify PARAMETER_DECLARATION somehow.
 */
TYPE_ID:
	TYPE_SPECIFIER_SEQ
	ABSTRACT_DECLARATOR_OPT		{ $$ = type_connect($1, $2); }
;

/*
 * In this case we don't need to use TYPE_SET() because there
 * are no new identifiers involved and there is only one
 * (or none) DECLARATOR and not a sequence of them. All the data
 * fits on the stack.
 */
TYPE_SPECIFIER_SEQ: /* TODO: Do we use the OPT? */
	TYPE_SPECIFIER
	TYPE_SPECIFIER_SEQ_OPT		{ $$ = type_connect($1, $2); }
;

TYPE_SPECIFIER_SEQ_OPT:
	/* Empty */			{ $$ = type_simple(void_t); }
|	TYPE_SPECIFIER_SEQ		{ $$ = $1; }
;

ABSTRACT_DECLARATOR: /* TODO: Do we need the non OPT? */
	PTR_OPERATOR
	ABSTRACT_DECLARATOR_OPT		{ $$ = type_reference($2); }
|	DIRECT_ABSTRACT_DECLARATOR	{ $$ = $1; }
;

ABSTRACT_DECLARATOR_OPT:
	/* Empty */			{ $$ = type_simple(void_t); }
|	ABSTRACT_DECLARATOR		{ $$ = $1; }
;

/*
 * TODO: start this from the beginning.
 */
DIRECT_ABSTRACT_DECLARATOR:
	DIRECT_ABSTRACT_DECLARATOR_PARAMETRIZED_LEFT
	PARAMETER_DECLARATION_CLAUSE T_RPAREN CV_QUALIFIER_SEQ_OPT
	EXCEPTION_SPECIFICATION_OPT	{ LEAVE(); $$ = $1;
					  SET_FSPEC($$); }
|	DIRECT_ABSTRACT_DECLARATOR_OPT
	T_FUNCTION
	CV_QUALIFIER_SEQ_OPT
	EXCEPTION_SPECIFICATION_OPT	{ $$ = type_parametrized($1, 0);
					  SET_FSPEC($$); }
|	DIRECT_ABSTRACT_DECLARATOR_OPT
	T_LBRACK			{ $1 = type_reference($1); }
	CONSTANT_EXPRESSION_OPT
	T_RBRACK			{ type_dispose($4); $$ = $1; }
|	DIRECT_ABSTRACT_DECLARATOR_OPT
	T_SUBSCRIPT			{ $$ = type_reference($1); }
|	T_LPAREN ABSTRACT_DECLARATOR
	T_RPAREN			{ $$ = $2; }
;

DIRECT_ABSTRACT_DECLARATOR_PARAMETRIZED_LEFT:
	DIRECT_ABSTRACT_DECLARATOR_OPT
	T_LPAREN			{ $$ = type_parametrized($1,
							ENTER_PARAMS()); }
;

DIRECT_ABSTRACT_DECLARATOR_OPT:
	/* Empty */			{ $$ = type_simple(void_t); }
|	DIRECT_ABSTRACT_DECLARATOR	{ $$ = $1; }
;

/*
 * The first production's parameter list style is C++ specific.
 */
PARAMETER_DECLARATION_CLAUSE:
	PARAMETER_DECLARATION_LIST_OPT ELIPSIS_OPT
|	PARAMETER_DECLARATION_LIST T_COMMA
	T_ELIPSIS			{ DEFINE_VA_LIST(); }
;

PARAMETER_DECLARATION_LIST:
	PARAMETER_DECLARATION
|	PARAMETER_DECLARATION_LIST T_COMMA PARAMETER_DECLARATION
;

PARAMETER_DECLARATION_LIST_OPT:
	/* Empty */
|	PARAMETER_DECLARATION_LIST
;

/*
 * When modifying PARAMETER_DECLARATION remember to apply
 * respective changes to TEMPLATE_PARAMETER_DECLARATION.
 *
 * TODO: Resolve the conflict by using a declarator that cannot
 * be a nested name, and possibly make it one with abstract
 * declarator.
 */
PARAMETER_DECLARATION:
	DECL_SPECIFIER_SEQ
	DECLARATOR			{ PUSH_TYPE(type_connect($2, $1));
					  type_dispose(DEFINE(variable_c)); }
|	DECL_SPECIFIER_SEQ
	DECLARATOR T_EQ
	ASSIGNMENT_EXPRESSION		{ PUSH_TYPE(type_connect($2, $1));
					  type_dispose(DEFINE(variable_c));
					  type_dispose($4); }
|	DECL_SPECIFIER_SEQ
	ABSTRACT_DECLARATOR_OPT		{ PUSH_TYPE(type_connect($2, $1));
					  PUSH_AUTO_NUM_ID();
					  type_dispose(DEFINE(variable_c)); }
|	DECL_SPECIFIER_SEQ
	ABSTRACT_DECLARATOR_OPT	T_EQ
	ASSIGNMENT_EXPRESSION		{ PUSH_TYPE(type_connect($2, $1));
					  PUSH_AUTO_NUM_ID();
					  type_dispose(DEFINE(variable_c));
					  type_dispose($4); }
;

/*
 * We use the .nested field to communicate to the declarator
 * if it is a function parameter clause or a call to constructor.
 * TODO: use a different method, a global variable or something.
 */
PARAMETER_DECLARATION_CLAUSE_OR_CONTRUCTOR_CALL:
	PARAMETER_DECLARATION_CLAUSE	{ $$.nested = 0; }
|	EXPRESSION_LIST			{ $$.nested = 1; }
;

/*
 * This is only reduced when we already know that the token after
 * the declaration specifier is going to be T_LBRACE, so we can execute
 * function specific actions.
 *
 * CTOR_INITIALIZER removed from here cause there's a separate
 * FUNCTION_DEFINITION for member functions now.
 *
 * If no type is given, a typedef name cannot be redefined as a
 * function.
 *
 * TODO: we could have some kind of DECLARATOR_DEFINE that
 * would do the define part at once. On the other hand it may
 * produce new conflicts, gotta check it first.
 *
 * TODO: don't use $2 after it has been disposed in type_connect() - Obsoleted
 * TODO: make this SANE - Holds
 *
 * TODO: add the params to the scope
 * TODO: do the second production
 */
FUNCTION_DEFINITION: /* TODO: add the ANSI C style params */
	DECL_SPECIFIER_SEQ_START NON_PAREN_MEMBER_FUNCTION_DEFINITION
					{ is_type_def = 0; }
|	DECL_SPECIFIER_SEQ_START PAREN_NON_REDEF_MEMBER_FUNCTION_DEFINITION
					{ is_type_def = 0; }
|	DECL_SPECIFIER_SEQ_START PARAMETER_LIST_MEMBER_FUNCTION_DEFINITION
					{ is_type_def = 0; }
|	OBVIOUSLY_A_DECLARATOR FUNCTION_BODY_LEFT FUNCTION_BODY_RIGHT
;

/*
 * This should be reduced immediately, because there is no other
 * production with DECL_SPECIFIER_SEQ DECLARATOR and T_LBRACE
 * (afaik) and so if the next token is an identifier it should
 * already be looked up in the children scope. Otherwise the
 * action would need to be in the above production.
 */
FUNCTION_BODY_LEFT:
	T_LBRACE			{ ENTER(function_c); code_scope = 1; }
;

FUNCTION_BODY_RIGHT:
	STATEMENT_SEQ_OPT T_RBRACE	{ LEAVE(); code_scope = 0; }
;

/* TODO: remove. */
FUNCTION_BODY: /* TODO: cut */
	COMPOUND_STATEMENT
;

/*
 * INITIALIZER was never used alone so now it is merged with
 * INITIALIZER_OPT.
 *
 * TODO: dispose() ?
 */
INITIALIZER_OPT:
	/* Empty */
|	T_EQ INITIALIZER_CLAUSE
|	T_LPAREN EXPRESSION_LIST T_RPAREN
;

/*
 * The COMMA_OPT has been moved to INITIALIZER_LIST.
 *
 * TODO: dispose() ?
 */
INITIALIZER_CLAUSE: /* These don't define a scope */
	ASSIGNMENT_EXPRESSION
|	T_LBRACE INITIALIZER_LIST T_RBRACE
;

/*
 * Made left side recursive and can be empty.
 * Initializer lists are often thousands elements long and
 * having INITIALIZER_LIST right recursive would mean putting
 * all of these elements on the stack.
 */
INITIALIZER_LIST:
	/* Empty */
|	INITIALIZER_LIST_LEFT
|	INITIALIZER_LIST_LEFT T_COMMA
;

INITIALIZER_LIST_LEFT:
	INITIALIZER_CLAUSE
|	INITIALIZER_LIST_LEFT T_COMMA INITIALIZER_CLAUSE
;

/* Classes [gram.class] */

/* TODO: eliminate TEMPLATE_NAME */
CLASS_NAME:
	T_CLASS_ID			{ PUSH_TYPE($1); PASS_ID(); }
|	TEMPLATE_ID
;

/*
 * Substitute for CLASS_SPECIFIER (after consuming the head!)
 *
 * TODO: it seems that anonymous classes cannot be derived (and
 * ofcourse nothing can be derived from them).
 */
CLASS_SPECIFIER_SHORT:
	BASE_CLAUSE_LEFT BASE_CLAUSE_RIGHT T_LBRACE
	CLASS_SPECIFIER_RIGHT		{ $$ = $1; }
|	CLASS_SPECIFIER_LEFT
	CLASS_SPECIFIER_RIGHT		{ $$ = $1; }
;

/*
 * ENTER the new context and define the class.
 *
 * Here it doesn't matter if we're inside a typedef construct
 * cause all classes are type names and the grammar takes care
 * of it (I hope!).
 */
CLASS_SPECIFIER_LEFT:
	T_LBRACE			{ $$ = type_copy(ENTER(class_c)); }
;

/*
 * The scope has already been taken care of and the left
 * brace has been parsed at this moment.
 */
CLASS_SPECIFIER_RIGHT:
	MEMBER_SPECIFICATION T_RBRACE	{ LEAVE(); }
;

/*
 * Class-key - also known as Aggregate-keys in ANSI publications.
 */
CLASS_KEY:
	T_CLASS				{ PUSH_TYPE(type_class(class_t)); }
|	T_STRUCT			{ PUSH_TYPE(type_class(struct_t)); }
|	T_UNION				{ PUSH_TYPE(type_class(union_t)); }
;

/*
 * The main body of the class.
 */
MEMBER_SPECIFICATION: /* TODO: consider access restrictions (future) */
	/* Empty */
|	MEMBER_SPECIFICATION MEMBER_DECLARATION
|	MEMBER_SPECIFICATION ACCESS_SPECIFIER T_COLON
;

/*
 * This has been inline expanded quite far to eliminate the
 * ambiguity connected with return-type-less member functions
 * (like contructors). It produces a big grammar but it
 * shouldn't slow down the parser. The conflict resolution here
 * is based on the GCC parser's behavior but is not at all
 * identical.
 * GCC parser introduces a special new token that is the name
 * of the parent class. It allows the parser to treat some
 * constructs either as declaration specifiers or declarators
 * depending on whether the type used is the current parent
 * class in particular or any other type name. This special
 * token is in some cases treated as a type name and in other
 * cases as an identifier. However it turns out that the use
 * of this token is not necesary to disambiguate the grammar
 * to the extent that G++ does in an LR(1) parser. In this
 * grammar we will treat the name of the current class just as
 * an ordinary type name.
 * The following table shows how G++ classifies some of the
 * declarations depending on the type name given and how this
 * grammar should classify them. "ok" means the parser simply
 * accepts the construct, "error" is a syntax error, "var" is
 * a member type, variable or function definition and "func" is
 * for a strictly function (i.e a constructor). I only listed
 * syntax errors, if a different error is reported, it is "ok".
 * The first column is when "t" is the current parent class,
 * second if "t" is any other type, third an identifier and
 * fourth is what cguess should do.
 *			class	type	id	cguess
 *
 *	t		ok	ok	var	ok
 *	t id		var	var	error	var
 *	t T		var	var	var	var
 *	t (x)		error	var	error	var
 *	t (T)		func	var	func	func
 *	t (int id)	func	error	func	func
 *	(t)		error	error	var	var
 *	(t) (x)		error	error	error	func
 *	(t) (T)		func	error	func	func
 *	(t) (int id)	func	error	func	func
 *
 * This shows that G++ parser reports syntax errors in some
 * cases where a constraint error should occur and the parser
 * should assume a redefinition. Cguess tries to allow this
 * kind of redefinitions. The only case where the existence
 * of this new token helps GCC more intelligently tell a
 * constructor from a member variable is "t (T)", but this
 * can be also done using further grammar expansion or inside
 * the semantic action without additional token types. We will
 * however always assume a constructor definition in this cases
 * because hardly any C++ program defines (redefines) class
 * fields in this way. This may be fixed in next versions.
 *
 * TODO: mangle IDs everywhere class name is used as an ID.
 */
MEMBER_DECLARATION:
	DECL_SPECIFIER_SEQ_START
	T_SEMIC				{ $$ = POP_TYPE();
					  GNU_ANONYMOUS_UNION($$);
					  is_type_def = 0; }
|	DECL_SPECIFIER_SEQ_START NON_PAREN_MEMBER_DECLARATOR
	MEMBER_DECLARATOR_LIST_OPT
	T_SEMIC				{ POPFREE_TYPE(); is_type_def = 0; }
|	DECL_SPECIFIER_SEQ_START NON_PAREN_MEMBER_FUNCTION_DEFINITION
					{ is_type_def = 0; }
|	DECL_SPECIFIER_SEQ_START PAREN_NON_REDEF_MEMBER_DECLARATOR
	MEMBER_DECLARATOR_LIST_OPT
	T_SEMIC				{ POPFREE_TYPE(); is_type_def = 0; }
|	DECL_SPECIFIER_SEQ_START PAREN_NON_REDEF_MEMBER_FUNCTION_DEFINITION
					{ is_type_def = 0; }
|	DECL_SPECIFIER_SEQ_START PARAMETER_LIST_MEMBER_DECLARATOR
	MEMBER_DECLARATOR_LIST_OPT
	T_SEMIC				{ POPFREE_TYPE(); is_type_def = 0; }
|	DECL_SPECIFIER_SEQ_START PARAMETER_LIST_MEMBER_FUNCTION_DEFINITION
					{ is_type_def = 0; }
|	OBVIOUSLY_A_DECLARATOR MEMBER_DECLARATOR_LIST_OPT
	T_SEMIC				{ DEFINE(variable_c); }
|	OBVIOUSLY_A_DECLARATOR FUNCTION_BODY_LEFT FUNCTION_BODY_RIGHT
|	USING_DECLARATION
|	MEMBER_TEMPLATE_DECLARATION
|	T_SEMIC
;

MEMBER_DECLARATOR_LIST_OPT:
	/* Empty */
|	MEMBER_DECLARATOR_LIST_OPT T_COMMA MEMBER_DECLARATOR
;

/*
 * This has been expanded enough to do no semantic actions before
 * the first parameter of the parameter list is shifted. This way we
 * defer the conflict between a member function definition and a
 * field declaration in parentheses until everything we need to know
 * is on the parser's stack and it can be easily decided. Consider
 * this two cases if you think the grammar for constructors is too
 * big:
 *
 *	class bar;
 *	class foo {
 *
 *		...
 *		foo (bar);		// Constructor
 *
 *		...
 *		foo (bar::*x)();	// Field
 *
 */
MEMBER_PARAMETER_LIST:
	PARAMETERS_LEFT T_RPAREN CV_QUALIFIER_SEQ_OPT
	EXCEPTION_SPECIFICATION_OPT
	CTOR_INITIALIZER_OPT		{ LEAVE(); $$ = $1;
					  SET_FSPEC($$); }
|	PARAMETERS_LEFT T_COMMA PARAMETER_DECLARATION_CLAUSE
	T_RPAREN CV_QUALIFIER_SEQ_OPT EXCEPTION_SPECIFICATION_OPT
	CTOR_INITIALIZER_OPT		{ LEAVE(); $$ = $1;
					  SET_FSPEC($$); }
|	T_FUNCTION CV_QUALIFIER_SEQ_OPT EXCEPTION_SPECIFICATION_OPT
	CTOR_INITIALIZER_OPT		{ $$ = TOP_TYPE();
					  $$ = type_parametrized($$, 0);
					  SET_FSPEC($$);
					  ID_FROM_TYPE(); ID_MANGLE(); }
;

PARAMETERS_LEFT:
	PARAM_PAREN T_LPAREN DECL_SPECIFIER_SEQ
	DECLARATOR			{ $$ = $1;
					  PUSH_TYPE(type_connect($4, $3));
					  type_dispose(DEFINE(variable_c));
					  ID_FROM_TYPE(); ID_MANGLE(); }
|	PARAM_PAREN T_LPAREN DECL_SPECIFIER_SEQ
	DECLARATOR T_EQ
	ASSIGNMENT_EXPRESSION		{ $$ = $1;
					  PUSH_TYPE(type_connect($4, $3));
					  type_dispose(DEFINE(variable_c));
					  type_dispose($6);
					  ID_FROM_TYPE(); ID_MANGLE(); }
|	PARAM_PAREN T_LPAREN DECL_SPECIFIER_SEQ
	ABSTRACT_DECLARATOR_OPT		{ $$ = $1;
					  ID_FROM_TYPE(); ID_MANGLE();
					  PUSH_TYPE(type_connect($4, $3));
					  PUSH_AUTO_NUM_ID();
					  type_dispose(DEFINE(variable_c)); }
|	PARAM_PAREN T_LPAREN DECL_SPECIFIER_SEQ
	ABSTRACT_DECLARATOR_OPT	T_EQ
	ASSIGNMENT_EXPRESSION		{ $$ = $1;
					  ID_FROM_TYPE(); ID_MANGLE();
					  PUSH_TYPE(type_connect($4, $3));
					  PUSH_AUTO_NUM_ID();
					  type_dispose(DEFINE(variable_c));
					  type_dispose($6); }
;

PARAM_PAREN:
					{ $$ = TOP_TYPE();
					  $$ = type_parametrized(
						$$, ENTER_PARAMS_AT($$)); }
;

/*
 * Bit fields removed from here and put into DECLARATOR together
 * with CTOR_INITIALIZERs to avoid the conflicts.
 */
MEMBER_DECLARATOR: /* Conflict between 1 & 2 but it's ok */
/*	DECLARATOR
	PURE_SPECIFIER_OPT		{ DEFINE_VAR_OR_FUNC($1); }
|*/	DECLARATOR
	CONSTANT_INITIALIZER_OPT	{ DEFINE_VAR_OR_FUNC($1); }
;

NON_PAREN_MEMBER_DECLARATOR:
	NON_PAREN_DECLARATOR
	CONSTANT_INITIALIZER_OPT	{ DEFINE_VAR_OR_FUNC($1); }
;

PAREN_NON_REDEF_MEMBER_DECLARATOR:
	PAREN_NON_REDEF_DECLARATOR
	CONSTANT_INITIALIZER_OPT	{ DEFINE_VAR_OR_FUNC($1); }
;

PARAMETER_LIST_MEMBER_DECLARATOR:
	MEMBER_PARAMETER_LIST		{ PUSH_TYPE(type_simple(void_t));
					  DEFINE_VAR_OR_FUNC($1); }
;

NON_PAREN_MEMBER_FUNCTION_DEFINITION:
	NON_PAREN_MEMBER_FUNCTION_DEFINITION_LEFT
	FUNCTION_BODY_LEFT FUNCTION_BODY_RIGHT
|	NON_PAREN_MEMBER_FUNCTION_DEFINITION_LEFT
	FUNCTION_TRY_BLOCK
;

NON_PAREN_MEMBER_FUNCTION_DEFINITION_LEFT:
	NON_PAREN_DECLARATOR		{ $1 = type_connect($1, POP_TYPE());
					  PUSH_TYPE($1); is_type_def = 0; }
;

PAREN_NON_REDEF_MEMBER_FUNCTION_DEFINITION:
	PAREN_NON_REDEF_MEMBER_FUNCTION_DEFINITION_LEFT
	FUNCTION_BODY_LEFT FUNCTION_BODY_RIGHT
|	PAREN_NON_REDEF_MEMBER_FUNCTION_DEFINITION_LEFT
	FUNCTION_TRY_BLOCK
;

PAREN_NON_REDEF_MEMBER_FUNCTION_DEFINITION_LEFT:
	PAREN_NON_REDEF_DECLARATOR	{ $1 = type_connect($1, POP_TYPE());
					  PUSH_TYPE($1); is_type_def = 0; }
;

PARAMETER_LIST_MEMBER_FUNCTION_DEFINITION:
	PARAMETER_LIST_MEMBER_FUNCTION_DEFINITION_LEFT
	FUNCTION_BODY_LEFT FUNCTION_BODY_RIGHT
;

PARAMETER_LIST_MEMBER_FUNCTION_DEFINITION_LEFT:
	MEMBER_PARAMETER_LIST		{ PUSH_TYPE($1); }
;

/*
 * TODO: Make the two into one, and make it a lexical rule
 *
 * But, but we don't actualy care cause CONSTANT_INITIALIZER
 * is equally Ok.
 */
/*
PURE_SPECIFIER:
	T_EQ * 0 * T_NUM_LITERAL
;

PURE_SPECIFIER_OPT:
	* Empty *
|	PURE_SPECIFIER
;
*/

/*
 * CONSTANT_INITIALIZER and CONSTANT_INITIALIZER_OPT are the same
 * symbol now.
 */
CONSTANT_INITIALIZER_OPT:
	/* Empty */
|	T_EQ CONSTANT_EXPRESSION
;

/* Derived Classes [gram.class.derived] */

/*
 * Enters the new scope, to place the base classes already
 * inside the scope.
 *
 * Here it doesn't matter if we're inside a typedef construct
 * cause all classes are type names and the grammar takes care
 * of it (I hope!).
 */
BASE_CLAUSE_LEFT:
	T_COLON				{ $$ = type_copy(ENTER(class_c)); }
;

BASE_CLAUSE_RIGHT:
	BASE_SPECIFIER_LIST
;

/*
 * Modified to be right side derivative.
 */
BASE_SPECIFIER_LIST:
	BASE_SPECIFIER
|	BASE_SPECIFIER T_COMMA BASE_SPECIFIER_LIST
;

/*
 * Inheritance is for now done using the same method that
 * "using namespace" construct, because in this application
 * the result is exactly the same - connecting two namespaces.
 *
 * Modified so that specifier is more easily digested by the parser.
 *
 * TODO: take access specifiers into account.
 */
BASE_SPECIFIER:
	NESTED_TYPE_NAME_SPECIFIER	{ POPFREE_ID(); USING(); }
|	T_VIRTUAL BASE_SPECIFIER
|	ACCESS_SPECIFIER BASE_SPECIFIER
;

ACCESS_SPECIFIER:
	T_PRIVATE
|	T_PROTECTED
|	T_PUBLIC
;

/* Special Member Functions [gram.special] */

CONVERSION_FUNCTION_ID:
	OPERATOR_SCOPE CONVERSION_TYPE_ID
;

/*
 * Conversion functions with normal TYPE_SPECIFIER_SEQ introduced
 * a lot of new conflicts because after reading:
 *
 *	T_OPERATOR CLASS_KEY CLASS_NAME T_LBRACE
 *
 * the parser couldn't know if the T_LBRACE was an opening of the
 * elaboration of the class or the start of the conversion operator
 * function. There could also be conflicts at T_COLON.
 *
 * James A. Roskind says: I had to disallow struct, union, or enum
 * elaborations during operator_function_name. The ANSI C++ Working
 * paper is vague about whether this should be part of the syntax,
 * or a constraint. The ambiguities that resulted were more than
 * LALR could handle, so the easiest fix was to be more specific.
 * This means that I had to in-line expand type_specifier_or_name
 * far enough that I would be able to exclude elaborations. [...]
 * Requiring and allowing '(' ')' around the `type' when the type
 * is complex would help a lot.
 *
 * CONVERSION_TYPE_ID is now a TYPE_NAME_SPECIFIER to resolve some
 * RR conflicts. However this way CONVERSION_DECLARATOR_OPT also
 * causes several SR conflicts but the default choice of yacc is
 * correct in this case. The conflict appears when "operator
 * sometype" is read and some asterisks follow. The asterisks can
 * be either a CONVERSION_DECLARATOR_OPT or a beginning of a
 * DECLARATOR. TODO
 *
 * We use scope_stmt_push() and scope_stmt_pop() to make the lexer
 * look up the conversion type in the global scope and not in the
 * statement scope, and to get back to the statement scope after
 * the lookup. TODO: this will fail when the conversion function
 * was previously declared as a template and is now defined as a
 * template but with different template parameter names. Use
 * the number of the parameter instead of name.
 */
CONVERSION_TYPE_ID:
	NON_ELABORATING_TYPE_SPECIFIER_SEQ
	CONVERSION_DECLARATOR_OPT	{ scope_stmt_pop();
					  $$ = scope_define_conversion(
						  	type_connect($1, $2));
					  PUSH_TYPE($$);
					  PUSH_OP_ID($$); }
;

NON_ELABORATING_TYPE_SPECIFIER_SEQ:
	NON_ELABORATING_TYPE_SPECIFIER	{ $$ = $1; }
;

NON_ELABORATING_TYPE_SPECIFIER:
	NESTED_TYPE_NAME_SPECIFIER	{ $$ = POP_TYPE(); POPFREE_ID(); }
|	NESTED_TYPE_NAME_SPECIFIER T_LANGLE TEMPLATE_ARGUMENT_LIST_OPT
	T_RANGLE			{ $$ = POP_TYPE(); POPFREE_ID(); }
|	SIMPLE_TYPE_SPECIFIER		{ $$ = $1; }
|	NE_CLASS_OR_ENUM_SPECIFIER	{ $$ = $1; POPFREE_ID(); }
;

/*
 * T_TYPENAME productions now obsoleted by new
 * NESTED_TYPE_NAME_SPECIFIER.
 */
NE_CLASS_OR_ENUM_SPECIFIER:
	CLASS_KEY
	NESTED_TYPE_NAME_SPECIFIER	{ $$ = POP_TYPE(); POPFREE_TYPE(); }
|	T_ENUM
	NESTED_TYPE_NAME_SPECIFIER	{ $$ = POP_TYPE(); }
;

/*
 * Contains CONVERSION_DECLARATOR too.
 */
CONVERSION_DECLARATOR_OPT:
	/* Empty */			{ $$ = type_simple(void_t); }
|	CONVERSION_DECLARATOR_OPT
	PTR_OPERATOR			{ $$ = type_reference($1); }
;

OPERATOR_SCOPE:
	T_OPERATOR			{ scope_stmt_push(); }
;

CTOR_INITIALIZER:
	T_COLON MEM_INITIALIZER_LIST
;

CTOR_INITIALIZER_OPT:
	/* Empty */
|	T_COLON MEM_INITIALIZER_LIST
;

/*
 * TODO: We could provide completion for these too (a separate idea)
 */
MEM_INITIALIZER_LIST:
	MEM_INITIALIZER
|	MEM_INITIALIZER T_COMMA MEM_INITIALIZER_LIST
;

MEM_INITIALIZER:
	MEM_INITIALIZER_ID T_LPAREN EXPRESSION_LIST_OPT T_RPAREN
|	MEM_INITIALIZER_ID T_FUNCTION
;

/* TODO: add the template argument list to CLASS_NAME or somewhere */
MEM_INITIALIZER_ID:
	NESTED_TYPE_OR_NAME_SPECIFIER	{ POPFREE_ID(); type_dispose($1); }
;

/* Overloading [gram.over] */

/*
 * TODO: these will be supported in far future.
 */
OPERATOR_FUNCTION_ID:
	OPERATOR_SCOPE OPERATOR_NAME	{ $$ = $2; PUSH_OP_ID($2); }
;

/*
 * GNU C++ minimum and maximum operators can also be
 * overloaded (tests/tst5/j.C).
 */
OPERATOR_NAME:
	T_NEW				{ $$ = TYPE_OP(operator_new); }
|	T_DELETE			{ $$ = TYPE_OP(operator_delete); }
|	NEW_ARRAY			{ $$ = TYPE_OP(operator_new_array); }
|	DELETE_ARRAY			{ $$ = TYPE_OP(
						operator_delete_array); }
|	T_PLUS				{ $$ = TYPE_OP(operator_plus); }
|	T_MINUS				{ $$ = TYPE_OP(operator_minus); }
|	T_STAR				{ $$ = TYPE_OP(operator_star); }
|	T_SLASH				{ $$ = TYPE_OP(operator_slash); }
|	T_PERCENT			{ $$ = TYPE_OP(operator_percent); }
|	T_HAT				{ $$ = TYPE_OP(operator_hat); }
|	T_AND				{ $$ = TYPE_OP(operator_and); }
|	T_OR				{ $$ = TYPE_OP(operator_or); }
|	T_TILDE				{ $$ = TYPE_OP(operator_tilde); }
|	T_NOT				{ $$ = TYPE_OP(operator_not); }
|	T_EQ				{ $$ = TYPE_OP(operator_eq); }
|	T_LANGLE			{ $$ = TYPE_OP(operator_langle); }
|	T_RANGLE			{ $$ = TYPE_OP(operator_rangle); }
|	T_PLUS_EQ			{ $$ = TYPE_OP(operator_plus_eq); }
|	T_MINUS_EQ			{ $$ = TYPE_OP(operator_minus_eq); }
|	T_STAR_EQ			{ $$ = TYPE_OP(operator_star_eq); }
|	T_SLASH_EQ			{ $$ = TYPE_OP(operator_slash_eq); }
|	T_PERCENT_EQ			{ $$ = TYPE_OP(operator_percent_eq); }
|	T_HAT_EQ			{ $$ = TYPE_OP(operator_hat_eq); }
|	T_AND_EQ			{ $$ = TYPE_OP(operator_and_eq); }
|	T_OR_EQ				{ $$ = TYPE_OP(operator_or_eq); }
|	T_LTLT				{ $$ = TYPE_OP(operator_ltlt); }
|	T_GTGT				{ $$ = TYPE_OP(operator_gtgt); }
|	T_GTGT_EQ			{ $$ = TYPE_OP(operator_gtgt_eq); }
|	T_LTLT_EQ			{ $$ = TYPE_OP(operator_ltlt_eq); }
|	T_EQEQ				{ $$ = TYPE_OP(operator_eqeq); }
|	T_NE				{ $$ = TYPE_OP(operator_ne); }
|	T_LE				{ $$ = TYPE_OP(operator_le); }
|	T_GE				{ $$ = TYPE_OP(operator_ge); }
|	T_ANDAND			{ $$ = TYPE_OP(operator_andand); }
|	T_OROR				{ $$ = TYPE_OP(operator_oror); }
|	T_INCR				{ $$ = TYPE_OP(operator_incr); }
|	T_DECR				{ $$ = TYPE_OP(operator_decr); }
|	T_COMMA				{ $$ = TYPE_OP(operator_comma); }
|	T_ARROW_STAR			{ $$ = TYPE_OP(operator_arrow_star); }
|	T_ARROW				{ $$ = TYPE_OP(operator_arrow); }
|	T_FUNCTION			{ $$ = TYPE_OP(operator_function); }
|	T_SUBSCRIPT			{ $$ = TYPE_OP(operator_subscript); }
|	T_MINIMUM			{ $$ = TYPE_OP(operator_minimum); }
|	T_MAXIMUM			{ $$ = TYPE_OP(operator_maximum); }
;

/* Templates [gram.temp] */

/*
 * EXPORT_OPT has been removed to avoid conflicts.
 *
 * TODO: the second production somehow introduces new conflict.
 * Check how.
 *
 * XXX: The last production was added to handle some declarations
 * that appear in STL headers and I wasn't sure what they do, but
 * they look safe to ignore here.
 */
TEMPLATE_DECLARATION:
	T_TEMPLATE TEMPLATE_PARAM_LEFT TEMPLATE_PARAMETER_LIST
	TEMPLATE_PARAM_RIGHT
	DECLARATION			{ scope_reset_template(); }
|	T_EXPORT T_TEMPLATE TEMPLATE_PARAM_LEFT TEMPLATE_PARAMETER_LIST
	TEMPLATE_PARAM_RIGHT
	DECLARATION			{ scope_reset_template(); }
|	T_EXTERN T_TEMPLATE DECL_SPECIFIER_SEQ
	T_SEMIC				{ type_dispose($3);
					  is_type_def = 0; }
|	T_EXTERN T_TEMPLATE DECL_SPECIFIER_SEQ DECLARATOR
	T_SEMIC				{ POPFREE_ID();
					  type_dispose($3); type_dispose($4);
					  is_type_def = 0; }
;

MEMBER_TEMPLATE_DECLARATION:
	T_TEMPLATE TEMPLATE_PARAM_LEFT TEMPLATE_PARAMETER_LIST
	TEMPLATE_PARAM_RIGHT
	MEMBER_DECLARATION		{ scope_reset_template(); }
|	T_EXPORT T_TEMPLATE TEMPLATE_PARAM_LEFT TEMPLATE_PARAMETER_LIST
	TEMPLATE_PARAM_RIGHT
	MEMBER_DECLARATION		{ scope_reset_template(); }
;

TEMPLATE_PARAM_LEFT:
	T_LANGLE			{ ENTER_PARAMS(); }
;

TEMPLATE_PARAM_RIGHT:
	T_RANGLE			{ scope_close_template(); }
;

TEMPLATE_PARAMETER_LIST:
	TEMPLATE_PARAMETER
|	TEMPLATE_PARAMETER_LIST T_COMMA TEMPLATE_PARAMETER
;

TEMPLATE_PARAMETER:
	TYPE_PARAMETER
|	TEMPLATE_PARAMETER_DECLARATION
;

TYPE_PARAMETER: /* TODO */ /* dispose */
	T_CLASS IDENTIFIER_OPT		{ PUSH_TYPE(type_class(class_t));
					  type_dispose(DEFINE(class_c)); }
|	T_CLASS IDENTIFIER_OPT T_EQ
	TYPE_ID				{ type_dispose($4);
					  PUSH_TYPE(type_class(class_t));
					  type_dispose(DEFINE(class_c)); }
|	T_TYPENAME
	IDENTIFIER_OPT 			{ PUSH_TYPE(type_simple(void_t));
					  type_dispose(DEFINE(class_c)); }
|	T_TYPENAME IDENTIFIER_OPT T_EQ
	TYPE_ID				{ type_dispose($4);
					  PUSH_TYPE(type_simple(void_t));
					  type_dispose(DEFINE(class_c)); }
|	T_TEMPLATE T_LANGLE TEMPLATE_PARAMETER_LIST T_RANGLE
	T_CLASS IDENTIFIER_OPT		{ POPFREE_ID(); }
|	T_TEMPLATE T_LANGLE TEMPLATE_PARAMETER_LIST T_RANGLE
	T_CLASS IDENTIFIER_OPT T_EQ
	ID_EXPRESSION			{ POPFREE_ID(); POPFREE_ID();
					  type_dispose($8); }
;

/* TODO: Some parts could be auto-completed too (separate idea) */
TEMPLATE_ID: /* TODO: Are both used? */
	TEMPLATE_NAME T_LANGLE TEMPLATE_ARGUMENT_LIST_OPT
	T_RANGLE
;

TEMPLATE_NAME:
	T_TEMPLATE_ID			{ PUSH_TYPE($1); PASS_ID(); }
;

TEMPLATE_ARGUMENT_LIST:
	TEMPLATE_ARGUMENT
|	TEMPLATE_ARGUMENT_LIST T_COMMA TEMPLATE_ARGUMENT
;

TEMPLATE_ARGUMENT_LIST_OPT:
	/* Empty */
|	TEMPLATE_ARGUMENT_LIST
;

/*
 * TODO: ASSIGNMENT_EXPRESSION here causes two reduce/reduce
 * conflicts for T_COLON and T_RANGLE, come up with something
 * better. For now we only allow SHIFT_EXPRESSION which is
 * one level below RELATIONAL_EXPRESSION and thus any T_COMMA
 * or T_RANGLE will be in parentheses, but SHIFT_EXPRESSION
 * doesn't allow some other operations that should be allowed,
 * we've gotta check how GCC handles this.
 *
 * Alternatively we could use %prec PREC for the T_COMMA in
 * TEMPLATE_ARGUMENT_LIST and T_RANGLE in TEMPLATE_ID and
 * others (there are several productions with T_LANGLE
 * TEMPLATE_ARGUMENT_LIST_OPT T_RANGLE sequence).
 */
TEMPLATE_ARGUMENT:
	SHIFT_EXPRESSION		{ type_dispose($1); }
|	TYPE_ID				{ type_dispose($1); }
;

EXPLICIT_INSTANTIATION:
	T_TEMPLATE DECLARATION
;

EXPLICIT_SPECIALIZATION:
	T_TEMPLATE TEMPLATE_PARAM_LEFT TEMPLATE_PARAM_RIGHT
	DECLARATION			{ scope_reset_template(); }
;

/*
 * Same as above
 */
TEMPLATE_PARAMETER_DECLARATION:
	TEMPLATE_DECL_SPECIFIER_SEQ
	DECLARATOR			{ PUSH_TYPE(type_connect($2, $1));
					  type_dispose(DEFINE(variable_c)); }
|	TEMPLATE_DECL_SPECIFIER_SEQ
	DECLARATOR T_EQ
	SHIFT_EXPRESSION		{ PUSH_TYPE(type_connect($2, $1));
					  type_dispose(DEFINE(variable_c));
					  type_dispose($4); }
|	TEMPLATE_DECL_SPECIFIER_SEQ
	ABSTRACT_DECLARATOR_OPT		{ PUSH_TYPE(type_connect($2, $1));
					  PUSH_AUTO_ID();
					  type_dispose(DEFINE(variable_c)); }
|	TEMPLATE_DECL_SPECIFIER_SEQ
	ABSTRACT_DECLARATOR_OPT	T_EQ
	SHIFT_EXPRESSION		{ PUSH_TYPE(type_connect($2, $1));
					  PUSH_AUTO_ID();
					  type_dispose(DEFINE(variable_c));
					  type_dispose($4); }
;

/*
 * Same as DECL_SPECIFIER_SEQ but doesn't allow T_TYPENAME as
 * the first token. Don't know what the specification says about
 * this but it seems to work.
 */
TEMPLATE_DECL_SPECIFIER_SEQ:
	T_FRIEND
	DECL_SPECIFIER_SEQ_RIGHT	{ $$ = $2; }
|	T_TYPEDEF
	DECL_SPECIFIER_SEQ_RIGHT	{ $$ = $2; is_type_def = 1; }
|	STORAGE_CLASS_SPECIFIER
	DECL_SPECIFIER_SEQ_RIGHT	{ $$ = $2; }
|	FUNCTION_SPECIFIER
	DECL_SPECIFIER_SEQ_RIGHT	{ $$ = $2; }
|	CV_QUALIFIER
	DECL_SPECIFIER_SEQ_RIGHT	{ $$ = $2; }
|	SIMPLE_TYPE_SPECIFIER
	STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_BIT_FLD_OR_SIMPLE_SPEC_LIST_OPT
					{ $$ = type_connect($1, $2);
					  SET_CV($$); }
|	STRICT_NAMED_TYPE_SPECIFIER
	STORAGE_CLASS_FUNCTION_FRIEND_TYPEDEF_OR_SIMPLE_SPEC_LIST_OPT
					{ $$ = type_connect($1, $2);
					  SET_CV($$); }
;

/* Exception Handling [gram.except] */

/*
 * unnamed_c are scopes that have no names, therefore
 * there's no way to refer to them from outside of the
 * block and therefore can be deleted after leaving.
 *
 * TODO:
 */
TRY_BLOCK:
	T_TRY				{ ENTER_ANONYMOUS(); }
	COMPOUND_STATEMENT		{ LEAVE(); }
	HANDLER_SEQ
;

/* TODO: check this dispose stuff */
FUNCTION_TRY_BLOCK:
	T_TRY				{ ENTER(function_c); }
	CTOR_INITIALIZER_OPT
	FUNCTION_BODY			{ LEAVE(); }
	HANDLER_SEQ
;

HANDLER_SEQ: /* TODO: Make the two into one, if one is used */
	HANDLER HANDLER_SEQ_OPT
;

HANDLER_SEQ_OPT:
	/* Empty */
|	HANDLER_SEQ
;

/*
 * TODO: add the exception identifiers to symbol table
 * like function parameters.
 */
HANDLER: /* TODO: add the exception identifiers to symbol table */
	T_CATCH T_LPAREN
	EXCEPTION_DECLARATION T_RPAREN	{ ENTER_ANONYMOUS(); }
	COMPOUND_STATEMENT		{ LEAVE(); }
;

EXCEPTION_DECLARATION:
	TYPE_SPECIFIER_SEQ DECLARATOR
|	TYPE_SPECIFIER_SEQ ABSTRACT_DECLARATOR
|	TYPE_SPECIFIER_SEQ T_ELIPSIS
;

THROW_EXPRESSION:
	T_THROW
	ASSIGNMENT_EXPRESSION_OPT	{ type_dispose($2); }
;

EXCEPTION_SPECIFICATION: /* TODO: both used? */
	T_THROW T_LPAREN TYPE_ID_LIST_OPT T_RPAREN
|	T_THROW T_FUNCTION
;

EXCEPTION_SPECIFICATION_OPT:
	/* Empty */
|	EXCEPTION_SPECIFICATION
;

TYPE_ID_LIST:
	TYPE_ID
|	TYPE_ID_LIST T_COMMA TYPE_ID
;

TYPE_ID_LIST_OPT:
	/* Empty */
|	TYPE_ID_LIST
;

/* Statements [gram.stmt.stmt] */ /* TODO: Move to top */

STATEMENT:
	LABELED_STATEMENT
|	EXPRESSION_STATEMENT
|	COMPOUND_STATEMENT
|	SELECTION_STATEMENT
|	ITERATION_STATEMENT
|	JUMP_STATEMENT
|	DECLARATION_STATEMENT
|	TRY_BLOCK
;

/*
 * This doesn't allow an empty labelled statement as the last
 * statement in the block. That's compatible with ISO but possibly
 * not with other C++ standards. For example, the following is
 * illegal:
 *		switch (0) {
 *			...
 *		default:
 *		}
 */
LABELED_STATEMENT: /* TODO: could be used for T_GOTO completion, some day */
	IDENTIFIER_C T_COLON STATEMENT	{ POPFREE_ID(); type_dispose($1); }
|	T_CASE CONSTANT_EXPRESSION T_COLON
	STATEMENT			{ type_dispose($2); }
|	T_DEFAULT T_COLON STATEMENT
;

EXPRESSION_STATEMENT:
	EXPRESSION_OPT T_SEMIC		{ type_dispose($1); }
;

COMPOUND_STATEMENT: /* TODO: put the tags here, except for functions */
	T_LBRACE STATEMENT_SEQ_OPT T_RBRACE
;

STATEMENT_SEQ: /* TODO: Will both be ever used? */
	STATEMENT
|	STATEMENT_SEQ STATEMENT
;

STATEMENT_SEQ_OPT:
	/* Empty */
|	STATEMENT_SEQ
;

SELECTION_STATEMENT: /* XXX: if-if-else conflict */
	T_IF T_LPAREN			{ ENTER_ANONYMOUS(); }
	CONDITION T_RPAREN		{ ENTER_ANONYMOUS(); }
	STATEMENT			{ LEAVE(); }
	SELECTION_STATEMENT_RIGHT	{ LEAVE(); }
|	T_SWITCH T_LPAREN		{ ENTER_ANONYMOUS(); }
	CONDITION T_RPAREN
	STATEMENT			{ LEAVE(); }
;

SELECTION_STATEMENT_RIGHT:
	T_ELSE				{ ENTER_ANONYMOUS(); }
	STATEMENT			{ LEAVE(); }
|	/* Empty */
;

CONDITION:
	EXPRESSION			{ type_dispose($1); }
|	CONDITION_DECLARATOR T_EQ
	ASSIGNMENT_EXPRESSION		{ type_dispose($3); }
;

/*
 * Adds the declared symbol to the tree at current depth.
 */
CONDITION_DECLARATOR:
	CONDITION_TYPE_SPECIFIER_SEQ
	DECLARATOR			{ DEFINE_VAR_OR_FUNC($2); }
;

CONDITION_TYPE_SPECIFIER_SEQ:
	TYPE_SPECIFIER_SEQ		{ PUSH_TYPE($1); }
;

CONDITION_OPT:
	/* Empty */
|	CONDITION
;

ITERATION_STATEMENT:
	T_WHILE T_LPAREN		{ ENTER_ANONYMOUS(); }
	CONDITION T_RPAREN
	STATEMENT			{ LEAVE(); }
|	T_DO				{ ENTER_ANONYMOUS(); }
	STATEMENT			{ LEAVE(); }
	T_WHILE T_LPAREN EXPRESSION T_RPAREN
	T_SEMIC				{ type_dispose($7); }
|	T_FOR T_LPAREN			{ ENTER_ANONYMOUS(); }
	FOR_INIT_STATEMENT CONDITION_OPT T_SEMIC EXPRESSION_OPT T_RPAREN
	STATEMENT			{ type_dispose($7); LEAVE(); }
;

/*
 * Changed to SIMPLE_DECLARATION_STATEMENT because declarations
 * without type are not allowed inside a FOR_INIT_STATEMENT in any
 * of the standards we are trying to support.
 */
FOR_INIT_STATEMENT:
	EXPRESSION_STATEMENT
|	SIMPLE_DECLARATION_STATEMENT
;

/* TODO: goto can be auto-completed too */
JUMP_STATEMENT:
	T_BREAK T_SEMIC
|	T_CONTINUE T_SEMIC
|	T_RETURN EXPRESSION_OPT T_SEMIC	{ type_dispose($2); }
|	T_GOTO IDENTIFIER_C T_SEMIC	{ POPFREE_ID(); type_dispose($2); }
;

DECLARATION_STATEMENT:
	BLOCK_DECLARATION_STATEMENT
;

/*
 * DECLARATION_STATEMENT produced a lot of statement and it is
 * inline expanded now, excluding SIMPLE_DECLARATION.
 */
BLOCK_DECLARATION_STATEMENT:
	SIMPLE_DECLARATION_STATEMENT
|	ASM_DEFINITION
|	NAMESPACE_ALIAS_DEFINITION
|	USING_DECLARATION
|	USING_DIRECTIVE
;

/*
 * The inline expanded version of SIMPLE_DECLARATION, with the
 * DECL_SPECIFIER_SEQ obligatory.
 */
SIMPLE_DECLARATION_STATEMENT:
	DECL_SPECIFIER_SEQ_START INIT_DECLARATOR_LIST_OPT
	T_SEMIC				{ is_type_def = 0; POPFREE_TYPE(); }
;

/* Expressions [gram.expr] */ /* TODO: Move to top */

/*
 * TODO: All expressions should be rewritten as four or five
 * non-terminals only, using bison's precedence keywords. GCC and
 * others have it done this way and it is way faster.
 */

PRIMARY_EXPRESSION:
	LITERAL				{ $$ = $1; }
|	T_THIS				{ $$ = TYPE_THIS(); }
|	T_LPAREN EXPRESSION T_RPAREN	{ $$ = $2; }
|	ID_EXPRESSION			{ $$ = $1; POPFREE_ID(); }
|	STATEMENT_EXPRESSION		{ $$ = $1; }
;

ID_EXPRESSION:
	NESTED_NAME_SPECIFIER		{ $$ = $1; }
;

/*
 * The last production has been removed cause CLASS_NAME can also
 * be a TEMPLATE_NAME, and it produced 49+ conflicts.
 */
UNQUALIFIED_ID: /* TODO: for 2 & 3 get the real type */
	IDENTIFIER_C			{ $$ = $1; }
|	IDENTIFIER_C T_LANGLE TEMPLATE_ARGUMENT_LIST_OPT
	T_RANGLE			{ $$ = $1; }
|	OPERATOR_FUNCTION_ID		{ $$ = $1; }
;

TEMPLATE_OPT:
	/* Empty */
|	T_TEMPLATE
;

NESTED_NAME_SPECIFIER:
	UNQUALIFIED_ID			{ $$ = $1;
					  $$.nested = 0; }
|	LOCAL_SCOPE_SEQ
	UNQUALIFIED_ID			{ $$ = $2;
					  $$.nested = 1; }
|	GLOBAL_SCOPE
	UNQUALIFIED_ID			{ $$ = $2;
					  $$.nested = 1; }
|	GLOBAL_SCOPE LOCAL_SCOPE_SEQ
	UNQUALIFIED_ID			{ $$ = $3;
					  $$.nested = 1; }
;

/*
 * Correct name lookup depends on immediate reduction of the
 * first T_SCOPE without look-ahead, otherwise it will have to
 * be done in the lexer. So make sure T_SCOPE is present only
 * in the rules for nested name specifiers. Alternatively the
 * action can be put before T_SCOPE, cause this is a LR(1)
 * grammar.
 *
 * Note that ANSI C++ Working Papers allow only the second/third
 * form of NESTED_NAME_SPECIFIER, but GCC recognises both without
 * warnings so we try do the same.
 */
NESTED_SCOPE_SPECIFIER:
	LOCAL_SCOPE_SEQ
|	GLOBAL_SCOPE
|	GLOBAL_SCOPE LOCAL_SCOPE_SEQ
;

/*
 * This could be limited to a (possibly empty) sequence of
 * namespace names followed by a (possibly empty) sequence
 * of class names because a namespace cannot be a member of
 * a class.
 */
LOCAL_SCOPE_SEQ:
	LOCAL_SCOPE
|	LOCAL_SCOPE_SEQ LOCAL_SCOPE
|	LOCAL_SCOPE_SEQ T_TEMPLATE LOCAL_SCOPE
|	LOCAL_SCOPE_SEQ T_SPECIAL	{ scope_stmt_lookup_info(); YYACCEPT; }
;

NESTED_TYPE_OR_NAME_SPECIFIER:
	UNQUALIFIED_ID			{ $$ = $1; ID_CLASS(variable_c); }
|	NESTED_SCOPE_SPECIFIER
	UNQUALIFIED_ID			{ $$ = $2; $$.nested = 1;
					  ID_CLASS(variable_c); }
|	TYPE_NAME			{ $$ = POP_TYPE(); $$.nested = 1;
					  ID_CLASS(typename_c); }
|	LOCAL_SCOPE_SEQ TYPE_NAME	{ $$ = POP_TYPE(); $$.nested = 1;
					  ID_CLASS(typename_c); }
|	GLOBAL_SCOPE TYPE_NAME		{ $$ = POP_TYPE(); $$.nested = 1;
					  ID_CLASS(typename_c); }
|	GLOBAL_SCOPE LOCAL_SCOPE_SEQ
	TYPE_NAME			{ $$ = POP_TYPE(); $$.nested = 1;
					  ID_CLASS(typename_c); }
|	GLOBAL_SCOPE T_SPECIAL		{ scope_stmt_lookup_info(); YYACCEPT; }
;

/*
 * We include both constructors and destructors as well as
 * conversion functions here as a method of disambiguating
 * the grammar for functions that require no return type.
 * Note that the ambiguity only affects scoped names. If a
 * declaration starts with a new identifier there's no
 * doubt whatsoever. Also there would be no problem with
 * constructors and destructors if they didn't allow
 * function specifiers before them. The conflict appears
 * when there's a function specifier (that forces non-empty
 * declaration specifier) followed by a typename. The parser
 * cannot know if it should reduce the declaration specifier
 * at this moment. The solution could be taking function
 * specifiers outside of declaration specifiers or deferring
 * any semantic actions until the ambiguity is resolved.
 * Any of these solutions will be better then the current
 * one, so this should change in the future.
 *
 * TODO: On T_TILDE communicate to scope.c that the next
 * lookup should be a destructor (for scoped IDs).
 */
NESTED_TYPE_NAME_SPECIFIER:
	TYPE_NAME			{ $$.nested = 0; }
|	LOCAL_SCOPE_SEQ TYPE_NAME	{ $$.nested = 1; }
|	GLOBAL_SCOPE TYPE_NAME		{ $$.nested = 1; }
|	GLOBAL_SCOPE LOCAL_SCOPE_SEQ
	TYPE_NAME			{ $$.nested = 1; }
|	GLOBAL_SCOPE T_SPECIAL		{ scope_stmt_lookup_info(); YYACCEPT; }
|	T_TYPENAME/*TODO*/
	NESTED_NAME_SPECIFIER		{ $$ = $1; PUSH_TYPE($1); }
|	T_TYPENAME TYPE_NAME		{ $$.nested = 0; }
|	T_TYPENAME LOCAL_SCOPE_SEQ
	TYPE_NAME			{ $$.nested = 1; }
|	CONVERSION_FUNCTION_ID		{ $$.nested = 0; }
|	LOCAL_SCOPE_SEQ
	CONVERSION_FUNCTION_ID		{ $$.nested = 1; }
|	GLOBAL_SCOPE
	CONVERSION_FUNCTION_ID		{ $$.nested = 1; }
|	GLOBAL_SCOPE LOCAL_SCOPE_SEQ
	CONVERSION_FUNCTION_ID		{ $$.nested = 1; }
|	T_TILDE CLASS_NAME		{ $$.nested = 0; is_destructor = 1; }
|	LOCAL_SCOPE_SEQ
	T_TILDE CLASS_NAME		{ $$.nested = 1; }
|	GLOBAL_SCOPE
	T_TILDE CLASS_NAME		{ $$.nested = 1; }
|	GLOBAL_SCOPE LOCAL_SCOPE_SEQ
	T_TILDE CLASS_NAME		{ $$.nested = 1; }
;

STRICT_NESTED_TYPE_NAME_SPECIFIER:
	TYPE_NAME			{ $$.nested = 0; }
|	LOCAL_SCOPE_SEQ TYPE_NAME	{ $$.nested = 1; }
|	GLOBAL_SCOPE TYPE_NAME		{ $$.nested = 1; }
|	GLOBAL_SCOPE LOCAL_SCOPE_SEQ
	TYPE_NAME			{ $$.nested = 1; }
|	GLOBAL_SCOPE T_SPECIAL		{ scope_stmt_lookup_info(); YYACCEPT; }
;

/*
 * Correct name lookup depends on immediate reduction of the
 * first T_SCOPE without look-ahead, otherwise it will have to
 * be done in the lexer. So make sure T_SCOPE is present only
 * in the rules for nested name specifiers. Alternatively the
 * action can be put before T_SCOPE, cause this is a LR(1)
 * grammar.
 */
NESTED_ORIGINAL_NAMESPACE_NAME_SPECIFIER:
	NESTED_ORIGINAL_NAMESPACE_NAME_SPECIFIER_LOCAL
					{ $$ = $1; }
|	GLOBAL_SCOPE
	NESTED_ORIGINAL_NAMESPACE_NAME_SPECIFIER_LOCAL
					{ $$ = $2; $$.nested = 1; }
|	GLOBAL_SCOPE T_SPECIAL		{ scope_stmt_lookup_info(); YYACCEPT; }
;

/*
 * This could be limited to a (possibly empty) sequence of
 * namespace names followed by a (possibly empty) sequence
 * of class names because a namespace cannot be a member of
 * a class.
 */
NESTED_ORIGINAL_NAMESPACE_NAME_SPECIFIER_LOCAL:
	ORIGINAL_NAMESPACE_NAME
|	LOCAL_SCOPE
	NESTED_ORIGINAL_NAMESPACE_NAME_SPECIFIER_LOCAL
					{ $$ = $2; $$.nested = 1; }
|	LOCAL_SCOPE T_SPECIAL		{ scope_stmt_lookup_info(); YYACCEPT; }
;

/*
 * Correct name lookup depends on immediate reduction of the
 * first T_SCOPE without look-ahead, otherwise it will have to
 * be done in the lexer. So make sure T_SCOPE is present only
 * in the rules for nested name specifiers. Alternatively the
 * action can be put before T_SCOPE, cause this is a LR(1)
 * grammar.
 */
NESTED_NAMESPACE_ALIAS_SPECIFIER:
	NESTED_NAMESPACE_ALIAS_SPECIFIER_LOCAL
					{ $$ = $1; }
|	GLOBAL_SCOPE
	NESTED_NAMESPACE_ALIAS_SPECIFIER_LOCAL
					{ $$ = $2; $$.nested = 1; }
;

/*
 * This could be limited to a (possibly empty) sequence of
 * namespace names followed by a (possibly empty) sequence
 * of class names because a namespace cannot be a member of
 * a class.
 */
NESTED_NAMESPACE_ALIAS_SPECIFIER_LOCAL:
	NAMESPACE_ALIAS
|	LOCAL_SCOPE
	NESTED_NAMESPACE_ALIAS_SPECIFIER_LOCAL
					{ $$ = $2; $$.nested = 1; }
;

GLOBAL_SCOPE:
	T_SCOPE				{ scope_stmt_global(); }
;

/*
 * There must be separate rules for CLASS_NAME and for NAMESPACE_NAME
 * because otherwise some strange conflicts appear and parser fails
 * on very basic programs.
 *
 * We can be sure that in case of a conflict between shifting the
 * T_SCOPE and reducing the nested name and starting a new one (like
 * in case of DECL_SPECIFIER_SEQ DECLARATOR) with global scope, the
 * former will be chosen because shifting always gets higher
 * precedence than reduction.
 *
 * TODO: remove the first two alternatives.
 */
LOCAL_SCOPE:
	TYPEDEF_NAME T_SCOPE		{ scope_stmt_enter(POP_TYPE());
					  POPFREE_ID(); }
|	TYPEDEF_NAME T_LANGLE TEMPLATE_ARGUMENT_LIST_OPT T_RANGLE
	T_SCOPE				{ scope_stmt_enter(POP_TYPE());
					  POPFREE_ID(); }
|	CLASS_NAME T_SCOPE		{ scope_stmt_enter(POP_TYPE());
					  POPFREE_ID(); }
|	CLASS_NAME T_LANGLE TEMPLATE_ARGUMENT_LIST_OPT T_RANGLE
	T_SCOPE				{ scope_stmt_enter(POP_TYPE());
					  POPFREE_ID(); }
|	T_TEMPLATE IDENTIFIER_C T_LANGLE TEMPLATE_ARGUMENT_LIST_OPT
	T_RANGLE T_SCOPE		{ scope_stmt_enter($2);
					  POPFREE_ID(); }
|	NAMESPACE_NAME T_SCOPE		{ scope_stmt_enter(POP_TYPE());
					  POPFREE_ID(); }
;

/*
 * Postfix expressions.
 *
 * The T_TYPENAME NESTED_NAME_SPECIFIER T_TEMPLATE TEMPLATE_ID T_LPAREN
 * EXPRESSION_LIST_OPT T_RPAREN productions have been removed because
 * they are now obsoleted by the previous one.
 */
/* TODO: remove the TYPE_GET() stuff. */
POSTFIX_EXPRESSION: /* TODO: conflicts */
	PRIMARY_EXPRESSION		{ $$ = $1; }
|	POSTFIX_EXPRESSION T_LBRACK EXPRESSION
	T_RBRACK			{ $$ = type_dereference($1);
					  type_dispose($3); }
|	POSTFIX_EXPRESSION T_LPAREN EXPRESSION_LIST_OPT
	T_RPAREN			{ $$ = type_return($1);
					  type_dispose($3); }
|	POSTFIX_EXPRESSION T_LPAREN
	T_SPECIAL			{ scope_function_info($1); YYACCEPT; }
|	POSTFIX_EXPRESSION T_FUNCTION	{ $$ = type_return($1); }
|	SIMPLE_TYPE_SPECIFIER T_LPAREN EXPRESSION_LIST_OPT
	T_RPAREN			{ $$ = $1; type_dispose($3); }
|	SIMPLE_TYPE_SPECIFIER
	T_FUNCTION			{ $$ = $1; }
|	NESTED_TYPE_NAME_SPECIFIER
	T_LPAREN EXPRESSION_LIST_OPT
	T_RPAREN			{ type_dispose($3);
					  $$ = POP_TYPE(); POPFREE_ID(); }
|	NESTED_TYPE_NAME_SPECIFIER
	T_FUNCTION			{ $$ = $1;
					  $$ = POP_TYPE(); POPFREE_ID(); }
/* TODO: for the last 8 get the type of the (possibly) overloaded operator */
|	POSTFIX_EXPRESSION T_DOT TEMPLATE_OPT
	UNQUALIFIED_ID			{ $$ = TYPE_LOOKUP($1); }
|	POSTFIX_EXPRESSION T_ARROW TEMPLATE_OPT
	UNQUALIFIED_ID			{ $$ = TYPE_LOOKUP($1); }
/* TODO: for the last 2 get the type of the (possibly) overloaded operator */
|	POSTFIX_EXPRESSION T_DOT
	T_SPECIAL			{ scope_lookup_info($1); YYACCEPT; }
|	POSTFIX_EXPRESSION T_ARROW
	T_SPECIAL			{ scope_lookup_info($1); YYACCEPT; }
|	POSTFIX_EXPRESSION T_DOT
	PSEUDO_DESTRUCTOR_NAME		{ $$ = type_simple(void_t);
					  type_dispose($1); }
|	POSTFIX_EXPRESSION T_ARROW
	PSEUDO_DESTRUCTOR_NAME		{ $$ = type_simple(void_t);
					  type_dispose($1); }
/* TODO: for the last two return the real prototypes */
|	POSTFIX_EXPRESSION T_INCR	{ $$ = $1; }
|	POSTFIX_EXPRESSION T_DECR	{ $$ = $1; }
/* TODO: for the last 2 get the type of the (possibly) overloaded operator */
|	T_DYNAMIC_CAST T_LANGLE TYPE_ID T_RANGLE T_LPAREN EXPRESSION
	T_RPAREN			{ $$ = $3; type_dispose($6); }
|	T_STATIC_CAST T_LANGLE TYPE_ID T_RANGLE T_LPAREN EXPRESSION
	T_RPAREN			{ $$ = $3; type_dispose($6); }
|	T_REINTERPRET_CAST T_LANGLE TYPE_ID T_RANGLE
	T_LPAREN EXPRESSION T_RPAREN	{ $$ = $3; type_dispose($6); }
|	T_CONST_CAST T_LANGLE TYPE_ID T_RANGLE T_LPAREN EXPRESSION
	T_RPAREN			{ $$ = $3; type_dispose($6); }
|	T_DYNAMIC_CAST T_LE TYPE_ID T_RANGLE T_LPAREN EXPRESSION
	T_RPAREN			{ $$ = $3; type_dispose($6); }
|	T_STATIC_CAST T_LE TYPE_ID T_RANGLE T_LPAREN EXPRESSION
	T_RPAREN			{ $$ = $3; type_dispose($6); }
|	T_REINTERPRET_CAST T_LE TYPE_ID T_RANGLE
	T_LPAREN EXPRESSION T_RPAREN	{ $$ = $3; type_dispose($6); }
|	T_CONST_CAST T_LE TYPE_ID T_RANGLE T_LPAREN EXPRESSION
	T_RPAREN			{ $$ = $3; type_dispose($6); }
|	T_TYPEID T_LPAREN EXPRESSION
	T_RPAREN			{ $$ = $1; type_dispose($3); }
|	T_TYPEID T_LPAREN TYPE_ID
	T_RPAREN			{ $$ = $1; type_dispose($3); }
/* Last two have conflicts with ABSTRACT_DECLARATORS but I doubt
 * we can do much about. */
;

/* TODO: check if any production uses these $$ values actually */
EXPRESSION_LIST:
	ASSIGNMENT_EXPRESSION		{ $$ = $1; }
|	EXPRESSION_LIST T_COMMA
	ASSIGNMENT_EXPRESSION		{ $$ = $3; type_dispose($1); }
;

EXPRESSION_LIST_OPT:
	/* Empty */			{ $$ = type_simple(void_t); }
|	EXPRESSION_LIST			{ $$ = $1; }
;

PSEUDO_DESTRUCTOR_NAME:
	T_TILDE CLASS_NAME		{ POPFREE_TYPE(); POPFREE_ID(); }
|	LOCAL_SCOPE_SEQ T_TILDE
	CLASS_NAME			{ POPFREE_TYPE(); POPFREE_ID(); }
;

UNARY_EXPRESSION: /* TODO: optimize */
	POSTFIX_EXPRESSION		{ $$ = $1; }
|	T_INCR CAST_EXPRESSION		{ $$ = $2; }
|	T_DECR CAST_EXPRESSION		{ $$ = $2; }
|	UNARY_OPERATOR CAST_EXPRESSION	{ $$ = type_connect($1, $2); }
|	T_SIZEOF UNARY_EXPRESSION	{ $$ = type_simple(int_t);
					  type_dispose($2); }
|	T_SIZEOF T_LPAREN TYPE_ID
	T_RPAREN			{ $$ = type_simple(int_t);
					  type_dispose($3); }
|	NEW_EXPRESSION			{ $$ = $1; }
|	DELETE_EXPRESSION		{ $$ = type_simple(void_t); }
;

/* TODO: check if they haven't been overloaded */
UNARY_OPERATOR:
	T_STAR				{ $$ = type_simple(void_t);
					  $$ = type_dereference($$); }
|	T_AND				{ $$ = type_simple(void_t);
					  $$ = type_reference($$); }
|	T_PLUS				{ $$ = type_simple(void_t); }
|	T_MINUS				{ $$ = type_simple(void_t); }
|	T_NOT				{ $$ = type_simple(void_t); }
|	T_TILDE				{ $$ = type_simple(void_t); }
;

/*
 * TODO: SCOPT_OPT has been removed, check what are the consequences
 */
NEW_EXPRESSION:
	T_NEW NEW_PLACEMENT_OPT NEW_TYPE_ID
	NEW_INITIALIZER_OPT		{ $$ = $3; }
|	T_NEW NEW_PLACEMENT_OPT T_LPAREN TYPE_ID
	T_RPAREN NEW_INITIALIZER_OPT	{ $$ = $4; }
;

NEW_PLACEMENT: /* TODO: Make the two into one */
	T_LPAREN EXPRESSION_LIST
	T_RPAREN			{ type_dispose($2); }
;

NEW_PLACEMENT_OPT:
	/* Empty */
|	NEW_PLACEMENT
;

/*
 * We don't allow elaborating type specifiers here either
 * because they caused a RR conflict at T_COLON. After reading:
 *
 *	EXPRESSION T_QUESTION T_NEW T_STRUCT T_IDENTIFIER T_COLON
 *
 * the parser couldn't know whether the T_COLON was a start of
 * a base clause of a definition of the new struct or if it
 * should already reduce the T_NEW T_STRUCT T_IDENTIFIER sequence
 * as a NEW_EXPRESSION and the T_COLON was a part the trinary
 * operator.
 *
 * TODO: Connect those with the DECLARATOR and ABSTRACT_DECLARATOR stuff
 */
NEW_TYPE_ID:
	NON_ELABORATING_TYPE_SPECIFIER_SEQ
	NEW_DECLARATOR_OPT		{ $$ = type_connect($1, $2); }
;

NEW_DECLARATOR:
	PTR_OPERATOR NEW_DECLARATOR_OPT /* OPT? */
					{ $$ = type_reference($2); }
|	DIRECT_NEW_DECLARATOR		{ $$ = $1; }
;

NEW_DECLARATOR_OPT:
	/* Empty */			{ $$ = type_simple(void_t); }
|	NEW_DECLARATOR			{ $$ = $1; }
;

DIRECT_NEW_DECLARATOR:
	T_LBRACK EXPRESSION T_RBRACK	{ $$ = type_simple(void_t);
					  $$ = type_reference($$);
					  type_dispose($2); }
|	DIRECT_NEW_DECLARATOR T_LBRACK CONSTANT_EXPRESSION
	T_RBRACK			{ $$ = type_reference($1);
					  type_dispose($3); }
;

NEW_INITIALIZER:
	T_LPAREN EXPRESSION_LIST_OPT
	T_RPAREN			{ type_dispose($2); }
|	T_FUNCTION
;

NEW_INITIALIZER_OPT:
	/* Empty */
|	NEW_INITIALIZER
;

/*
 * TODO: SCOPT_OPT has been removed, check what are the consequences
 */
DELETE_EXPRESSION:
	T_DELETE CAST_EXPRESSION	{ type_dispose($2); }
|	DELETE_ARRAY CAST_EXPRESSION	{ type_dispose($2); }
;

CAST_EXPRESSION:
	UNARY_EXPRESSION		{ $$ = $1; }
|	T_LPAREN TYPE_ID T_RPAREN
	CAST_EXPRESSION			{ $$ = $2;
					  type_dispose($4); }
;

PM_EXPRESSION: /* TODO: these will be supported in far future */
	CAST_EXPRESSION			{ $$ = $1; }
|	PM_EXPRESSION T_DOTSTAR
	CAST_EXPRESSION			{ $$ = $1;
					  type_dispose($3); }
|	PM_EXPRESSION T_ARROW_STAR
	CAST_EXPRESSION			{ $$ = $1;
					  type_dispose($3); }
;

/*
 * TODO: check if the operators have been overloaded
 *
 * TODO: as long as we don't care about precedence we can
 * put several of these productions into one and it would speed
 * the parser up a little.
 *
 * TODO: we could have #defines for the actions
 *
 * TODO: make it all smarter
 */
MULTIPLICATIVE_EXPRESSION:
	PM_EXPRESSION			{ $$ = $1; }
|	MULTIPLICATIVE_EXPRESSION T_STAR
	PM_EXPRESSION			{ $$ = type_connect($1, $3); }
|	MULTIPLICATIVE_EXPRESSION T_SLASH
	PM_EXPRESSION			{ $$ = type_connect($1, $3); }
|	MULTIPLICATIVE_EXPRESSION T_PERCENT
	PM_EXPRESSION			{ $$ = type_connect($1, $3); }
;

ADDITIVE_EXPRESSION:
	MULTIPLICATIVE_EXPRESSION	{ $$ = $1; }
|	ADDITIVE_EXPRESSION T_PLUS
	MULTIPLICATIVE_EXPRESSION	{ $$ = type_connect($1, $3); }
|	ADDITIVE_EXPRESSION T_MINUS
	MULTIPLICATIVE_EXPRESSION	{ $$ = type_connect($1, $3); }
;

SHIFT_EXPRESSION:
	ADDITIVE_EXPRESSION		{ $$ = $1; }
|	SHIFT_EXPRESSION T_LTLT
	ADDITIVE_EXPRESSION		{ $$ = $1;
					  type_dispose($3); }
|	SHIFT_EXPRESSION T_GTGT
	ADDITIVE_EXPRESSION		{ $$ = $1;
					  type_dispose($3); }
;

/*
 * RELATIONAL_EXPRESSIONs with T_LANGLE and T_RANGLE were very
 * difficult to distinguish from template argument lists and were
 * cause of several ambiguities in the grammar. Now the disambiguation
 * is done inside the lexer which passes all the T_LANGLEs and
 * T_RANGLEs that are operators as T_LE or T_GE to the parser.
 */
RELATIONAL_EXPRESSION:
	SHIFT_EXPRESSION		{ $$ = $1; }
|	RELATIONAL_EXPRESSION T_RANGLE
	SHIFT_EXPRESSION		{ $$ = type_simple(bool_t);
					  type_dispose($1); type_dispose($3); }
|	RELATIONAL_EXPRESSION T_LE
	SHIFT_EXPRESSION		{ $$ = type_simple(bool_t);
					  type_dispose($1); type_dispose($3); }
|	RELATIONAL_EXPRESSION T_GE
	SHIFT_EXPRESSION		{ $$ = type_simple(bool_t);
					  type_dispose($1); type_dispose($3); }
|	RELATIONAL_EXPRESSION T_MINIMUM
	SHIFT_EXPRESSION		{ $$ = type_simple(bool_t);
					  type_dispose($1); type_dispose($3); }
|	RELATIONAL_EXPRESSION T_MAXIMUM
	SHIFT_EXPRESSION		{ $$ = type_simple(bool_t);
					  type_dispose($1); type_dispose($3); }
;

EQUALITY_EXPRESSION:
	RELATIONAL_EXPRESSION		{ $$ = $1; }
|	EQUALITY_EXPRESSION T_EQEQ
	RELATIONAL_EXPRESSION		{ $$ = type_simple(bool_t);
					  type_dispose($1); type_dispose($3); }
|	EQUALITY_EXPRESSION T_NE
	RELATIONAL_EXPRESSION		{ $$ = type_simple(bool_t);
					  type_dispose($1); type_dispose($3); }
|	EQUALITY_EXPRESSION T_EQEQ
	T_SPECIAL			{ scope_enum_info($1); YYACCEPT; }
|	EQUALITY_EXPRESSION T_NE
	T_SPECIAL			{ scope_enum_info($1); YYACCEPT; }
;

AND_EXPRESSION:
	EQUALITY_EXPRESSION		{ $$ = $1; }
|	AND_EXPRESSION T_AND
	EQUALITY_EXPRESSION		{ $$ = type_connect($1, $3); }
;

EXCLUSIVE_OR_EXPRESSION:
	AND_EXPRESSION			{ $$ = $1; }
|	EXCLUSIVE_OR_EXPRESSION T_HAT
	AND_EXPRESSION			{ $$ = type_connect($1, $3); }
;

INCLUSIVE_OR_EXPRESSION:
	EXCLUSIVE_OR_EXPRESSION		{ $$ = $1; }
|	INCLUSIVE_OR_EXPRESSION T_OR
	EXCLUSIVE_OR_EXPRESSION		{ $$ = type_connect($1, $3); }
;

LOGICAL_AND_EXPRESSION:
	INCLUSIVE_OR_EXPRESSION		{ $$ = $1; }
|	LOGICAL_AND_EXPRESSION T_ANDAND
	INCLUSIVE_OR_EXPRESSION		{ $$ = type_simple(bool_t);
					  type_dispose($1); type_dispose($3); }
;

LOGICAL_OR_EXPRESSION:
	LOGICAL_AND_EXPRESSION		{ $$ = $1; }
|	LOGICAL_OR_EXPRESSION T_OROR
	LOGICAL_AND_EXPRESSION		{ $$ = type_simple(bool_t);
					  type_dispose($1); type_dispose($3); }
;

CONDITIONAL_EXPRESSION:
	LOGICAL_OR_EXPRESSION		{ $$ = $1; }
|	LOGICAL_OR_EXPRESSION T_QUESTION EXPRESSION
	T_COLON ASSIGNMENT_EXPRESSION	{ $$ = $3;
					  type_dispose($1); type_dispose($5); }
;

ASSIGNMENT_EXPRESSION:
	CONDITIONAL_EXPRESSION		{ $$ = $1; }
|	LOGICAL_OR_EXPRESSION ASSIGNMENT_OPERATOR
	ASSIGNMENT_EXPRESSION		{ $$ = $1;
					  type_dispose($3); }
|	THROW_EXPRESSION		{ $$ = type_simple(void_t); }
;

ASSIGNMENT_EXPRESSION_OPT:
	/* Empty */			{ $$ = type_simple(void_t); }
|	ASSIGNMENT_EXPRESSION		{ $$ = $1; }
;

ASSIGNMENT_OPERATOR:
	T_EQ
|	T_STAR_EQ
|	T_SLASH_EQ
|	T_PERCENT_EQ
|	T_PLUS_EQ
|	T_MINUS_EQ
|	T_GTGT_EQ
|	T_LTLT_EQ
|	T_AND_EQ
|	T_HAT_EQ
|	T_OR_EQ
;

EXPRESSION:
	ASSIGNMENT_EXPRESSION		{ $$ = $1; }
|	EXPRESSION T_COMMA
	ASSIGNMENT_EXPRESSION		{ $$ = $3; type_dispose($1); }
;

EXPRESSION_OPT:
	/* Empty */			{ $$ = type_simple(void_t); }
|	EXPRESSION			{ $$ = $1; }
;

CONSTANT_EXPRESSION:
	CONDITIONAL_EXPRESSION		{ $$ = $1; }
;

CONSTANT_EXPRESSION_OPT:
	/* Empty */			{ $$ = type_simple(void_t); }
|	CONSTANT_EXPRESSION		{ $$ = $1; }
;

/*
 * GNU C statement expressions. They are described in GCC info
 * pages under "Statements and Declarations in Expressions".
 *
 * TODO: return the correct type. This will require expanding
 * COMPOUND_STATEMENT far enough to get to the last statement in
 * the sequence.
 */
STATEMENT_EXPRESSION:
	T_LPAREN COMPOUND_STATEMENT
	T_RPAREN			{ $$ = type_simple(void_t); }
;

/* Other */

NEW_ARRAY:
	T_NEW T_SUBSCRIPT
;

/*
 * Note that there was a concept of T_DELETE T_LBRACK CONSTANT_EXPRESSION
 * T_RBRACK in C++ a lot time ago.
 */
DELETE_ARRAY:
	T_DELETE T_SUBSCRIPT
;

%%
