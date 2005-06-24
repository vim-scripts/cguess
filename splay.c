/* A splay-tree datatype.  
   Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.
   Contributed by Mark Mitchell (mark@markmitchell.com).

This file is part of GNU CC.
   
GNU CC is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2, or (at your option)
any later version.

GNU CC is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.

You should have received a copy of the GNU General Public License
along with GNU CC; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  */

/* For an easily readable description of splay-trees, see:

     Lewis, Harry R. and Denenberg, Larry.  Data Structures and Their
     Algorithms.  Harper-Collins, Inc.  1991.  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "splay.h"

inline void splay_tree_delete_helper    PARAMS((splay_tree, 
						splay_tree_node));
inline void splay_tree_splay            PARAMS((splay_tree,
						splay_tree_key));
inline splay_tree_node splay_tree_splay_helper     
                                        PARAMS((splay_tree,
						splay_tree_key,
						splay_tree_node*,
						splay_tree_node*,
						splay_tree_node*));
inline void splay_tree_foreach_helper    PARAMS((splay_tree,
					        splay_tree_node,
						splay_tree_foreach_fn,
						void*));

/* Deallocate NODE (a member of SP), and all its sub-trees.  */

inline void 
splay_tree_delete_helper (sp, node)
     splay_tree sp;
     splay_tree_node node;
{
  if (!node)
    return;

  splay_tree_delete_helper (sp, node->left);
  splay_tree_delete_helper (sp, node->right);

  free ((char*) node);
}

/* Help splay SP around KEY.  PARENT and GRANDPARENT are the parent
   and grandparent, respectively, of NODE.  */

inline splay_tree_node
splay_tree_splay_helper (sp, key, node, parent, grandparent)
     splay_tree sp;
     splay_tree_key key;
     splay_tree_node *node;
     splay_tree_node *parent;
     splay_tree_node *grandparent;
{
  splay_tree_node *next;
  splay_tree_node n;
  int comparison;
  
  n = *node;

  if (!n)
    return *parent;

  comparison = strcmp (key, n->key);

  if (comparison == 0)
    /* We've found the target.  */
    next = 0;
  else if (comparison < 0)
    /* The target is to the left.  */
    next = &n->left;
  else 
    /* The target is to the right.  */
    next = &n->right;

  if (next)
    {
      /* Continue down the tree.  */
      n = splay_tree_splay_helper (sp, key, next, node, parent);

      /* The recursive call will change the place to which NODE
	 points.  */
      if (*node != n)
	return n;
    }

  if (!parent)
    /* NODE is the root.  We are done.  */
    return n;

  /* First, handle the case where there is no grandparent (i.e.,
     *PARENT is the root of the tree.)  */
  if (!grandparent) 
    {
      if (n == (*parent)->left)
	{
	  *node = n->right;
	  n->right = *parent;
	}
      else
	{
	  *node = n->left;
	  n->left = *parent;
	}
      *parent = n;
      return n;
    }

  /* Next handle the cases where both N and *PARENT are left children,
     or where both are right children.  */
  if (n == (*parent)->left && *parent == (*grandparent)->left)
    {
      splay_tree_node p = *parent;

      (*grandparent)->left = p->right;
      p->right = *grandparent;
      p->left = n->right;
      n->right = p;
      *grandparent = n;
      return n; 
    }
  else if  (n == (*parent)->right && *parent == (*grandparent)->right)
    {
      splay_tree_node p = *parent;

      (*grandparent)->right = p->left;
      p->left = *grandparent;
      p->right = n->left;
      n->left = p;
      *grandparent = n;
      return n;
    }

  /* Finally, deal with the case where N is a left child, but *PARENT
     is a right child, or vice versa.  */
  if (n == (*parent)->left) 
    {
      (*parent)->left = n->right;
      n->right = *parent;
      (*grandparent)->right = n->left;
      n->left = *grandparent;
      *grandparent = n;
      return n;
    } 
  else
    {
      (*parent)->right = n->left;
      n->left = *parent;
      (*grandparent)->left = n->right;
      n->right = *grandparent;
      *grandparent = n;
      return n;
    }
}

/* Splay SP around KEY.  */

inline void
splay_tree_splay (sp, key)
     splay_tree sp;
     splay_tree_key key;
{
  if (sp->root == 0)
    return;

  splay_tree_splay_helper (sp, key, &sp->root, 
			   /*grandparent=*/0, /*parent=*/0); 
}

/* Call FN, passing it the DATA, for every node below NODE, all of
   which are from SP, following an in-order traversal.  If FN every
   returns a non-zero value, the iteration ceases immediately, and the
   value is returned.  Otherwise, this function returns 0.  */

inline void
splay_tree_foreach_helper (sp, node, fn, data)
     splay_tree sp;
     splay_tree_node node;
     splay_tree_foreach_fn fn;
     void* data;
{
  if (node->left)
    splay_tree_foreach_helper (sp, node->left, fn, data);

  (*fn)(node, data);

  if (node->right)
    splay_tree_foreach_helper (sp, node->right, fn, data);
}


/* Insert a new node (associating KEY with DATA) into SP.  If a
   previous node with the indicated KEY exists, its data is replaced
   with the new value.  Returns the new node.  */

inline splay_tree_node
splay_tree_insert (sp, key, value)
     splay_tree sp;
     splay_tree_key key;
     splay_tree_value value;
{
  int comparison = 0;

  splay_tree_splay (sp, key);

  if (sp->root)
    comparison = strcmp (sp->root->key, key);

  if (sp->root && comparison == 0)
    {
      /* If the root of the tree already has the indicated KEY, just
	 replace the value with VALUE.  */
      sp->root->value = value;
    } 
  else 
    {
      /* Create a new node, and insert it at the root.  */
      splay_tree_node node;
      
      node = malloc (sizeof (struct splay_tree_node_s));
      node->key = key;
      node->value = value;
      
      if (!sp->root)
	node->left = node->right = 0;
      else if (comparison < 0)
	{
	  node->left = sp->root;
	  node->right = node->left->right;
	  node->left->right = 0;
	}
      else
	{
	  node->right = sp->root;
	  node->left = node->right->left;
	  node->right->left = 0;
	}

      sp->root = node;
    }

  return sp->root;
}

/* Remove KEY from SP.  It is not an error if it did not exist.  */

inline void
splay_tree_remove (sp, key)
     splay_tree sp;
     splay_tree_key key;
{
  splay_tree_splay (sp, key);

  if (sp->root && strcmp (sp->root->key, key) == 0)
    {
      splay_tree_node left, right;

      left = sp->root->left;
      right = sp->root->right;

      /* Delete the root node itself.  */
      free (sp->root);

      /* One of the children is now the root.  Doesn't matter much
	 which, so long as we preserve the properties of the tree.  */
      if (left)
	{
	  sp->root = left;

	  /* If there was a right child as well, hang it off the 
	     right-most leaf of the left child.  */
	  if (right)
	    {
	      while (left->right)
		left = left->right;
	      left->right = right;
	    }
	}
      else
	sp->root = right;
    }
}

/* Lookup KEY in SP, returning VALUE if present, and NULL 
   otherwise.  */

inline splay_tree_node
splay_tree_lookup (sp, key)
     splay_tree sp;
     splay_tree_key key;
{
  splay_tree_splay (sp, key);

  if (sp->root && strcmp (sp->root->key, key) == 0)
    return sp->root;
  else
    return 0;
}

/* Call FN, passing it the DATA, for every node in SP, following an
   in-order traversal.  If FN every returns a non-zero value, the
   iteration ceases immediately, and the value is returned.
   Otherwise, this function returns 0.  */

inline void
splay_tree_foreach (sp, fn, data)
     splay_tree sp;
     splay_tree_foreach_fn fn;
     void *data;
{
  splay_tree_foreach_helper (sp, sp->root, fn, data);
}

void splay_init(struct splay_s *splay) {
	splay->root = 0;
}

void splay_insert(struct splay_s *splay, const void *data, const char *key) {
	splay_tree_insert(splay, (char *) key, (void *) data);
}

const void *splay_find(struct splay_s *splay, const char *key) {
	splay_tree_node n;
	if ((n = splay_tree_lookup(splay, (char *) key)))
		return n->value;
	return 0;
}

void splay_delete(struct splay_s *splay, const char *key) {
	splay_tree_remove(splay, (char *) key);
}

struct splay_iter_helper_s {
	splay_iterator_t func;
	void *data;
};

int splay_iter_helper(splay_tree_node node, struct splay_iter_helper_s *data) {
	return !data->func(node->value, data->data);
}

void splay_foreach(struct splay_s *splay, splay_iterator_t iter, void *data) {
	struct splay_iter_helper_s hdata = { iter, data };
	splay_tree_foreach(
			splay,
			(splay_tree_foreach_fn) splay_iter_helper,
			&hdata);
}

void splay_done(struct splay_s *splay) {
	splay_tree_delete_helper (splay, splay->root);
}
