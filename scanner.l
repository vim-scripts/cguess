%{
/*
 * cguess - C/C++/Java(tm) auto-completion tool for VIM
 * Copyright (C) 2005 Andrzej Zaborowski <balrog@zabor.org>
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
 * The lexical analyser for C++ near superset (but this means
 * C++, no preprocessing is done, e.g. no comments are allowed).
 * Lexical errors are ignored whenever possible, to avoid any
 * user interaction. Scanning should be always successful even
 * for a totally deformed code or if a rot13 encoded MPEG movie
 * about ethic dilemas of a concrete giraffe's monument is fed
 * as input.
 *
 * We aim to be both GNU and ISO compatible.
 *
 * Preprocessors own output is ignored for now but it may be
 * used for line counting.
 *
 * This file is meant to be compiled using flex; the lex
 * compatibility state isn't known.
 */
#	include <string.h>
#	include <stdlib.h>

#	include "parser.h"
#	include "scope.h"
#	include "sstack.h"
#	include "fifo.h"
#	include "language.h"
#	include "cguess.h"
#	include "type.h"

#	define YYSTYPE	token_val_t
#	include "y.tab.h"

#	ifdef NDEBUG
#		define RULE_START
#	else
#		define RULE_START	fprintf(stderr, "%s", yytext)
	char buffer[512];
#	endif /* NDEBUG */

#	define TOKEN(token)			\
		if ((ret = tokens[token]))	\
			return ret

	/*
	 * The stacks of attributes.
	 */
	extern struct sstack_s id_stack;
	extern struct sstack_s type_stack;
	extern fifo(char *) id_fifo;

	char *last_string;

	int line = 1;
	int eof = 0;
	int ret;
%}

identifier	[a-zA-Z_$][a-zA-Z_0-9$]*
/* INTEGER_LITERAL & FLOATING_LITERAL accepting errors */
/* equivalent to pp_number */
num_literal	\.?[0-9][.0-9a-fA-FlLuUxX]*
/* CHARACTER_LITERAL accepting errors */
char_literal	\'([^\n\\\']*(\\[^\n])?)*\'?
/* char_literal	\'([^\n\'\\]|(\\[^\n]))\' would be correct */
/* STRING_LITERAL accepting errors */
string_literal	\"(([^\n\\\"]*(\\[^\n])?)*)\"?
/*
 * string_literal \"([^\n\\\"]*(\\[^\n])?)*\" would be correct,
 * although the gnu preprocessor adds the terminating ' and " if
 * omitted.
 */
boolean_literal	true|false
pp_newline	\n
langle		<
rangle		>
lparen		\(
rparen		\)
elipsis		\.\.\.
comma		,
lbrack		\[|<:
rbrack		(\]|:>)
lbrace		\{|<%
rbrace		\}|%>
eq		=
scope		::
semic		;
colon		:
dotstar		\.\*
question	\?
dot		\.

plus		\+
minus		-
star		\*
slash		\/
percent		%
hat		\^|xor
and		&|bitand
or		\||bitor
tilde		~|compl
not		!|not
plus_eq		\+=
minus_eq	-=
star_eq		\*=
slash_eq	\/=
percent_eq	%=
hat_eq		\^=|xor_eq
and_eq		&=|and_eq
or_eq		\|=|or_eq
ltlt		<<
gtgt		>>
ltlt_eq		<<=
gtgt_eq		>>=
eqeq		==
ne		!=
le		<=
ge		>=
andand		&&|and
oror		\|\||or
incr		\+\+
decr		--
arrow_star	->\*
arrow		->

min		<\?
max		>\?

white		[ \t]
ignore		[\r\v\f]
pp		#[^\n]*

skip		{white}|{ignore}|{pp}|{pp_newline}

/* Scanner options */
%option noyywrap

%%
	/* Lexical rules */

{ignore}		RULE_START; /* ignored */
{white}			RULE_START; /* ignored */
{pp}			RULE_START; /* ignored for now */
{pp_newline}		RULE_START; line ++; /* ignored for now */

{num_literal}		RULE_START; TOKEN(T_NUM_LITERAL);
{char_literal}		RULE_START; TOKEN(T_CHAR_LITERAL);
{string_literal}	RULE_START; TOKEN(T_STRING_LITERAL);
{boolean_literal}	RULE_START; TOKEN(T_BOOLEAN_LITERAL);
{elipsis}		RULE_START; TOKEN(T_ELIPSIS);
{comma}			RULE_START; TOKEN(T_COMMA);
{lbrace}		RULE_START; TOKEN(T_LBRACE);
{rbrace}		RULE_START; TOKEN(T_RBRACE);
{scope}			RULE_START; TOKEN(T_SCOPE);
{semic}			RULE_START; TOKEN(T_SEMIC);
{dotstar}		RULE_START; TOKEN(T_DOTSTAR);
{question}		RULE_START; TOKEN(T_QUESTION);
{dot}			RULE_START; TOKEN(T_DOT);
{plus_eq}		RULE_START; TOKEN(T_PLUS_EQ);
{minus_eq}		RULE_START; TOKEN(T_MINUS_EQ);
{star_eq}		RULE_START; TOKEN(T_STAR_EQ);
{slash_eq}		RULE_START; TOKEN(T_SLASH_EQ);
{percent_eq}		RULE_START; TOKEN(T_PERCENT_EQ);
{hat_eq}		RULE_START; TOKEN(T_HAT_EQ);
{and_eq}		RULE_START; TOKEN(T_AND_EQ);
{or_eq}			RULE_START; TOKEN(T_OR_EQ);
{gtgt_eq}		RULE_START; TOKEN(T_GTGT_EQ);
{ltlt_eq}		RULE_START; TOKEN(T_LTLT_EQ);
{ltlt}			RULE_START; TOKEN(T_LTLT);
{gtgt}			RULE_START; TOKEN(T_GTGT);
{eqeq}			RULE_START; TOKEN(T_EQEQ);
{ne}			RULE_START; TOKEN(T_NE);
{le}			RULE_START; TOKEN(T_LE);
{ge}			RULE_START; TOKEN(T_GE);
{andand}		RULE_START; TOKEN(T_ANDAND);
{oror}			RULE_START; TOKEN(T_OROR);
{incr}			RULE_START; TOKEN(T_INCR);
{decr}			RULE_START; TOKEN(T_DECR);
{arrow_star}		RULE_START; TOKEN(T_ARROW_STAR);
{arrow}			RULE_START; TOKEN(T_ARROW);
{lparen}{skip}*{rparen}	RULE_START; TOKEN(T_FUNCTION);
{lbrack}{skip}*{rbrack}	RULE_START; TOKEN(T_SUBSCRIPT);
{plus}			RULE_START; TOKEN(T_PLUS);
{minus}			RULE_START; TOKEN(T_MINUS);
{star}			RULE_START; TOKEN(T_STAR);
{slash}			RULE_START; TOKEN(T_SLASH);
{percent}		RULE_START; TOKEN(T_PERCENT);
{hat}			RULE_START; TOKEN(T_HAT);
{and}			RULE_START; TOKEN(T_AND);
{or}			RULE_START; TOKEN(T_OR);
{tilde}			RULE_START; TOKEN(T_TILDE);
{not}			RULE_START; TOKEN(T_NOT);
{lparen}		RULE_START; TOKEN(T_LPAREN);
{rparen}		RULE_START; TOKEN(T_RPAREN);
{lbrack}		RULE_START; TOKEN(T_LBRACK);
{rbrack}		RULE_START; TOKEN(T_RBRACK);
{langle}		RULE_START; TOKEN(T_LANGLE);
{rangle}		RULE_START; TOKEN(T_RANGLE);
{colon}			RULE_START; TOKEN(T_COLON);
{eq}			RULE_START; TOKEN(T_EQ);
"dynamic_cast"		RULE_START; TOKEN(T_DYNAMIC_CAST);
"static_cast"		RULE_START; TOKEN(T_STATIC_CAST);
"reinterpret_cast"	RULE_START; TOKEN(T_REINTERPRET_CAST);
"const_cast"		RULE_START; TOKEN(T_CONST_CAST);
"typeid"		RULE_START; TOKEN(T_TYPEID);
"this"			RULE_START; TOKEN(T_THIS);
"template"		RULE_START; TOKEN(T_TEMPLATE);
"typename"		RULE_START; TOKEN(T_TYPENAME);
"throw"			RULE_START; TOKEN(T_THROW);
"try"			RULE_START; TOKEN(T_TRY);
"catch"			RULE_START; TOKEN(T_CATCH);
"typedef"		RULE_START; TOKEN(T_TYPEDEF);
"friend"		RULE_START; TOKEN(T_FRIEND);
"class"			RULE_START; TOKEN(T_CLASS);
"namespace"		RULE_START; TOKEN(T_NAMESPACE);
"enum"			RULE_START; TOKEN(T_ENUM);
"struct"		RULE_START; TOKEN(T_STRUCT);
"union"			RULE_START; TOKEN(T_UNION);
"virtual"		RULE_START; TOKEN(T_VIRTUAL);
"private"		RULE_START; TOKEN(T_PRIVATE);
"protected"		RULE_START; TOKEN(T_PROTECTED);
"public"		RULE_START; TOKEN(T_PUBLIC);
"export"		RULE_START; TOKEN(T_EXPORT);
"auto"			RULE_START; TOKEN(T_AUTO);
"register"		RULE_START; TOKEN(T_REGISTER);
"extern"		RULE_START; TOKEN(T_EXTERN);
"mutable"		RULE_START; TOKEN(T_MUTABLE);
"asm"			RULE_START; TOKEN(T_ASM);
"using"			RULE_START; TOKEN(T_USING);
"inline"		RULE_START; TOKEN(T_INLINE);
"explicit"		RULE_START; TOKEN(T_EXPLICIT);
"static"		RULE_START; TOKEN(T_STATIC);
"const"			RULE_START; TOKEN(T_CONST);
"volatile"		RULE_START; TOKEN(T_VOLATILE);
"overload"		RULE_START; TOKEN(T_OVERLOAD);
"operator"		RULE_START; TOKEN(T_OPERATOR);
"sizeof"		RULE_START; TOKEN(T_SIZEOF);
	/* NEW_ARRAY as well as DELETE_ARRAY are syntactic rules */

"new"			RULE_START; TOKEN(T_NEW);
"delete"		RULE_START; TOKEN(T_DELETE);
"char"			RULE_START; TOKEN(T_CHAR);
"wchar_t"		RULE_START; TOKEN(T_WCHAR);
"bool"			RULE_START; TOKEN(T_BOOL);
"short"			RULE_START; TOKEN(T_SHORT);
"int"			RULE_START; TOKEN(T_INT);
"long"			RULE_START; TOKEN(T_LONG);
"signed"		RULE_START; TOKEN(T_SIGNED);
"unsigned"		RULE_START; TOKEN(T_UNSIGNED);
"float"			RULE_START; TOKEN(T_FLOAT);
"double"		RULE_START; TOKEN(T_DOUBLE);
"void"			RULE_START; TOKEN(T_VOID);
"case"			RULE_START; TOKEN(T_CASE);
"default"		RULE_START; TOKEN(T_DEFAULT);
"if"			RULE_START; TOKEN(T_IF);
"else"			RULE_START; TOKEN(T_ELSE);
"switch"		RULE_START; TOKEN(T_SWITCH);
"while"			RULE_START; TOKEN(T_WHILE);
"do"			RULE_START; TOKEN(T_DO);
"for"			RULE_START; TOKEN(T_FOR);
"break"			RULE_START; TOKEN(T_BREAK);
"continue"		RULE_START; TOKEN(T_CONTINUE);
"goto"			RULE_START; TOKEN(T_GOTO);
"return"		RULE_START; TOKEN(T_RETURN);

"restrict"		RULE_START; TOKEN(T_RESTRICT);
"__restrict"		RULE_START; TOKEN(T_RESTRICT);
"__restrict__"		RULE_START; TOKEN(T_RESTRICT);
"typeof"		RULE_START; TOKEN(T_TYPEOF);
"__typeof"		RULE_START; TOKEN(T_TYPEOF);
"__typeof__"		RULE_START; TOKEN(T_TYPEOF);
"__asm"			RULE_START; TOKEN(T_ASM);
"__asm__"		RULE_START; TOKEN(T_ASM);
"__const"		RULE_START; TOKEN(T_CONST);
"__const__"		RULE_START; TOKEN(T_CONST);
"__inline"		RULE_START; TOKEN(T_INLINE);
"__inline__"		RULE_START; TOKEN(T_INLINE);
"__thread"		RULE_START; TOKEN(T_THREAD);
"__thread__"		RULE_START; TOKEN(T_THREAD);
"__volatile"		RULE_START; TOKEN(T_VOLATILE);
"__volatile__"		RULE_START; TOKEN(T_VOLATILE);
"__signed"		RULE_START; TOKEN(T_SIGNED);
"__signed__"		RULE_START; TOKEN(T_SIGNED);
"__unsigned"		RULE_START; TOKEN(T_UNSIGNED);
"__unsigned__"		RULE_START; TOKEN(T_UNSIGNED);

"__extension__"		RULE_START; /* ignored for now */
"__attribute__"		RULE_START; /* ignored for now */
"__offsetof__"		RULE_START; /* ignored for now */

{min}			RULE_START; TOKEN(T_MINIMUM);
{max}			RULE_START; TOKEN(T_MAXIMUM);

{identifier}		RULE_START; TOKEN(T_IDENTIFIER);

<<EOF>>			{
	if (eof)
		return EOF;

	eof = 1;

#ifndef NDEBUG
	context_show_tree();
	fprintf(stderr, "stacks are %i & %i elements high now\n",
		(id_stack.last - id_stack.first) / id_stack.size,
		(type_stack.last - type_stack.first) / type_stack.size);
#endif /* NDEBUG */
	fifo_push(id_fifo, SPECIAL_ID);
	return T_SPECIAL;
}

.		/* Character unrecognized. Ignoring */

%%

#define BUFFER_SIZE		64
#define BUFFER_SIZE_MASK	63

int local_token_fifo[BUFFER_SIZE];
char *local_id_fifo[BUFFER_SIZE];
int lread = 0;
int lwrite = 0;
int lookahead = 0;
int statement_start = 0;
int last_token = 0;

inline void getonetoken() {
	int token = yylex();
	local_token_fifo[lwrite] = token;
	if (token == T_IDENTIFIER) {
		local_id_fifo[lwrite] = malloc(yyleng + 1);
		if (!local_id_fifo[lwrite]) {
			fprintf(stderr,
				"Aborting: malloc(%i) failed\n", yyleng + 1);
			exit(-1);
		}
		strcpy(local_id_fifo[lwrite], yytext);
	}
	lwrite ++;
	lwrite &= BUFFER_SIZE_MASK;
	lookahead ++;
}

int lexer() {
	struct identifier_s *tokeninfo;
	int token, new_id, latoken;
	char *id;

	if (!lookahead) {
		token = yylex();
		id = yytext;
		new_id = 0;
	} else {
		token = local_token_fifo[lread];
		id = local_id_fifo[lread];
		new_id = 1;

		lread ++;
		lread &= BUFFER_SIZE_MASK;
		lookahead --;
	}

	/* TODO: move this to after all the lookahead */
	if (token == T_STRING_LITERAL) {
		last_string = id;
	}

	if (token == T_IDENTIFIER) {
		/* Retrieve information about identifier */
		tokeninfo = scope_lookup(id);

		if (tokeninfo) {
			yylval = type_copy(tokeninfo->type);
			tokeninfo->type.nested = 0;

			if (new_id)
				free(id);

			/* Constructors */
			if (tokeninfo->name && tokeninfo->name[0] == '%') {
				id = tokeninfo->name + 1;
				token = T_CLASS_ID;
				/* TODO: destructors */
			} else {
				id = tokeninfo->name;

				/* Pass an appropriate keyword to the parser */
				switch (tokeninfo->id_class) {
				case typename_c:
					token = T_TYPEDEF_ID;
					break;
				case enum_c:
					token = T_ENUM_ID;
					break;
				case namespace_c:
					token = T_NAMESPACE_ID;
					break;
				case link_c: /* TODO: type checking */
					token = T_ALIAS_ID;
					break;
				case class_c:
					token = T_CLASS_ID;
					break;
				case template_c:
					token = T_TEMPLATE_ID;
					break;
				default:
					break;
				}
			}
		} else {
			if (!new_id) {
				id = malloc(yyleng + 1);
				if (!id) {
					fprintf(stderr,
						"Aborting: malloc(%i)"
						" failed\n",
						yyleng + 1);
					exit(-1);
				}
				strcpy(id, yytext);
			}
			yylval = type_simple(void_t);
		}

#ifndef NDEBUG
		if (token == T_IDENTIFIER) {
			if (tokeninfo) {
				type_visual(tokeninfo->type, buffer);
				fprintf(stderr, " /* %s */", buffer);
			} else
				fprintf(stderr, " /* new */");
		}
#endif /* NDEBUG */
		fifo_push(id_fifo, id);

		/*
		 * Here we are trivially trying to distinguish between a
		 * beginning of a declaration and a postfix expression.
		 *
		 * TODO: cache tokens until the next T_RPAREN and one
		 * token more.
		 */
		if ((
				token == T_TYPEDEF_ID ||
				token == T_CLASS_ID) &&
				code_scope && statement_start) {
			while (lookahead < 1)
				getonetoken();
			latoken = local_token_fifo[lread];

			if (latoken == T_LPAREN || latoken == T_FUNCTION)
				token = T_IDENTIFIER;
		}

		/*
		 * Here we try to tell which T_LANGLEs are beginnings
		 * of a template's argument lists and which are arithmetic
		 * operators.
		 */
		if (token == T_IDENTIFIER && code_scope) {
			while (lookahead < 1)
				getonetoken();

			if (
				local_token_fifo[lread] == T_LANGLE && (
				!tokeninfo ||
				!tokeninfo->parent->definition ||
				tokeninfo->parent->definition->id_class !=
				template_c))
				local_token_fifo[lread] = T_LE;
		}
	} else
		if (
				token == T_LANGLE &&
				last_token != T_IDENTIFIER &&
				last_token != T_CLASS_ID &&
				last_token != T_TYPEDEF_ID &&
				last_token != T_TEMPLATE)
			token = T_LE;

	statement_start = (
		token == T_SEMIC ||
		token == T_LBRACE ||
		token == T_COMMA ||
		token == T_COLON);
	last_token = token;
	return token;
}
