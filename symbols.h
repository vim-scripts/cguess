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

#ifndef __symbols_h_
# define __symbols_h_	1

/* The structures used for the table */

# include "hash.h"
# define STRUCT_NAME(id) hash ## id

# include "list.h"
# define STRUCT_O_NAME(id) list ## id

# define STRUCT		struct STRUCT_NAME(_s)
# define STRUCT_CALL(name, args...) STRUCT_NAME(_ ## name) (args)

# define STRUCT_O	struct STRUCT_O_NAME(_s)
# define STRUCT_O_CALL(name, args...) STRUCT_O_NAME(_ ## name) (args)

/*
 * The table of symbols defined in a local scope.
 *
 * It can contain sub-tables for its nested contexts thus
 * forming a tree of symbols. It also maintains a list of
 * immediate links that let you transparently include other
 * symbol tables in this one.
 *
 * The symbol table can be ordered (a sequence of symbols,
 * slow) or not (a set of symbols, a bit faster). Ordered
 * tables will be used when you often need to list the
 * contents, or maintain the order of symbols, and the
 * unordered ones when you often need to do a key lookup
 * (find operation).
 *
 * TODO: for function parameter list we should use something
 * intermediate, like a tree with each element linked to its
 * successor, or simply copy all its elements to the context
 * of the function, like we did in version 0.1.
 *
 * TODO: possibly .table should be a union containing
 * current .table and .table_o
 */

struct symbol_table_s {
	STRUCT table;
	STRUCT_O table_o;
	STRUCT_O links;
	int is_ordered;
	struct identifier_s *definition;

	/*
	 * This holds the number of the last identifier lookup. Each
	 * action of searching for a symbol numbered. This way we can
	 * guarantee that each identifier is only looked up once in each
	 * symbol table and thus avoid infinite loops and situations
	 * when 2 ^ n lookups are required for 2 * n tables.
	 */
	int lookup_count;
};

/* TODO: correct this */
typedef void (*table_iter_t) (struct symbol_table_s *, void *);
typedef int (*table_iterator_t) (void *, void *);

void symbol_table_init(struct symbol_table_s *table, void *def);
void symbol_table_done(struct symbol_table_s *table);
void *symbol_table_def(struct symbol_table_s *table);
void symbol_table_ordered_init(struct symbol_table_s *table, void *def);
void *symbol_lookup(struct symbol_table_s *table, const char *key);
void *symbol_lookup_local(struct symbol_table_s *table, const char *key);
void symbol_insert(struct symbol_table_s *table,
		const void *data, const char *key);
void symbol_table_merge(struct symbol_table_s *dst,
		struct symbol_table_s *src, table_iter_t insert);
void symbol_table_foreach(struct symbol_table_s *table,
		table_iterator_t func, void *data);
void symbol_table_link(struct symbol_table_s *table,
		struct symbol_table_s *link);
void symbol_table_unlink(struct symbol_table_s *table);
void symbol_table_link_foreach(struct symbol_table_s *table,
		table_iterator_t func, void *data);

#endif /* __symbols_h_ */
