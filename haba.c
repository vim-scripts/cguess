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
 *    notice, this tree of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this tree of conditions and the following disclaimer in
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
 * A simple hash table implementation. It can be used for
 * the symbol table.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "hash.h"

inline hash_position_t hash(const char *key) {
	int p;
	for (p = 0; *key; key ++)
		p += (*(int *) key) << (*key & 11);
	return p;
}
#define SHIFT(x, y)	x ^ (++ l)	/* x + 103 is also good */

inline void hash_insert_sure(struct hash_s *table,
		const void *data, const char *key) {
	hash_position_t pos = hash(key) & table->mask, l = 0;
	while (table->table[pos].key)
		pos = (SHIFT(pos, table->table[pos].data)) & table->mask;
	table->table[pos].key = key;
	table->table[pos].data = data;
}

inline void hash_resize(struct hash_s *table) {
	int i = 0, j = table->size;
	struct hash_element_s *p = table->table;
	struct hash_element_s *s = table->table;

	table->size <<= 2;
	table->mask = table->size - 1;
	table->table = malloc(table->size *
			sizeof(struct hash_element_s));
	if (!table->table) {
		fprintf(stderr, "Aborting: malloc(%i) failed\n",
			table->size *
			sizeof(struct hash_element_s));
		exit(-1);
	}

	memset(table->table, 0, table->size *
			sizeof(struct hash_element_s));

	for (; i < j; s ++, i ++)
		if (s->data)
			hash_insert_sure(table, s->data, s->key);
	free(p);
}

void hash_init(struct hash_s *table) {
	table->table = malloc(INITIAL_SIZE *
			sizeof(struct hash_element_s));
	if (!table->table) {
		fprintf(stderr, "Aborting: malloc(%i) failed\n",
			INITIAL_SIZE *
			sizeof(struct hash_element_s));
		exit(-1);
	}

	memset(table->table, 0, INITIAL_SIZE *
			sizeof(struct hash_element_s));
	table->size = INITIAL_SIZE;
	table->mask = INITIAL_SIZE - 1;
	table->usage = 0;
}

void hash_insert(struct hash_s *table, const void *data, const char *key) {
	hash_position_t pos, l = 0;
	if (table->usage ++ > (table->size >> 1))
		hash_resize(table);

	pos = hash(key) & table->mask;
	while (table->table[pos].key)
		pos = (SHIFT(pos, table->table[pos].data)) & table->mask;
	table->table[pos].key = key;
	table->table[pos].data = data;
}

const void *hash_find(struct hash_s *haystack, const char *needle) {
	hash_position_t pos = hash(needle) & haystack->mask, l = 0;
	struct hash_element_s *e = haystack->table + pos;
	while (
			e->key &&
			strcmp(e->key, needle))
		e = haystack->table +
			(pos = (SHIFT(pos, e->data)) & haystack->mask);

	return e->data;
}

void hash_delete(struct hash_s *table, const char *key) {
	/* TODO! */
}

void hash_foreach(struct hash_s *table, hash_iterator_t iter, void *data) {
	int i = 0;
	struct hash_element_s *s = table->table;
	for (; i < table->size; s ++, i ++)
		if (s->data && !iter((void *) s->data, data))
				return;
}

void hash_done(struct hash_s *table) {
	free(table->table);
}
