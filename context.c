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
#include <assert.h>

#include "context.h"
#include "stack.h"
#include "cguess.h"

/*
 * The stack is global for the parser.
 *
 * Whoever needs it reentrant will have to modify this.
 *
 * TODO: use sstacks
 */
static struct stack_s stack;

const struct symbol_table_s *global;

void context_init() {
	stack_init(&stack);
	global = 0;
}

void context_open(const struct symbol_table_s *context) {
	stack_push(&stack, context);
	if (!global)
		global = context;
}

void context_close() {
	assert(!stack_empty(&stack));
	stack_pop(&stack);
}

void context_done() {
	while (!stack_empty(&stack))
		stack_pop(&stack);
}

struct symbol_table_s *context_local() {
	/*assert(!stack_empty(&stack));*/
	if (stack_empty(&stack))
		return 0;

	return (struct symbol_table_s *) stack_top(&stack);
}

struct symbol_table_s *context_global() {
	return (struct symbol_table_s *) global;
}

int prt(struct symbol_table_s *ctx, void *data) {
	if (symbol_table_def(ctx))
		printf("::%s", ((struct identifier_s *)
					symbol_table_def(ctx))->name);
	else
		printf("::<0>");
	return 1;
}

int context_print() {
	stack_foreach(&stack, (stack_iterator_t) prt, 0);
	printf("\n");
	return 0;
}

struct search_data_s {
	struct identifier_s *result;
	const char *key;
};

int context_search(struct symbol_table_s *ctx, struct search_data_s *data) {
	data->result = identifier_lookup(ctx, data->key);
	return !data->result;
}

/*
 * This method of looking up identifiers worked for C, but it
 * is not sufficient for C++, so it is no longer used.
 */
struct identifier_s *context_c_lookup(const char *key) {
	struct search_data_s data = { 0, key };
	stack_foreach(&stack, (stack_iterator_t) context_search, &data);

	return data.result;
}

struct identifier_s *context_lookup(const char *key) {
	struct symbol_table_s *table; 
	struct identifier_s *result;
	assert(!stack_empty(&stack));
	table = (struct symbol_table_s *) stack_top(&stack);

	while (table) {
		result = identifier_lookup(table, key);
		if (result)
			return result;

		/* assert(table->definition); */
		if (table->definition)
			table = ((struct identifier_s *) table->definition)->
				parent;
		else /* TODO: */
			return context_c_lookup(key);
	}

	return 0;
}

int n, i, show(struct symbol_table_s *ctx, int in);

int count(void *ctx, void *data) {
	n ++;
	return 1;
}

int show0(void *ctx, void *data) {
	for (i = 0; i < (int) data; i ++)
		printf("  ");
	printf("+%s\n", ((struct identifier_s *) ctx)->name);
	if (((struct identifier_s *) ctx)->nested)
		show(((struct identifier_s *) ctx)->nested, (int) data + 1);
	return 1;
}

int show1(void *ctx, void *data) {
	n --;
	if (!n)
		show((struct symbol_table_s *) ctx, 0);
	return 1;
}

int show(struct symbol_table_s *ctx, int in) {
	STRUCT_CALL(foreach, &ctx->table, show0, (void *) in);
	return 1;
}

int context_show_tree() {
	n = 0;
	printf("global\n");
	stack_foreach(&stack, count, 0);
	stack_foreach(&stack, show1, 0);
	return 0;
}
