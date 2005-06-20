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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "symbols.h"
#include "scope.h"
#include "context.h"
#include "identifier.h"
#include "type.h"
#include "builtin.h"
#include "cguess.h"
#include "parser.h"

/*
 * We don't need a real stack for statement's local scope
 * since C++ has no way to go up in the symbols tree.
 * You can only reset it to the local context or to the
 * global scope with "::".
 */
struct symbol_table_s *stmt_local, *stmt_stack;

/*
 * A current parent template, null if we're not inside
 * a template.
 */
struct identifier_s *template_parent;
int template_depth = 1; /* TODO: remove */

/*
 * Indicates if parser is currently inside a compound
 * statement (somewhere where statements are allowed). It
 * is a tip for the lexer and is set by the parser.
 */
int code_scope = 0;

/*
 * auto_id is used for generating automatic identifiers where
 * the input omits them and there is a possibility that we
 * will need to display the data later. Otherwise the data is
 * simply not added to the symbol table. scope_define() does
 * that if the id parameter is null. It generates an unique
 * identifier based on auto_id's value and increments the
 * variable. The value is global for all scopes even though
 * the identifiers don't need to be globally unique (but it
 * doesn't cost anything and saves us some thinking).
 */
int auto_id = 0;

/*
 * In verbose mode, information that is not needed by the
 * parser anymore will also be added to the symbol tree, so
 * that the tree is complete and can be used for other
 * purposes after parsing.
 */
int verbose = 0;

#ifndef NDEBUG
extern int line;
#endif /* NDEBUG */

/*
 * Called at the beginnig of parsing the program.
 */
void scope_init() {
	context_init();
	scope_stmt_reset();
	scope_reset_template();
	scope_open(PRINCIPAL_SCOPE, unnamed_c, type_simple(void_t));
}

struct type_s scope_open(const char *name, identifier_class_t id_class,
		struct type_s type) {
	struct identifier_s *id = 0;
	struct symbol_table_s *table = context_local();
	if (type.nested && type.definition)
		table = type.definition->parent;
	if (!type.nested)
		type.definition = 0;

	/* TODO: Check if verbose mode is on */
	if ((id_class != unnamed_c || verbose) && name)
		id = identifier_local_lookup(table, name);

	if (id && id_class == function_c)
		id->nested = 0;

	/* Create new identifier */
	if (!id) {
		id = malloc(sizeof(struct identifier_s));
		if (!id) {
			fprintf(stderr, "Aborting: malloc(%i) failed\n",
					sizeof(struct identifier_s));
			exit(-1);
		}

		id->nested = 0;
		id->parent = 0;
		id->name = (char *) name;

		/* TODO: Check if verbose mode is on */
		if ((id_class != unnamed_c || verbose) && name)
			identifier_define(table, id);
	} else
		type_dispose(id->type);

	/*
	 * TODO: This condition should consider more factors.
	 * "definition" should be assigned only to classes, possibly
	 * functions and namespaces, but not typenames or variables.
	 */
	if (!type.definition)
		type.definition = id;
	id->type = type;
	id->type.nested = 0;
	id->id_class = id_class;
	id->parent = table;

	/* Nested symbol table */
	if (!id->nested) {
		table =	malloc(sizeof(struct symbol_table_s));
		if (!table) {
			fprintf(stderr, "Aborting: malloc(%i) failed\n",
					sizeof(struct symbol_table_s));
			exit(-1);
		}

		symbol_table_init(table, id);
		id->nested = table;
	}

	/*
	 * This is all temporary. It makes a function's parent be
	 * the current list of template parameters (unless the list
	 * is already a parent of a parent scope for example, so
	 * we never have to look an identifier up two times in the
	 * same symbol table. In case of a redefinition of the
	 * function (or rather a definition of a function with the
	 * same name and different parameters) we will just link
	 * the tables of parameters. This is a very dirty solution.
	 * And it may have some consequences that I don't know about.
	 */
	if (template_parent && template_parent->parent == context_local()) {
		if (type.nested)
			symbol_table_link(id->nested, template_parent->nested);
		else
			id->parent = template_parent->nested;
	}

#ifndef NDEBUG
	id->line_nr = line;
#endif /* NDEBUG */

	/* Enter the new scope */
	context_open(id->nested);

	/* Give access to the parameter list in case of functions */
	if (
			id_class == function_c &&
			type.category == function_t &&
			type.function_type.parameters)
		scope_using_namespace(type.function_type.parameters);

	return type;
}

void scope_close() {
	/* TODO: free ! (if not verbose) */
	/* Temporary, will be fixed in scope_open_params() */
	struct symbol_table_s *table = context_local();
	if (table->definition && table->definition->id_class == params_c) {
		free(table->definition);
		table->definition = 0;
		symbol_table_unlink(table);
	}

	context_close();
}

void scope_done() {
	context_done();
}

struct type_s scope_define(
		const char *name, identifier_class_t id_class,
		struct type_s type) {
	struct symbol_table_s *table = context_local();
	struct identifier_s *id = 0;

	if (name)
		id = identifier_local_lookup(table, name);

	/*
	 * This is only needed when considering the point 9.8 #3 of
	 * the specification (see below). The condition should be
	 * changed when we stop using the same definition for both
	 * scopes. There should only be one identifier_s structure
	 * and a link to it in the second scope.
	 */
	if (id && id->id_class != id_class)
		id = 0;

	if (id) { /* Redefinition/Redeclaration */
		type_dispose(id->type);

		/*
		 * We leave the nested symbol table and name intact.
		 *
		 * Name because it is already correct and the
		 * symbol table may be problematic. In general if
		 * something is being legally redefined in C, it is
		 * perhaps something that doesn't have a nested
		 * table. Remember we also have to deal with
		 * incorrect code.
		 */
	} else {
		id = malloc(sizeof(struct identifier_s));
		if (!id) {
			fprintf(stderr, "Aborting: malloc(%i) failed\n",
					sizeof(struct identifier_s));
			exit(-1);
		}

		id->nested = 0;
		id->parent = 0;
		id->name = (char *) name;

		/*
		 * Only .name must be assigned before calling
		 * identifier_define().
		 */
		if (name)
			identifier_define(table, id);

		/*
		 * This represents the point 9.8 #3 of C++ specification:
		 * If class X is a local class a nested class Y may be
		 * declared in class X and later defined in the definition of
		 * class X or be later defined the same scope as the
		 * definition of class X.  A class nested within a local class
		 * is a local class.
		 *
		 * TODO: now we simply declare Y in both scopes. We should
		 * remember this fact in the identifier_s structure of
		 * this declaration and remove the obsolete declaration
		 * when the definition comes. Also remember to set the
		 * .parent field appropriately.
		 */
		if (
				name &&
				!type.definition &&
				id_class == class_c &&
				table->definition &&
				table->definition->id_class == class_c)
			identifier_define(table->definition->parent, id);
	}

	/*
	 * TODO: This condition should consider more factors.
	 * "definition" should be assigned only to classes, possibly
	 * functions and namespaces, but not typenames or variables.
	 */
	if (		!type.definition ||
			(!type.nested && name && name[0] == '%') ||
			(!type.nested && (
				type.definition->id_class == function_c ||
				type.definition->id_class == variable_c)))
		type.definition = id;
	id->type = type;
	id->id_class = id_class;
	/*
	 * This is all temporary. It makes a function's parent be
	 * the current list of template parameters (unless the list
	 * is already a parent of a parent scope for example, so
	 * we never have to look an identifier up two times in the
	 * same symbol table. In case of a redefinition of the
	 * function (or rather a definition of a function with the
	 * same name and different parameters) we will just link
	 * the tables of parameters. This is a very dirty solution.
	 * And it may have some consequences that I don't know about.
	 */
	if (template_parent && template_parent->parent == table) {
/*		if (id->parent)
			symbol_table_link(template_parent->nested,
					id->parent);*/
		id->parent = template_parent->nested;
/*		scope_reset_template();	*/
	} else
		id->parent = table;

#ifndef NDEBUG
	id->line_nr = line;
#endif /* NDEBUG */

	return type;
}

struct type_s scope_define_operator(operator_t op) {
	struct symbol_table_s *table = context_local();
	struct identifier_s *id = 0;
	char *name = operator_name(op);

	if (stmt_local)
		id = identifier_lookup(stmt_local, name);
	if (id) {
		scope_stmt_reset();
		return type_copy(id->type);
	}

	/* Note we don't insert anything to symbol tables */

	id = malloc(sizeof(struct identifier_s));
	if (!id) {
		fprintf(stderr, "Aborting: malloc(%i) failed\n",
				sizeof(struct identifier_s));
		exit(-1);
	}

	id->nested = 0;
	id->parent = stmt_local;
	id->name = name;
	id->type = type_parametrized(type_simple(void_t), 0);
	id->type.definition = id;
	id->id_class = function_t;
	if (
			!id->parent &&
			template_parent &&
			template_parent->parent == table) {
		id->parent = template_parent->nested;
/*		scope_reset_template();	*/
	}
	
	if (!id->parent)
		id->parent = table;

#ifndef NDEBUG
	id->line_nr = line;
#endif /* NDEBUG */

	scope_stmt_reset();
	return id->type;
}

struct type_s scope_define_conversion(struct type_s type) {
	struct symbol_table_s *table = context_local();
	struct identifier_s *id = 0;
	char *name, buffer[512];
	strcpy(buffer, "operator ");
	type_visual(type, buffer + strlen(buffer));
	type_dispose(type);

	name = identifier_constructor(buffer);
	if (stmt_local)
		id = identifier_lookup(stmt_local, name);
	if (id) {
		scope_stmt_reset();
		free(name);
		return id->type;
	}

	id = malloc(sizeof(struct identifier_s));
	if (!id) {
		fprintf(stderr, "Aborting: malloc(%i) failed\n",
				sizeof(struct identifier_s));
		exit(-1);
	}

	id->nested = 0;
	id->parent = stmt_local;
	id->name = name;
	id->type = type_parametrized(type_simple(void_t), 0);
	id->type.definition = id;
	id->id_class = function_t;
	if (
			!id->parent &&
			template_parent &&
			template_parent->parent == table) {
		id->parent = template_parent->nested;
/*		scope_reset_template();	*/
	}

	if (!id->parent)
		id->parent = table;

#ifndef NDEBUG
	id->line_nr = line;
#endif /* NDEBUG */

	if (stmt_local)
		identifier_define(stmt_local, id);
	else
		identifier_define(table, id);
	scope_stmt_reset();
	return id->type;
}

struct identifier_s *template_lookup(const char *key) {
	/* TODO !!! */
	if (
			template_parent &&
			template_parent->parent == context_local())
		return identifier_lookup(template_parent->nested, key);
	if (
			template_parent &&
			template_parent->parent &&
			template_parent->parent->definition &&
			template_parent->parent->definition->parent == 
			context_local())
		return identifier_lookup(
				template_parent->parent->definition->nested,
				key);
	return 0;
}

struct identifier_s *scope_lookup(const char *key) {
	struct identifier_s *id = 0;
	if (stmt_local)
		return scope_stmt_lookup(key);
/*	if (id)
		return id;	*/

	id = context_lookup(key);
	if (id)
		return id;

	id = is_gcc_builtin(key);
	if (id)
		return id;

	if (template_parent && template_parent->parent == context_local())
		id = identifier_lookup(template_parent->nested, key);
	if (id)
		return id;

	/*
	 * Identifier lookup called from inside context_lookup() will
	 * take care of "using" namespaces so we don't need to
	 * remember about it here.
	 */

	return 0;
}

void scope_using_namespace(struct symbol_table_s *table) {
	symbol_table_link(context_local(), table);
}

/*
 * TODO: the two can be one function that works like the first
 * one when name is a null.
 */
void scope_using(struct type_s type) {
	if (type.definition && type.definition->nested)
		scope_using_namespace(type.definition->nested);
	else
		/* TODO: add a link */;
}

void scope_using_id(struct type_s type, identifier_class_t id_class,
		const char *name) {
	struct symbol_table_s *table = context_local();
	struct identifier_s *id = 0;
	
	if (!name)
		return;

	id = identifier_local_lookup(table, name);

	if (id) { /* Redefinition/Redeclaration */
		type_dispose(id->type);

		id->type = type;
		id->id_class = id_class;
		/* TODO: free((char *) name); */
	} else {
		if (type.definition) {
			/* Simple check if name exists is not sufficient! */
			if (
					type.definition->name &&
					!strcmp(type.definition->name, name))
				id = type.definition;
			else {
				id = malloc(sizeof(struct identifier_s));
				if (!id) {
					fprintf(stderr,
						"Aborting: malloc(%i)"
						"failed\n",
						sizeof(struct identifier_s));
					exit(-1);
				}

				*id = *type.definition;
				id->name = (char *) name;
				id->id_class = id_class;
			}
		} else {
			id = malloc(sizeof(struct identifier_s));
			if (!id) {
				fprintf(stderr,
					"Aborting: malloc(%i) failed\n",
					sizeof(struct identifier_s));
				exit(-1);
			}

			id->id_class = id_class;
			id->name = (char *) name;
			id->nested = 0;
			id->parent = table;
			id->type = type;
		}

		identifier_define(table, id);
	}

#ifndef NDEBUG
	id->line_nr = line;
#endif /* NDEBUG */
}

struct type_s scope_this() {
	struct identifier_s *id = (struct identifier_s *)
		symbol_table_def(context_local());

	while (id && id->id_class != function_c && id->parent)
		id = (struct identifier_s *) symbol_table_def(id->parent);
	if (id && id->id_class == function_c && id->parent)
		id = (struct identifier_s *) symbol_table_def(id->parent);
	if (id && id->type.category == classy_t)
		return id->type;

	return type_simple(void_t);
}

int scope_id_info(struct identifier_s *id, void *type_ids) {
	int width = 0;
	char buffer[256];

	if (
			!type_ids &&
			id->id_class != variable_c &&
			id->id_class != function_c)
		return 1;

	if (id->name && (
				isalpha(id->name[0]) ||
				is_operator_name(id->name) ||
				id->name[0] == '_' ||
				id->name[0] == '$' ||
				id->name[0] == '%' ||
				id->name[0] == '~')) {

		if (id->id_class == function_c ||
				id->type.category == function_t) {

			if (is_operator_name(id->name)) {
				operator_visual(id->name, buffer);
				printf("%s()", buffer);
				width = strlen(buffer) + 2;
			} else if (id->name[0] ==  '%') {
				printf("%s()", id->name + 1);
				width = strlen(id->name) + 1;
			} else {
				printf("%s()", id->name);
				width = strlen(id->name) + 2;
			}

		} else {
			printf("%s", id->name);
			width = strlen(id->name);
		}
	}

	if (types) {
		if (
				id->id_class == typename_c ||
				id->id_class == variable_c ||
				id->id_class == function_c ||
				id->id_class == enum_c ||
				id->id_class == class_c) {
			while (width ++ < TYPE_COLUMN)
				printf(" ");

			if (id->id_class == template_c)
				type_show_names = 0;

			type_visual(id->type, buffer);

			type_show_names = 1;

#ifdef NDEBUG
			printf("\t%s", buffer);
#else
			printf(
					"\t%i: %s",
					id->line_nr,
					buffer);
#endif /* NDEBUG */
			if (debug && id->parent && id->parent->definition)
				printf(
						" [in %s]",
						id->parent->definition->name);
		}

		if (
				id->id_class == namespace_c ||
				id->id_class == link_c) {
			while (width ++ < TYPE_COLUMN)
				printf(" ");

			printf("\tnamespace");
		}
	}
	printf("\n");
	return 1;
}

/*
 * TODO: check for infinite loops.
 */
int scope_table_info(struct symbol_table_s *table, void *data) {
	/*
	 * Template parameters that are accessible are
	 * not shown.
	 */
	if (table->definition)
		if (table->definition->id_class == template_c)
			return 1;

#ifndef NDEBUG
	if (table->definition)
		printf("Listing in a scope called %s:\n",
				table->definition->name);
	else	
		printf("Listing in an unnamed scope:\n");
#endif /* NDEBUG */

	symbol_table_foreach(
			table,
			(table_iterator_t) scope_id_info,
			data);
	symbol_table_link_foreach(
			table,
			(table_iterator_t) scope_table_info,
			data);
	return 1;
}

/*
 * If the symbol table's underlaying structure maintains a
 * particular order of "foreach" calls for the identifiers,
 * this order is lost here, because of linked tables.
 */
void scope_completion_info(struct identifier_s *id) {
	symbol_table_foreach(
			id->nested,
			(table_iterator_t) scope_id_info,
			0);
	symbol_table_link_foreach(
			id->nested,
			(table_iterator_t) scope_table_info,
			0);
	result = 0;
}

struct type_s scope_local_lookup(struct type_s type, const char *name) {
	struct identifier_s *id = type.definition;
	type_dispose(type);

	/* TODO: stronger check for an infinite loop */
	while (id && !id->nested && id->type.definition &&
			id != id->type.definition)
		id = id->type.definition;

	if (!name || !id || !id->nested)
		return type_simple(void_t);

	/* Checking for special IDs has moved to the parser */

	id = identifier_lookup(id->nested, name);
	if (!id)
		return type_simple(void_t);

	return id->type;
}

struct symbol_table_s *scope_open_params(struct identifier_s *parent) {
	struct identifier_s *id;
	struct symbol_table_s *table = malloc(sizeof(struct symbol_table_s));
	if (!table) {
		fprintf(stderr, "Aborting: malloc(%i) failed\n",
				sizeof(struct symbol_table_s));
		exit(-1);
	}

	/*
	 * TODO: If verbose mode is on, generate an auto id and an
	 * identifier structure and put it into local context.
	 *
	 * TODO: for now only when inside a template definition.
	 *
	 * This is a bit complicated because a parameters list of
	 * a function that is a member function of a templated
	 * class, has to get access to the class'es local symbol
	 * table as well as to the templates parameters.
	 */
	if (!parent) {
		id = malloc(sizeof(struct identifier_s));
		if (!id) {
			fprintf(stderr, "Aborting: malloc(%i) failed\n",
					sizeof(struct identifier_s));
			exit(-1);
		}

		id->parent = context_local();
		id->id_class = params_c;
		id->type = type_simple(void_t);
		id->name = "<params>";
		symbol_table_ordered_init(table, id);
	} else
		symbol_table_ordered_init(table, parent);
		/* Beware, this table may have no "this" pointer. */

	if (template_parent &&
			template_parent->parent == context_local())
		symbol_table_link(table, template_parent->nested);

	context_open(table);
	return table;
}

/* TODO: enhance this */
void scope_function_info(struct type_s type) {
	char buffer[512];
	if (type.category != function_t)
		return;

	type_visual(type, buffer);
	buffer[strlen(buffer) - 1] = 0;
	printf("%s\n", buffer + 1);
	result = 0;
}

void scope_lookup_info(struct type_s type) {
	struct identifier_s *id = type.definition;
	type_dispose(type);

	/* TODO: stronger check for an infinite loop */
	while (id && !id->nested && id->type.definition &&
			id != id->type.definition)
		id = id->type.definition;

	if (id->nested)
		scope_completion_info(id);
}

void scope_enum_info(struct type_s type) {
	if (type.category == enum_t)
		scope_lookup_info(type);
}

/* TODO: check for destructors */
struct identifier_s *scope_stmt_lookup(const char *key) {
	char *ctor_name;
	struct identifier_s *id = identifier_lookup(stmt_local, key);
	if (!id) {
		/* Checking for constructors */
/*		if (stmt_local->definition &&
				!strcmp(stmt_local->definition->name, key))
			id = stmt_local->definition;*/
		ctor_name = identifier_constructor(key);
		id = identifier_lookup(stmt_local, ctor_name);
		free(ctor_name);
	}

	scope_stmt_reset();
	return id;
}

void scope_stmt_lookup_info() {
	if (stmt_local) {
		symbol_table_foreach(
				stmt_local,
				(table_iterator_t) scope_id_info,
				(void *) 1);
		symbol_table_link_foreach(
				stmt_local,
				(table_iterator_t) scope_table_info,
				(void *) 1);
		result = 0;
	}
}

inline void scope_stmt_reset() {
	stmt_local = 0;
}

void scope_stmt_global() {
	stmt_local = context_global();
}

void scope_stmt_push() {
	stmt_stack = stmt_local;
	scope_stmt_reset();
}

void scope_stmt_pop() {
	stmt_local = stmt_stack;
}

void scope_stmt_enter(struct type_s scope) {
	/* TODO: stronger check for infinite loops */
	while (scope.definition &&
			!scope.definition->nested &&
			scope.definition !=
			scope.definition->type.definition)
		scope = scope.definition->type;
	if (scope.definition && scope.definition->nested)
		stmt_local = scope.definition->nested;
	else
		if (!stmt_local)
			stmt_local = context_local();
}

/*
 * Closes the current scope (that should be a template
 * parameter list) and sets it as a parent scope for any
 * new definition that comes on. This way the template
 * parameters will be correctly recognised in templated
 * definitions.
 */
void scope_close_template() {
	struct symbol_table_s *template = context_local();
	struct identifier_s *old_template = template_parent;

	scope_close();

	template_parent = malloc(sizeof(struct identifier_s));
	if (!template_parent) {
		fprintf(stderr, "Aborting: malloc(%i) failed\n",
				sizeof(struct identifier_s));
		exit(-1);
	}

	template_parent->nested = template;
	template_parent->id_class = template_c;
	template_parent->type = type_simple(void_t);
	template_parent->name = "<template>";
	template_parent->parent = context_local();
	if (old_template && old_template->parent == context_local())
		symbol_table_link(template, old_template->nested);

	template_parent->type.definition = template_parent;
	template->definition = template_parent;

#ifndef NDEBUG
	template_parent->line_nr = line;
#endif /* NDEBUG */

	template_depth ++; /* TODO: remove */
}

/*
 * Indicates that we're not inside any templated definition
 * now and any new definitions will not be parametrised.
 */
void scope_reset_template() {
	template_parent = 0;
	template_depth --; /* TODO: remove */
}
