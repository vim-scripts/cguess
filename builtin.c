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

#include <string.h>

#include "builtin.h"
#include "cguess.h"

/* A static buffer for return values. TODO: change! */
static struct identifier_s id;
char name_buffer[512];

/* This will be changed later */
struct identifier_s *is_gcc_builtin(const char *name) {
	if (
			!strcmp(name, "__builtin_va_list") ||
			!strcmp(name, "__builtin_va_alist")) {
		id.id_class = typename_c;
		id.nested = 0;
		id.name = 0;
		id.type = type_simple(int_t);

		return &id;
	}

	if (
			!strcmp(name, "__builtin_va_list_t") ||
			!strcmp(name, "__builtin_va_alist_t")) {
		id.id_class = typename_c;
		id.nested = 0;
		id.name = 0;
		id.type = type_simple(int_t);

		return &id;
	}

	if (
			!strncmp(name, "__builtin", 9)) {
		strncpy(name_buffer, name, 512);
		id.id_class = function_c;
		id.nested = 0;
		id.name = name_buffer;
		id.type = type_simple(int_t);
		id.type.category = function_t;
		id.type.function_type.return_type = 0;
		id.type.function_type.parameters = 0;
		return &id;
	}

	return 0;
}
