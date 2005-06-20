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
 * Utility functions for managing C++ operators.
 *
 * Note: When adding a new operator, it first has to be added
 * as a token in c++.y, than as a lexeme in scanner.l, then there
 * needs to be a production for it in c++.y in the OPERATOR_NAME
 * rule (possibly also in ASSIGNMENT_OPERATOR). Finally add it
 * in the enum operator_e in operator.h and a visual string for
 * it in operator_visual() below in this file.
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "operator.h"

/*
 * Returns a name for an operator, that can be inserted into a
 * symbol table.
 */
char *operator_name(operator_t operator) {
	char *str = malloc(3);
	if (!str) {
		fprintf(stderr, "Aborting: malloc(3) failed\n");
		exit(-1);
	}

	str[0] = OPERATOR_PREFIX;
	str[1] = operator + 'a';
	str[2] = 0;
	return str;
}

/*
 * Fills buffer with a human readable form of the identifier name.
 *
 * TODO: as for type_visual(), control the length of the buffer.
 */
void operator_visual(const char *name, char *buffer) {
	char op;
	assert(is_operator_name(name));

	op = name[1] - 'a';
	assert(op >= 0 && op < operator_t_max_val);

	strcpy(buffer, "operator ");

	/* TODO: use some tables or trees to make this faster */
	switch (op) {
	case operator_new:
		strcat(buffer, "new");
		break;
	case operator_delete:
		strcat(buffer, "delete");
		break;
	case operator_new_array:
		strcat(buffer, "new[]");
		break;
	case operator_delete_array:
		strcat(buffer, "delete[]");
		break;
	case operator_plus:
		strcat(buffer, "+");
		break;
	case operator_minus:
		strcat(buffer, "-");
		break;
	case operator_star:
		strcat(buffer, "*");
		break;
	case operator_slash:
		strcat(buffer, "/");
		break;
	case operator_percent:
		strcat(buffer, "%");
		break;
	case operator_hat:
		strcat(buffer, "^");
		break;
	case operator_and:
		strcat(buffer, "&");
		break;
	case operator_or:
		strcat(buffer, "|");
		break;
	case operator_tilde:
		strcat(buffer, "~");
		break;
	case operator_not:
		strcat(buffer, "!");
		break;
	case operator_eq:
		strcat(buffer, "=");
		break;
	case operator_langle:
		strcat(buffer, "<");
		break;
	case operator_rangle:
		strcat(buffer, ">");
		break;
	case operator_plus_eq:
		strcat(buffer, "+=");
		break;
	case operator_minus_eq:
		strcat(buffer, "-=");
		break;
	case operator_star_eq:
		strcat(buffer, "*=");
		break;
	case operator_slash_eq:
		strcat(buffer, "/=");
		break;
	case operator_percent_eq:
		strcat(buffer, "%=");
		break;
	case operator_hat_eq:
		strcat(buffer, "^=");
		break;
	case operator_and_eq:
		strcat(buffer, "&=");
		break;
	case operator_or_eq:
		strcat(buffer, "|=");
		break;
	case operator_ltlt:
		strcat(buffer, "<<");
		break;
	case operator_gtgt:
		strcat(buffer, ">>");
		break;
	case operator_gtgt_eq:
		strcat(buffer, ">>=");
		break;
	case operator_ltlt_eq:
		strcat(buffer, "<<=");
		break;
	case operator_eqeq:
		/*
		 * The whitespace here is to not trigger the script on ==
		 * recursively in VIM.
		 */
		/*strcat(buffer, "= =");*/
		strcat(buffer, "==");
		break;
	case operator_ne:
		/*
		 * The whitespace here is to not trigger the script on !=
		 * recursively in VIM.
		 */
		/*strcat(buffer, "! =");*/
		strcat(buffer, "!=");
		break;
	case operator_le:
		strcat(buffer, "<=");
		break;
	case operator_ge:
		strcat(buffer, ">=");
		break;
	case operator_andand:
		strcat(buffer, "&&");
		break;
	case operator_oror:
		strcat(buffer, "||");
		break;
	case operator_incr:
		strcat(buffer, "++");
		break;
	case operator_decr:
		strcat(buffer, "--");
		break;
	case operator_comma:
		strcat(buffer, ",");
		break;
	case operator_arrow_star:
		/*
		 * The whitespace here is to not trigger the script on ->
		 * recursively in VIM.
		 */
		/*strcat(buffer, "->*");*/
		strcat(buffer, "->*");
		break;
	case operator_arrow:
		/*
		 * The whitespace here is to not trigger the script on ->
		 * recursively in VIM.
		 */
		/*strcat(buffer, "- >");*/
		strcat(buffer, "->");
		break;
	case operator_function:
		strcat(buffer, "()");
		break;
	case operator_subscript:
		strcat(buffer, "[]");
		break;
	case operator_minimum:
		strcat(buffer, "<?");
		break;
	case operator_maximum:
		strcat(buffer, ">?");
		break;
	default:
		strcat(buffer, "xxx");
		break;
	}
}
