/*
 * cguess - C/C++/Java(tm) auto-completion tool for VIM
 * Copyright (C) 2005 Andrzej Zaborowski <balrog@gmail.com>
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
#include <string.h>
#include <stdio.h>

#include "type.h"
#include "identifier.h"
#include "stack.h"
#include "operator.h"
#include "cguess.h"

struct type_s type_simple(simple_type_t type) {
	struct type_s ret;
	ret.ref_depth = 0;
	ret.category = basic_t;
	ret.basic_type.type = type;
	ret.basic_type.is_long = 0;
	ret.basic_type.is_signed = 0;
	ret.basic_type.is_unsigned = 0;
	ret.definition = 0;
	ret.nested = 0;
	return ret;
}

struct type_s type_class(class_style_t type) {
	struct type_s ret;
	ret.ref_depth = 0;
	ret.category = classy_t;
	ret.class_type.type = type;
	ret.definition = 0;
	ret.nested = 0;
	return ret;
}

struct type_s type_string() {
	struct type_s ret;
	ret.ref_depth = 1;
	ret.category = basic_t;
	ret.basic_type.type = char_t;
	ret.basic_type.is_long = 0;
	ret.basic_type.is_signed = 0;
	ret.basic_type.is_unsigned = 0;
	ret.definition = 0;
	ret.nested = 0;
	return ret;
}

struct type_s type_enum() {
	struct type_s ret;
	ret.ref_depth = 0;
	ret.category = enum_t;
	ret.definition = 0;
	ret.nested = 0;
	return ret;
}

/*
 * No type or type that should not be displayed.
 */
struct type_s type_none() {
	struct type_s ret;
	ret.category = none_t;
	return ret;
}

struct type_s type_signed(struct type_s type) {
	if (type.category == basic_t)
		type.basic_type.is_signed = 1;
	return type;
}

struct type_s type_unsigned(struct type_s type) {
	if (type.category == basic_t)
		type.basic_type.is_unsigned = 1;
	return type;
}

/* TODO: this should be improved */
struct type_s type_connect(struct type_s type0, struct type_s type1) {
	struct type_s ret;
	ret.ref_depth = type0.ref_depth + type1.ref_depth;
	/* This will be removed, but for now it is critical */
	ret.nested = type0.nested;

	/*
	 * TODO: instead of relying on the values of enumerators
	 * we should build a kind of two dimensional table indexed
	 * by categories and with a type in each cell.
	 */
	if (type0.category >= type1.category) {
		ret.category = type0.category;
		ret.definition = type0.definition;
		if (type0.category == type1.category &&
				!type0.definition && type1.definition)
			ret.definition = type1.definition;
		if (ret.category == classy_t)
			ret.class_type = type0.class_type;
		if (ret.category == enum_t)
			ret.enum_type = type0.enum_type;
		if (ret.category == template_t)
			ret.template_type = type0.template_type;
		if (ret.category == function_t) {
			ret.function_type = type0.function_type;
			ret.ref_depth = type0.ref_depth;
			if (ret.function_type.return_type)
				type_dispose(type1);
			else {
				ret.function_type.return_type = malloc(
						sizeof(struct type_s));
				if (!ret.function_type.return_type) {
					fprintf(stderr, "Aborting: malloc(%i)"
						"failed",
						sizeof(struct type_s));
					exit(-1);
				}
				*ret.function_type.return_type = type1;
			}
			return ret;
		}
	} else {
		ret.category = type1.category;
		ret.definition = type1.definition;
		if (ret.category == classy_t)
			ret.class_type = type1.class_type;
		if (ret.category == enum_t)
			ret.enum_type = type1.enum_type;
		if (ret.category == template_t)
			ret.template_type = type1.template_type;
		if (ret.category == function_t) {
			ret.function_type = type1.function_type;
			ret.ref_depth = type1.ref_depth;
			if (ret.function_type.return_type)
				type_dispose(type0);
			else {
				ret.function_type.return_type = malloc(
						sizeof(struct type_s));
				if (!ret.function_type.return_type) {
					fprintf(stderr, "Aborting: malloc(%i)"
						"failed",
						sizeof(struct type_s));
					exit(-1);
				}
				*ret.function_type.return_type = type0;
			}
			return ret;
		}
	}

	if (ret.category == basic_t) {
		if (type0.basic_type.type > type1.basic_type.type)
			ret.basic_type.type = type0.basic_type.type;
		else
			ret.basic_type.type = type1.basic_type.type;
		ret.basic_type.is_long =
			type0.basic_type.is_long ||
			type1.basic_type.is_long;
		ret.basic_type.is_signed =
			type0.basic_type.is_signed ||
			type1.basic_type.is_signed;
		ret.basic_type.is_unsigned =
			type0.basic_type.is_unsigned ||
			type1.basic_type.is_unsigned;
	}

	type_dispose(type0);
	type_dispose(type1);
	return ret;
}

struct type_s type_reference(struct type_s type) {
	type.ref_depth ++;
	return type;
}

struct type_s type_dereference(struct type_s type) {
	type.ref_depth --;
	return type;
}

/*
 * TODO: some of these stupid checks could be avoided if we
 * first carefully revise the whole "c++.y".
 *
 * TODO: possibly free old parameter list.
 */
struct type_s type_parametrized(struct type_s decl, struct symbol_table_s *p) {
	if (decl.category == function_t &&
			decl.function_type.return_type) {
		type_dispose(*decl.function_type.return_type);
		free(decl.function_type.return_type);
	}

	decl.category = function_t;
	decl.function_type.return_type = 0;
	decl.function_type.parameters = p;
	return decl;
}

struct type_s type_return(struct type_s func) {
	struct type_s ret;
	if (func.category == function_t)
		if (func.function_type.return_type) {
			ret = *func.function_type.return_type;
			free(func.function_type.return_type);
			func.function_type.return_type = 0;
		} else
			ret = type_simple(int_t);
	else
		return func;

	ret.nested = 0;
	/* Redundant */
	type_dispose(func);
	return ret;
}

struct type_s type_copy(struct type_s type) {
	struct type_s ret = type;

	if (ret.category == function_t &&
			ret.function_type.return_type) {
		ret.function_type.return_type = malloc(sizeof(struct type_s));
		if (!ret.function_type.return_type) {
			/* Do something */
			exit(-1);
		}

		/*
		 * TODO: check if we aren't entering an infinite loop
		 * here (well, limited by the stack size only) OR prove
		 * that's impossible.
		 */
		*ret.function_type.return_type =
			type_copy(*type.function_type.return_type);
	}

	return ret;
}

#ifndef NDEBUG
void type_dispose(struct type_s type) {
	if (type.category == function_t &&
			type.function_type.return_type) {
		/*
		 * TODO: check if we aren't entering an infinite loop
		 * here (well, limited by the stack size only) OR prove
		 * that's impossible.
		 */
		type_dispose(*type.function_type.return_type);
		free(type.function_type.return_type);
	}
}
#endif /* NDEBUG */

struct table_iter_helper_t {
	char *buf;
	int first;
};

int type_push(struct identifier_s *id,
		struct stack_s *stack) {
	stack_push(stack, id);
	return 1;
}

/*
 * We print the parameters in normal order because the list
 * iterates over elements in reverse order, but the grammar
 * for parameters is right recursive and so adds the parameters
 * to the list in reverse order as well.
 */
int type_visual_param(struct identifier_s *id,
		struct table_iter_helper_t *data) {
	char *name;

	if (id->id_class != variable_c && id->id_class != function_c)
		return 1;

	if (id->name)
		name = id->name;
	else
		name = "";

	if (data->first)
		data->first = 0;
	else
		strcat(data->buf, ", ");

	/* Don't display type for T_ELIPSIS. */
	if (*name != '.') {
		/* TODO: check for inifinite loops */
		type_visual(id->type, data->buf + strlen(data->buf));
		strcat(data->buf, " ");
	}

	strcat(data->buf, name);

	return 1;
}

void type_visual_param_list(struct symbol_table_s *table, char *buffer) {
	struct table_iter_helper_t data = { buffer, 1 };
	struct stack_s stck;
	stack_init(&stck);
	symbol_table_foreach(
			table,
			(table_iterator_t) type_push,
			&stck);
	stack_foreach(
			&stck,
			(stack_iterator_t) type_visual_param,
			&data);
}

int type_show_names = 1;

/*
 * This function is insecure, there's no buffer overflow
 * checking.
 */
void type_visual(struct type_s type, char *buffer) {
	int i;
	char *name = 0;
	strcpy(buffer, "(");

	if (type.definition)
		name = type.definition->name;
	while (type.definition &&
		type.definition != type.definition->type.definition) {
		type = type.definition->type;
		if (type.definition && type.definition->name)
			name = type.definition->name;
	}
	while (name && *name ==  '%')
		name ++;

	switch (type.category) {
	case basic_t:
		if (type_show_names && name &&
				type.definition->id_class != variable_c &&
				type.definition->id_class != function_c)
			strcat(buffer, name);
		else {
			if (type.basic_type.is_long)
				strcat(buffer, "long ");

			if (type.basic_type.is_signed)
				strcat(buffer, "signed ");

			if (type.basic_type.is_unsigned)
				strcat(buffer, "unsigned ");

			switch (type.basic_type.type) {
			case void_t:
				strcat(buffer, "void");
				break;
			case char_t:
				strcat(buffer, "char");
				break;
			case short_t:
				strcat(buffer, "short");
				break;
			case int_t:
				strcat(buffer, "int");
				break;
			case bool_t:
				strcat(buffer, "bool");
				break;
			case float_t:
				strcat(buffer, "float");
				break;
			case double_t:
				strcat(buffer, "double");
				break;
			}
		}
		if (type.ref_depth) {
			strcat(buffer, " ");
			for (i = 0; i < type.ref_depth; i ++)
				strcat(buffer, "*");
		}
		break;

	case classy_t:
		switch (type.class_type.type) {
		case struct_t:
			strcat(buffer, "struct");
			break;
		case class_t:
			strcat(buffer, "class");
			break;
		case union_t:
			strcat(buffer, "union");
			break;
		}
		if (name) {
			strcat(buffer, " ");
			strcat(buffer, name);
		}
		if (type.ref_depth) {
			strcat(buffer, " ");
			for (i = 0; i < type.ref_depth; i ++)
				strcat(buffer, "*");
		}
		break;

	case enum_t:
		strcat(buffer, "enum");
		if (name) {
			strcat(buffer, " ");
			strcat(buffer, name);
		}
		if (type.ref_depth) {
			strcat(buffer, " ");
			for (i = 0; i < type.ref_depth; i ++)
				strcat(buffer, "*");
		}
		break;

	case template_t:
		strcat(buffer, "t<>");
		if (name) {
			strcat(buffer, " ");
			strcat(buffer, name);
		}
		if (type.ref_depth) {
			strcat(buffer, " ");
			for (i = 0; i < type.ref_depth; i ++)
				strcat(buffer, "*");
		}
		break;

	case function_t:
		/*
		 * There must be a return type and the function must
		 * not be a destructor.
		 */
		if (type.function_type.return_type &&
				!(name && name[0] == '~')) {
			type_visual(*type.function_type.return_type,
					buffer + strlen(buffer));
			if (type.ref_depth || name)
				strcat(buffer, " ");
		}

		/* The chain of pointers */
		for (i = 0; i < type.ref_depth; i ++)
			strcat(buffer, "*");
		if (name) {
			if (is_operator_name(name))
				operator_visual(name, buffer + strlen(buffer));
			else
				strcat(buffer, name);
		}

		/* The list of parameters */
		strcat(buffer, " (");
		if (type.function_type.parameters)
			type_visual_param_list(
					type.function_type.parameters,
					buffer + strlen(buffer));
		else
			strcat(buffer, "void");
		strcat(buffer, ")");
		break;

	case none_t:
		break;
	}

	strcat(buffer, ")");
}
