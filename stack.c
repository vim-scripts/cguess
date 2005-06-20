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

#include "stack.h"
#include "cguess.h"

/*
 * The structure for stack elements.
 */
struct stack_element_s {
	const void *data;
	struct stack_element_s *next;
};

/*
 * Initialises the stack structure before first use.
 */
void stack_init(struct stack_s *stack) {
	stack->first = 0;
}

/*
 * Puts an element at the top of the stack.
 */
void stack_push(struct stack_s *stack, const void *data) {
	struct stack_element_s *first;

	first = malloc(sizeof(struct stack_element_s));
	if (!first) {
		fprintf(stderr,
				"Aborting: malloc(%i) failed\n",
				sizeof(struct stack_element_s));
		exit(-1);
	}

	first->next = stack->first;
	first->data = data;
	stack->first = first;
}

/*
 * Takes the topmost element off from the stack.
 */
const void *stack_pop(struct stack_s *stack) {
	struct stack_element_s *first;
	const void *data;

	assert(stack->first);
	first = stack->first->next;
	data = stack->first->data;
	free(stack->first);

	stack->first = first;
	return data;
}

/*
 * Returns the stack's topmost element.
 */
const void *stack_top(struct stack_s *stack) {
	return stack->first->data;
}

/*
 * Checks whether the stack is empty.
 */
int stack_empty(struct stack_s *stack) {
	return !stack->first;
}

/*
 * Calls a given function for each element,
 * from the top down to the bottom, of the stack.
 */
void stack_foreach(struct stack_s *stack, stack_iterator_t iter, void *data) {
	struct stack_element_s *element;

	for (element = stack->first; element &&
			iter((void *) element->data, data);
			element = element->next);
}
