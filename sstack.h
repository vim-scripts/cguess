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

#ifndef __sstack_h_
# define __sstack_h_	1

/*
 * The static stack structure for tokens' attributes. Should be
 * faster than the normal stack.
 */
typedef struct sstack_s {
	void *first;
	void *last;
	size_t size;
} sstack_t;

/*
 * The function type for iterating over elements.
 */
typedef int (*sstack_iterator_t) (void *, void *);

/* TODO: some of this could be macros to speed things up */
void sstack_init(struct sstack_s *stack, size_t size);
void sstack_done(struct sstack_s *stack);
void *sstack_push(struct sstack_s *stack);
const void *sstack_pop(struct sstack_s *stack);
const void *sstack_top(struct sstack_s *stack);
const void *sstack_topn(struct sstack_s *stack);
int sstack_empty(struct sstack_s *stack);
void sstack_foreach(struct sstack_s *stack, sstack_iterator_t iter, void *data);

#endif /* __sstack_h_ */
