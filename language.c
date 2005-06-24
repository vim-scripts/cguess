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
 * Utility macros for switching between the supported languages.
 */

#include <string.h>

#include "y.tab.h"
#include "language.h"

language_t lang_global;
language_t lang_local;

int *tokens;

int *languages[language_t_max];

struct {
	int token, value;
}
c_tokens[] = {
	{ T_IDENTIFIER, T_IDENTIFIER },
	{ T_TYPEDEF_ID, T_TYPEDEF_ID },
	{ T_ENUM_ID, T_ENUM_ID },
	{ T_CLASS_ID, T_CLASS_ID },
	{ T_NUM_LITERAL, T_NUM_LITERAL },
	{ T_CHAR_LITERAL, T_CHAR_LITERAL },
	{ T_STRING_LITERAL, T_STRING_LITERAL },
	{ T_BOOLEAN_LITERAL, T_BOOLEAN_LITERAL },
	{ T_LANGLE, T_LANGLE },
	{ T_RANGLE, T_RANGLE },
	{ T_LPAREN, T_LPAREN },
	{ T_RPAREN, T_RPAREN },
	{ T_ELIPSIS, T_ELIPSIS },
	{ T_COMMA, T_COMMA },
	{ T_LBRACK, T_LBRACK },
	{ T_RBRACK, T_RBRACK },
	{ T_LBRACE, T_LBRACE },
	{ T_RBRACE, T_RBRACE },
	{ T_EQ, T_EQ },
	{ T_SEMIC, T_SEMIC },
	{ T_COLON, T_COLON },
	{ T_QUESTION, T_QUESTION },
	{ T_DOT, T_DOT },
	{ T_DYNAMIC_CAST, T_IDENTIFIER },
	{ T_STATIC_CAST, T_IDENTIFIER },
	{ T_REINTERPRET_CAST, T_IDENTIFIER },
	{ T_CONST_CAST, T_IDENTIFIER },
	{ T_TYPEID, T_IDENTIFIER },
	{ T_THIS, T_IDENTIFIER },
	{ T_TEMPLATE, T_IDENTIFIER },
	{ T_TYPENAME, T_IDENTIFIER },
	{ T_THROW, T_IDENTIFIER },
	{ T_TRY, T_IDENTIFIER },
	{ T_CATCH, T_IDENTIFIER },
	{ T_TYPEDEF, T_TYPEDEF },
	{ T_FRIEND, T_IDENTIFIER },
	{ T_CLASS, T_CLASS },
	{ T_NAMESPACE, T_IDENTIFIER },
	{ T_ENUM, T_ENUM },
	{ T_STRUCT, T_STRUCT },
	{ T_UNION, T_UNION },
	{ T_VIRTUAL, T_IDENTIFIER },
	{ T_PRIVATE, T_IDENTIFIER },
	{ T_PROTECTED, T_IDENTIFIER },
	{ T_PUBLIC, T_IDENTIFIER },
	{ T_EXPORT, T_IDENTIFIER },
	{ T_AUTO, T_IDENTIFIER },
	{ T_REGISTER, T_REGISTER },
	{ T_EXTERN, T_EXTERN },
	{ T_MUTABLE, T_IDENTIFIER },
	{ T_ASM, T_ASM },
	{ T_USING, T_IDENTIFIER },
	{ T_INLINE, T_INLINE },
	{ T_EXPLICIT, T_IDENTIFIER },
	{ T_STATIC, T_STATIC },
	{ T_CONST, T_CONST },
	{ T_VOLATILE, T_VOLATILE },
	{ T_OVERLOAD, 0 },
	{ T_OPERATOR, T_IDENTIFIER },
	{ T_SIZEOF, T_SIZEOF },
	{ T_NEW, T_IDENTIFIER },
	{ T_DELETE, T_IDENTIFIER },
	{ T_PLUS, T_PLUS },
	{ T_MINUS, T_MINUS },
	{ T_STAR, T_STAR },
	{ T_SLASH, T_SLASH },
	{ T_PERCENT, T_PERCENT },
	{ T_HAT, T_HAT },
	{ T_AND, T_AND },
	{ T_OR, T_OR },
	{ T_TILDE, T_TILDE },
	{ T_NOT, T_NOT },
	{ T_PLUS_EQ, T_PLUS_EQ },
	{ T_MINUS_EQ, T_MINUS_EQ },
	{ T_STAR_EQ, T_STAR_EQ },
	{ T_SLASH_EQ, T_SLASH_EQ },
	{ T_PERCENT_EQ, T_PERCENT_EQ },
	{ T_HAT_EQ, T_HAT_EQ },
	{ T_AND_EQ, T_AND_EQ },
	{ T_OR_EQ, T_OR_EQ },
	{ T_LTLT, T_LTLT },
	{ T_GTGT, T_GTGT },
	{ T_GTGT_EQ, T_GTGT_EQ },
	{ T_LTLT_EQ, T_LTLT_EQ },
	{ T_EQEQ, T_EQEQ },
	{ T_NE, T_NE },
	{ T_LE, T_LE },
	{ T_GE, T_GE },
	{ T_ANDAND, T_ANDAND },
	{ T_OROR, T_OROR },
	{ T_INCR, T_INCR },
	{ T_DECR, T_DECR },
	{ T_ARROW, T_ARROW },
	{ T_FUNCTION, T_FUNCTION },
	{ T_SUBSCRIPT, T_SUBSCRIPT },
	{ T_CHAR, T_CHAR },
	{ T_WCHAR, T_WCHAR },
	{ T_BOOL, T_BOOL },
	{ T_SHORT, T_SHORT },
	{ T_INT, T_INT },
	{ T_LONG, T_LONG },
	{ T_SIGNED, T_SIGNED },
	{ T_UNSIGNED, T_UNSIGNED },
	{ T_FLOAT, T_FLOAT },
	{ T_DOUBLE, T_DOUBLE },
	{ T_VOID, T_VOID },
	{ T_CASE, T_CASE },
	{ T_DEFAULT, T_DEFAULT },
	{ T_IF, T_IF },
	{ T_ELSE, T_ELSE },
	{ T_SWITCH, T_SWITCH },
	{ T_WHILE, T_WHILE },
	{ T_DO, T_DO },
	{ T_FOR, T_FOR },
	{ T_BREAK, T_BREAK },
	{ T_CONTINUE, T_CONTINUE },
	{ T_GOTO, T_GOTO },
	{ T_RETURN, T_RETURN },
	{ T_TYPEOF, T_TYPEOF },
	{ T_THREAD, 0 },
	{ T_MINIMUM, T_MINIMUM },
	{ T_MAXIMUM, T_MAXIMUM },
	{ T_RESTRICT, T_IDENTIFIER }, /* TODO */
	{ T_SPECIAL, T_SPECIAL },
	{ 0, 0 },
},
cpp_tokens[] = {
	{ T_IDENTIFIER, T_IDENTIFIER },
	{ T_TYPEDEF_ID, T_TYPEDEF_ID },
	{ T_ENUM_ID, T_ENUM_ID },
	{ T_NAMESPACE_ID, T_NAMESPACE_ID },
	{ T_ALIAS_ID, T_ALIAS_ID },
	{ T_CLASS_ID, T_CLASS_ID },
	{ T_TEMPLATE_ID, T_TEMPLATE_ID },
	{ T_NUM_LITERAL, T_NUM_LITERAL },
	{ T_CHAR_LITERAL, T_CHAR_LITERAL },
	{ T_STRING_LITERAL, T_STRING_LITERAL },
	{ T_BOOLEAN_LITERAL, T_BOOLEAN_LITERAL },
	{ T_LANGLE, T_LANGLE },
	{ T_RANGLE, T_RANGLE },
	{ T_LPAREN, T_LPAREN },
	{ T_RPAREN, T_RPAREN },
	{ T_ELIPSIS, T_ELIPSIS },
	{ T_COMMA, T_COMMA },
	{ T_LBRACK, T_LBRACK },
	{ T_RBRACK, T_RBRACK },
	{ T_LBRACE, T_LBRACE },
	{ T_RBRACE, T_RBRACE },
	{ T_EQ, T_EQ },
	{ T_SCOPE, T_SCOPE },
	{ T_SEMIC, T_SEMIC },
	{ T_COLON, T_COLON },
	{ T_DOTSTAR, T_DOTSTAR },
	{ T_QUESTION, T_QUESTION },
	{ T_DOT, T_DOT },
	{ T_DYNAMIC_CAST, T_DYNAMIC_CAST },
	{ T_STATIC_CAST, T_STATIC_CAST },
	{ T_REINTERPRET_CAST, T_REINTERPRET_CAST },
	{ T_CONST_CAST, T_CONST_CAST },
	{ T_TYPEID, T_TYPEID },
	{ T_THIS, T_THIS },
	{ T_TEMPLATE, T_TEMPLATE },
	{ T_TYPENAME, T_TYPENAME },
	{ T_THROW, T_THROW },
	{ T_TRY, T_TRY },
	{ T_CATCH, T_CATCH },
	{ T_TYPEDEF, T_TYPEDEF },
	{ T_FRIEND, T_FRIEND },
	{ T_CLASS, T_CLASS },
	{ T_NAMESPACE, T_NAMESPACE },
	{ T_ENUM, T_ENUM },
	{ T_STRUCT, T_STRUCT },
	{ T_UNION, T_UNION },
	{ T_VIRTUAL, T_VIRTUAL },
	{ T_PRIVATE, T_PRIVATE },
	{ T_PROTECTED, T_PROTECTED },
	{ T_PUBLIC, T_PUBLIC },
	{ T_EXPORT, T_EXPORT },
	{ T_AUTO, T_AUTO },
	{ T_REGISTER, T_REGISTER },
	{ T_EXTERN, T_EXTERN },
	{ T_MUTABLE, T_MUTABLE },
	{ T_ASM, T_ASM },
	{ T_USING, T_USING },
	{ T_INLINE, T_INLINE },
	{ T_EXPLICIT, T_EXPLICIT },
	{ T_STATIC, T_STATIC },
	{ T_CONST, T_CONST },
	{ T_VOLATILE, T_VOLATILE },
	{ T_OVERLOAD, T_OVERLOAD },
	{ T_OPERATOR, T_OPERATOR },
	{ T_SIZEOF, T_SIZEOF },
	{ T_NEW, T_NEW },
	{ T_DELETE, T_DELETE },
	{ T_PLUS, T_PLUS },
	{ T_MINUS, T_MINUS },
	{ T_STAR, T_STAR },
	{ T_SLASH, T_SLASH },
	{ T_PERCENT, T_PERCENT },
	{ T_HAT, T_HAT },
	{ T_AND, T_AND },
	{ T_OR, T_OR },
	{ T_TILDE, T_TILDE },
	{ T_NOT, T_NOT },
	{ T_PLUS_EQ, T_PLUS_EQ },
	{ T_MINUS_EQ, T_MINUS_EQ },
	{ T_STAR_EQ, T_STAR_EQ },
	{ T_SLASH_EQ, T_SLASH_EQ },
	{ T_PERCENT_EQ, T_PERCENT_EQ },
	{ T_HAT_EQ, T_HAT_EQ },
	{ T_AND_EQ, T_AND_EQ },
	{ T_OR_EQ, T_OR_EQ },
	{ T_LTLT, T_LTLT },
	{ T_GTGT, T_GTGT },
	{ T_GTGT_EQ, T_GTGT_EQ },
	{ T_LTLT_EQ, T_LTLT_EQ },
	{ T_EQEQ, T_EQEQ },
	{ T_NE, T_NE },
	{ T_LE, T_LE },
	{ T_GE, T_GE },
	{ T_ANDAND, T_ANDAND },
	{ T_OROR, T_OROR },
	{ T_INCR, T_INCR },
	{ T_DECR, T_DECR },
	{ T_ARROW_STAR, T_ARROW_STAR },
	{ T_ARROW, T_ARROW },
	{ T_FUNCTION, T_FUNCTION },
	{ T_SUBSCRIPT, T_SUBSCRIPT },
	{ T_CHAR, T_CHAR },
	{ T_WCHAR, T_WCHAR },
	{ T_BOOL, T_BOOL },
	{ T_SHORT, T_SHORT },
	{ T_INT, T_INT },
	{ T_LONG, T_LONG },
	{ T_SIGNED, T_SIGNED },
	{ T_UNSIGNED, T_UNSIGNED },
	{ T_FLOAT, T_FLOAT },
	{ T_DOUBLE, T_DOUBLE },
	{ T_VOID, T_VOID },
	{ T_CASE, T_CASE },
	{ T_DEFAULT, T_DEFAULT },
	{ T_IF, T_IF },
	{ T_ELSE, T_ELSE },
	{ T_SWITCH, T_SWITCH },
	{ T_WHILE, T_WHILE },
	{ T_DO, T_DO },
	{ T_FOR, T_FOR },
	{ T_BREAK, T_BREAK },
	{ T_CONTINUE, T_CONTINUE },
	{ T_GOTO, T_GOTO },
	{ T_RETURN, T_RETURN },
	{ T_TYPEOF, T_TYPEOF },
	{ T_THREAD, T_THREAD },
	{ T_MINIMUM, T_MINIMUM },
	{ T_MAXIMUM, T_MAXIMUM },
	{ T_RESTRICT, 0 },	/* TODO */
	{ T_SPECIAL, T_SPECIAL },
	{ 0, 0 },
},
java_tokens[] = {
/*	TODO	*/
/*	{ T_EXTENDS, T_COLON },	*/
/*	{ T_IMPLEMENTS, T_COLON },	*/
	{ T_LANGLE, T_LE },
	{ 0, 0 },
};

int c_table[T_LAST_TOKEN];
int cpp_table[T_LAST_TOKEN];
int java_table[T_LAST_TOKEN];
int skip_table[T_LAST_TOKEN];

/*
 * Sets the language for the global scope of the source file
 * (the one that cannot be altered by linkage specification
 * declarations in the source file). Should only be called once
 * per input file.
 */
void language_set_global(language_t lang) {
	int i;
	for (i = 0; i < T_LAST_TOKEN; i ++) {
		c_table[i] = i;		/* 0; */
		cpp_table[i] = i;	/* 0; */
		java_table[i] = i;	/* 0; */
		skip_table[i] = 0;
	}

	for (i = 0; c_tokens[i].token; i ++)
		c_table[c_tokens[i].token] = c_tokens[i].value;
	
	for (i = 0; cpp_tokens[i].token; i ++)
		cpp_table[cpp_tokens[i].token] = cpp_tokens[i].value;

	for (i = 0; java_tokens[i].token; i ++)
		java_table[java_tokens[i].token] = java_tokens[i].value;

	languages[c] = c_table;
	languages[cpp] = cpp_table;
	languages[java] = java_table;
	languages[skip] = skip_table;

	lang_global = lang;
	language_set_local(lang);
}

/*
 * Switches between the supported languages with an immediate
 * effect on the lexical scanner. Fast, can be used many times in
 * a single source file.
 */
void language_set_local(language_t lang) {
	if (lang_local == lang)
		return;

	lang_local = lang;
	tokens = languages[lang];
}

/*
 * Returns the language whose string representation is in the
 * parameter.
 */
language_t language_from_name(const char *id) {
	const char *begin, *end;
	begin = id;
	end = id + strlen(id);
	while (begin < end && (
				*begin == ' ' || *begin == '\t' ||
				*begin == '\"' || *begin == '\''))
		begin ++;
	while (begin < end && (
				end[-1] == ' ' || end[-1] == '\t' ||
				end[-1] == '\"' || end[-1] == '\''))
		end --;

	switch (end - begin) {
	case 1:
		if (*begin == 'c' || *begin == 'C')
			return c;
		break;

	case 3:
		if (*begin == 'c' || *begin == 'C')
			return cpp;
		break;
	}

	if (*begin == 'j' || *begin == 'J')
		return java;

	return skip;
}
