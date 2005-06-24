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

#include "symbols.h"
#include "cguess.h"

/*
 * The number of the last identifier lookup. Its purpose is
 * avoiding infinite loops when searching for a symbol and
 * gaining some speed (see symbols.h).
 */
int lookup_count = 0;

/*
 * Initializes an unordered symbol tables at the addres given
 * in first parameter.
 */
void symbol_table_init(struct symbol_table_s *table, void *def) {
	table->is_ordered = 0;
	STRUCT_CALL(init, &table->table);
	STRUCT_O_CALL(init, &table->links);
	table->definition = def;
	table->lookup_count = 0;
}

void symbol_table_done(struct symbol_table_s *table) {
	if (table->is_ordered)
		STRUCT_O_CALL(done, &table->table_o);
	else
		STRUCT_CALL(done, &table->table);
	STRUCT_O_CALL(done, &table->table_o);
}

void *symbol_table_def(struct symbol_table_s *table) {
	return table->definition;
}

int symbol_nested_lookup(struct symbol_table_s *table, char **key) {
	void *ret;
	/*
	 * We assume that when an identifier is found any
	 * function that performs the lookup exits immediately,
	 * and no further lookups are done. Otherwise any
	 * second lookup will return failure or we would have
	 * to remember the last lookup's result separately for
	 * each table.
	 */
	if (table->lookup_count == lookup_count)
		return 0;

	/*
	 * The counter is updated before the search so that
	 * if this table is linked by itself or any other
	 * linked table, no multiple searches are done.
	 */
	table->lookup_count = lookup_count;

	if (table->is_ordered)
		ret = (void *) STRUCT_O_CALL(find, &table->table_o, *key);
	else
		ret = (void *) STRUCT_CALL(find, &table->table, *key);
	if (!ret) {
		ret = *key;
		STRUCT_O_CALL(
				foreach,
				&table->links,
				(STRUCT_O_NAME(_iterator_t))
					symbol_nested_lookup,
				&ret);
		if (ret == *key)
			return 1;
	}
	*key = ret;
	return 0;
}

void *symbol_lookup(struct symbol_table_s *table, const char *key) {
	void *ret;
	/*
	 * We assume that when an identifier is found any
	 * function that performs the lookup exits immediately,
	 * and no further lookups are done. Otherwise any
	 * second lookup will return failure or we would have
	 * to remember the last lookup's result separately for
	 * each table.
	 */
	if (table->lookup_count == lookup_count)
		return 0;

	/*
	 * The counter is updated before the search so that
	 * if this table is linked by itself or any other
	 * linked table, no multiple searches are done.
	 */
	table->lookup_count = lookup_count;

	if (table->is_ordered)
		ret = (void *) STRUCT_O_CALL(find, &table->table_o, key);
	else
		ret = (void *) STRUCT_CALL(find, &table->table, key);
	if (!ret) {
		ret = (void *) key;
		STRUCT_O_CALL(
				foreach,
				&table->links,
				(STRUCT_O_NAME(_iterator_t))
					symbol_nested_lookup,
				&ret);
		if (ret == key)
			return 0;
	}
	return ret;
}

void *symbol_lookup_local(struct symbol_table_s *table, const char *key) {
	/* No counter update is needed here */
	if (table->is_ordered)
		return (void *) STRUCT_O_CALL(find, &table->table_o, key);
	else
		return (void *) STRUCT_CALL(find, &table->table, key);
}

void symbol_insert(struct symbol_table_s *table,
		const void *data, const char *key) {
	if (table->is_ordered)
		STRUCT_O_CALL(insert, &table->table_o, data, key);
	else
		STRUCT_CALL(insert, &table->table, data, key);
}

struct iter_helper_s {
	struct symbol_table_s *table;
	table_iter_t func;
};

int symbol_iterator(void *element, struct iter_helper_s *data) {
	data->func(data->table, element);
	return 1;
}

/*
 * This doesn't support ordered tables still.
 */
void symbol_table_merge(struct symbol_table_s *dst,
		struct symbol_table_s *src, table_iter_t insert) {
	struct iter_helper_s data = { dst, insert };
	STRUCT_CALL(
			foreach,
			&src->table,
			(STRUCT_NAME(_iterator_t)) symbol_iterator,
			&data);
}

void symbol_table_foreach(struct symbol_table_s *table,
		table_iterator_t func, void *data) {
	if (table->is_ordered)
		STRUCT_O_CALL(
				foreach,
				&table->table_o,
				(STRUCT_O_NAME(_iterator_t)) func,
				data);
	else
		STRUCT_CALL(
				foreach,
				&table->table,
				(STRUCT_NAME(_iterator_t)) func,
				data);
}

void symbol_table_link(struct symbol_table_s *table,
		struct symbol_table_s *link) {
	STRUCT_O_CALL(
			insert,
			&table->links,
			link,
			"<link>");
}

void symbol_table_unlink(struct symbol_table_s *table) {
	STRUCT_O_CALL(done, &table->links);
	STRUCT_O_CALL(init, &table->links);
}

void symbol_table_ordered_init(struct symbol_table_s *table, void *def) {
	table->is_ordered = 1;
	STRUCT_O_CALL(init, &table->table_o);
	STRUCT_O_CALL(init, &table->links);
	table->definition = def;
	table->lookup_count = 0;
}

void symbol_table_link_foreach(struct symbol_table_s *table,
		table_iterator_t func, void *data) {
	STRUCT_O_CALL(
			foreach,
			&table->links,
			(STRUCT_O_NAME(_iterator_t)) func,
			data);
}
