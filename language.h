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
#ifndef __language_h_
# define __language_h_	1

/*
 * Supported languages. ``skip'' is used as lang_local's value
 * when we're currently reading a part of the input that belongs
 * to one of the #included files (as preprocessor's comments
 * indicate) that we may have been reqested not to parse.
 */
typedef enum language_e {
	c,
	cpp,
	java,
	skip,
	language_t_max
} language_t;

/*
 * The first is the language that the program was started
 * parsing in and the second one is the current language (i.e.
 * at the current cursor position).
 */
extern language_t lang_global;
extern language_t lang_local;

/*
 * The table of tokens used in the current language. It can map
 * one token's number to other or it can be zero for a token
 * that doesn't exist in the language.
 */
extern int *tokens;

void language_set_global(language_t lang);
void language_set_local(language_t lang);

#endif /* __language_h */
