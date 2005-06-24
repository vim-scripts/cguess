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
 * Identifier (aka symbol)
 */
#ifndef __identifier_h_
# define __identifier_h_	1

# include "type.h"
# include "symbols.h"

/*
 * The internal name used for unnamed namespaces (only).
 * GCC uses <unnamed>.
 */
# define UNNAMED_ID		"<unnamed>"

/*
 * USING_PREFIX is no longer used.
 */

/*
 * Since we allow errors in code there may be loops in
 * "using" links. We go the easy way and limit the number
 * of jumps to avoid locking up.
 *
 * TODO: Improve this mechanism. There can be a two verse
 * program that would make the parser check 2^MAX_JUMPS
 * symbol tables. (By the way, the said program also kills
 * GCC, at least up to 3.3.4).
 */
# define MAX_JUMPS		32

/*
 * Possible classes of identifiers.
 *
 * none_c is for types of identifiers that we don't know
 * or don't care about.
 *
 * typename_c is a name of a type in general. enum_c and
 * class_c are special cases of names of types.
 * 
 * link_c serves for defining more than one name
 * for a single identifier. Namespace aliases can be an
 * example of links.
 *
 * unnamed_c are local scopes that have no names and
 * therefore there is no way to refer to them from
 * outside and so they can be removed from symbol table
 * right after the parser leaves them.
 *
 * params_c is a function's parameter list (possibly
 * a template's as well).
 */
typedef enum {
	none_c,
	namespace_c,
	function_c,
	enum_c,
	class_c,
	variable_c,
	typename_c,
	template_c,
	unnamed_c,
	link_c,
	params_c,
} identifier_class_t;

/*
 * The structure representing all sorts of identifiers.
 */
struct identifier_s {
	/*
	 * Depending on the class of the identifier,
	 * different fields of the structure have meanings.
	 */
	identifier_class_t id_class;

	/*
	 * The name is the primary key for all searches in
	 * symbol tables. It must be unique. May be empty
	 * and then special rules apply to the identifier.
	 */
	char *name;

	struct type_s type;

	/*
	 * Links.
	 */
	struct symbol_table_s *nested;

	struct symbol_table_s *parent;

# ifndef NDEBUG
	/*
	 * Line number approximation of the definition for
	 * tracking purposes.
	 */
	int line_nr;
# endif /* NDEBUG */
};

/*
 * The number of the last identifier lookup. Its purpose is
 * avoiding infinite loops when searching for a symbol and
 * gaining some speed (see symbols.h).
 *
 * Must be global. Should be increased BEFORE any new lookup
 * everytime we look for a new identifier or there is any
 * change in the symbol tables.
 */
extern int lookup_count;


/* TODO! */
# ifndef NDEBUG
struct identifier_s *identifier_lookup(
		struct symbol_table_s *table, const char *name);
struct identifier_s *identifier_local_lookup(
		struct symbol_table_s *table, const char *name);
void identifier_define(
		struct symbol_table_s *table, const struct identifier_s *id);
void identifier_new_lookup();
# else
#  define identifier_lookup(t, n)	symbol_lookup(t, n)
#  define identifier_local_lookup(t, n)	symbol_lookup_local(t, n)
#  define identifier_define(t, i)	symbol_insert(t, i, i->name)
#  define identifier_new_lookup()	lookup_count ++
# endif /* NDEBUG */

int identifier_is_special(const char *name);
char *identifier_destructor(const char *name);
char *identifier_constructor(const char *name);

#endif /* __identifier_h_ */
