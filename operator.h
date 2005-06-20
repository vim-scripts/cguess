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
 * Utility functions for managing C++ operators.
 */
#ifndef __operator_h_
# define __operator_h_	1

typedef enum operator_e {
	operator_new = 0,
	operator_delete,
	operator_new_array,
	operator_delete_array,
	operator_plus,
	operator_minus,
	operator_star,
	operator_slash,
	operator_percent,
	operator_hat,
	operator_and,
	operator_or,
	operator_tilde,
	operator_not,
	operator_eq,
	operator_langle,
	operator_rangle,
	operator_plus_eq,
	operator_minus_eq,
	operator_star_eq,
	operator_slash_eq,
	operator_percent_eq,
	operator_hat_eq,
	operator_and_eq,
	operator_or_eq,
	operator_ltlt,
	operator_gtgt,
	operator_gtgt_eq,
	operator_ltlt_eq,
	operator_eqeq,
	operator_ne,
	operator_le,
	operator_ge,
	operator_andand,
	operator_oror,
	operator_incr,
	operator_decr,
	operator_comma,
	operator_arrow_star,
	operator_arrow,
	operator_function,
	operator_subscript,
	operator_minimum,
	operator_maximum,

	operator_t_max_val
} operator_t;

/*
 * All operator names will start with this sign in symbol tables.
 */
#define OPERATOR_PREFIX	'='
#define is_operator_name(string)	(*string == OPERATOR_PREFIX)

char *operator_name(operator_t operator);
void operator_visual(const char* name, char *buffer);

#endif /* __operator_h */
