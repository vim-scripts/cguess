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
#include <assert.h>

#include "sstack.h"
#include "cguess.h"

#define STACK_MAX_ELEMENTS	1024

/*
 * Initialises the stack structure before first use.
 */
void sstack_init(struct sstack_s *stack, size_t size) {
	stack->first = malloc(STACK_MAX_ELEMENTS * size);
	if (!stack->first) {
		fprintf(stderr, "Aborting: malloc(%i) failed\n",
				STACK_MAX_ELEMENTS * size);
		exit(-1);
	}

	stack->last = stack->first;
	stack->size = size;
}

void sstack_done(struct sstack_s *stack) {
	free(stack->first); stack->first = 0;
}

/*
 * Puts an element at the top of the stack.
 */
void *sstack_push(struct sstack_s *stack) {
	void *ret = stack->last;
	/* TODO: Abort program if stack full */
	((char *) stack->last) += stack->size;
	return ret;
}

/*
 * Takes the topmost element off from the sstack.
 */
const void *sstack_pop(struct sstack_s *stack) {
	assert(stack->first != stack->last);
	((char *) stack->last) -= stack->size;
	return stack->last;
}

/*
 * Returns the stack's topmost element.
 */
const void *sstack_top(struct sstack_s *stack) {
	assert(stack->first != stack->last);
	return ((char *) stack->last - stack->size);
}

const void *sstack_topn(struct sstack_s *stack) {
	assert(stack->first != stack->last - stack->size);
	return stack->last - stack->size - stack->size;
}

/*
 * Checks whether the stack is empty.
 */
int sstack_empty(struct sstack_s *stack) {
	return (stack->first == stack->last);
}

/*
 * Calls a given function for each element,
 * from the top down to the bottom, of the sstack.
 */
void sstack_foreach(struct sstack_s *stack, sstack_iterator_t iter, void *data) {
	void *element;
	for (element = stack->last - stack->size; element >= stack->first &&
			iter(element, data); element -= stack->size);
}
