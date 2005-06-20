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
 * Identifier (aka symbol)
 */
#include <string.h>
#include <stdlib.h>

#include "identifier.h"
#include "cguess.h"

struct identifier_s *identifier_lookup(
		struct symbol_table_s *table, const char *name) {
	struct identifier_s *id = symbol_lookup(table, name);
	return id;

	/* TODO: check enums */
}

struct identifier_s *identifier_local_lookup(
		struct symbol_table_s *table, const char *name) {
	return symbol_lookup_local(table, name);
}

void identifier_define(
		struct symbol_table_s *table, const struct identifier_s *id) {
	symbol_insert(table, id, id->name);
}

int identifier_is_special(const char *name) {
	return !strcmp(name, SPECIAL_ID);
}

char *identifier_destructor(const char *name) {
	char *id = malloc(strlen(name) + 2);
	strcpy(id, "~");
	strcat(id, name);
	return id;
}

char *identifier_constructor(const char *name) {
	char *id = malloc(strlen(name) + 2);
	strcpy(id, "%");
	strcat(id, name);
	return id;
}
