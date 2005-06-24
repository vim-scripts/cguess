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
 * Plain binary tree with no optimization. It can be used for
 * the symbol table.
 *
 * Keys are compared lexically (no locale tricks).
 */
#include <stdlib.h>	/* malloc() */
#include <string.h>	/* strcmp() */

#include "tree.h"
#include "cguess.h"

struct tree_node_s {
	const void *data;
	const char *key;
	struct tree_node_s *children[2];
};

void tree_init(struct tree_s *tree) {
	tree->root = 0;
}

void tree_insert(struct tree_s *tree, const void *data, const char *key) {
	int r;
	struct tree_node_s **node = &tree->root;

	while (*node) {
		if ((r = strcmp(key, (*node)->key)) > 0)
			node = (*node)->children;
		else if (r < 0)
			node = (*node)->children + 1;
		else {
			/* Memory leaks here */
			(*node)->data = data;
			(*node)->key = key;
			return;
		}
	}
	
	*node = malloc(sizeof(struct tree_node_s));
	if (!*node) {
		/* Do something */
		exit(-1);
	}

	(*node)->data = data;
	(*node)->key = key;
	(*node)->children[0] = 0;
	(*node)->children[1] = 0;
}

const void *tree_find(struct tree_s *tree, const char *key) {
	int r;
	struct tree_node_s *node = tree->root;

	while (node) {
		if ((r = strcmp(key, node->key)) > 0)
			node = node->children[0];
		else if (r < 0)
			node = node->children[1];
		else
			return node->data;
	}

	return 0;
}

void tree_delete(struct tree_s *tree, const char *key) {
	int r;
	struct tree_node_s **node = &tree->root;

	while (*node) {
		if ((r = strcmp(key, (*node)->key)) > 0)
			node = (*node)->children;
		else if (r < 0)
			node = (*node)->children + 1;
		else {
			free(*node);
			*node = 0;
			/* TODO: splay */
		}
	}
}

void tree_node_foreach(struct tree_node_s *node,
		tree_iterator_t iter, void *data) {
	if (node->children[1])
		tree_node_foreach(node->children[1], iter, data);
	iter((void *) node->data, data); /* TODO: return val */
	if (node->children[0])
		tree_node_foreach(node->children[0], iter, data);
}

/*
 * Calls a given function for each node of the tree.
 *
 * No particular order for the calls is guaranteed (usually
 * it will be alphabetical or reverse alphabetical).
 */
void tree_foreach(struct tree_s *tree, tree_iterator_t iter, void *data) {
	if (tree->root)
		tree_node_foreach(tree->root, iter, data);
}

void tree_node_done(struct tree_node_s *node) {
	if (node->children[0])
		tree_node_done(node->children[0]);
	if (node->children[1])
		tree_node_done(node->children[1]);
	free(node);
}

void tree_done(struct tree_s *tree) {
	if (tree->root)
		tree_node_done(tree->root);
	tree->root = 0;
}
