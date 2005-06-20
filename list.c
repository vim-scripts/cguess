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
 * A linked list that can be used for implementing the symbol
 * table, but will not be too efficient.
 */
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "stack.h"
#include "cguess.h"

struct list_element_s {
	const void *data;
	const char *key;
	struct list_element_s *next;
};

void list_init(struct list_s *list) {
	list->head = 0;
}

void list_insert(struct list_s *list, const void *data, const char *key) {
	struct list_element_s *element =
		malloc(sizeof(struct list_element_s));

	if (!element) {
		/* Do something */
		exit(-1);
	}

	element->data = data;
	element->key = key;
	element->next = list->head;
	list->head = element;
}

const void *list_find(struct list_s *list, const char *key) {
	struct list_element_s *element;

	for (element = list->head; element; element = element->next)
		if (!strcmp(element->key, key))
			return element->data;

	return 0;
}

void list_delete(struct list_s *list, const char *key) {
	struct list_element_s *element, *t;

	if (list->head && !strcmp(list->head->key, key)) {
		t = list->head->next;
		free(list->head);
		list->head = t;
		return;
	} else
		if (!list->head)
			return;

	for (element = list->head; element->next; element = element->next)
		if (!strcmp(element->next->key, key)) {
			t = element->next->next;
			free(element->next);
			element->next = t;
			return;
		}
}

/*
 * Calls a given function for each element of the list.
 */
void list_foreach(struct list_s *list, list_iterator_t iter, void *data) {
	struct list_element_s *element;

	for (element = list->head; element &&
			iter((void *) element->data, data);
			element = element->next);
}

void list_done(struct list_s *list) {
	struct list_element_s *element;

	for (element = list->head; element; element = list->head) {
		list->head = element->next;
		free(element);
	}
	list->head = 0;
}
