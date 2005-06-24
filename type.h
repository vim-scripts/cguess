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

#ifndef __type_h_
# define __type_h_	1

/*
 * The basic data types.
 */
typedef enum {
	void_t,
	char_t,
	short_t,
	int_t,
	bool_t,
	float_t,
	double_t
} simple_type_t;

/*
 * Structures for properties of types specific to each category.
 *
 * Note: They do not contain the properties common to all types.
 */
typedef struct basic_type_s {
	simple_type_t type;
	int is_long;
	int is_signed;
	int is_unsigned;
	/* ... */
} basic_type_t;

/*
 * The class-style types.
 */
typedef enum {
	struct_t,
	class_t,
	union_t
} class_style_t;

typedef struct class_type_s {
	class_style_t type;
	/* scope */
} class_type_t;

/*
 * Enumerated types.
 *
 * XXX: For the particular purpose of expression completion we
 * could same as well consider enums one of the class-style types.
 * The point is these types can contain declarations inside their
 * definitions, so their symbol-table entries will each have to
 * maintain a pointer to a new, nested symbol table that defines
 * its local scope.
 *
 * Note that if it was for a different purpose, e.g. writing a
 * compiler, it would be a better idea to have each enumerator
 * defined inside the same scope that the enum type itself in the
 * symbol table, with only a pointer to the definition of the
 * type. The definition of the type would in turn contain no
 * pointers to the enumerators and wouldn't define any new scope.
 */
typedef struct enum_type_s {
	/* scope */
} enum_type_t;

/*
 * Template.
 *
 * TODO: This should be rather template_parameter_type_s
 */
typedef struct template_type_s {
	/* pointer to template definition */
	/* pointer to the template argument or argument number in the list */
} template_type_t;

/*
 * Function.
 *
 * Our data type "arithmetics" don't manage parameters. It
 * is just a link to somewhere inside the global symbol tree,
 * so make sure we don't free the tree before the type.
 */
typedef struct function_type_s {
	struct type_s *return_type;
	struct symbol_table_s *parameters;
	int ref_depth;
	int is_virtual;
	int is_const;
	/* is_pure */
	/* ... */
} function_type_t;

/*
 * The special identifier that triggers the C++ frase
 * completion mechanism. If the lexer returns this
 * identifier it means that it is the point where the
 * user wants to stop parsing and lookup possible
 * identifiers.
 */
# define SPECIAL_ID		"<special>"

/*
 * The category of data type
 */
typedef enum {
	none_t,
	basic_t,
	classy_t,
	enum_t,
	template_t,
	function_t,
} type_category_t;

/*
 * The type of reference.
 */
typedef enum {
	pointer_r,
	reference_r,
	scoped_pointer_r,
	const_pointer_r,
	const_reference_r,
	const_scoped_pointer_r,
} reference_t;

/*
 * A variable type in C++.
 *
 * We need it to represent the type of data that the variables
 * of this type hold, and not the formal type as seen by the
 * compiler (i.e. we should differ between [] arrays, pointers
 * and int's).
 */
struct type_s {
	/*
	 * Since we don't interpret the pointers (we have no
	 * way to show their values in human-readable format)
	 * we only hold the type of data that is stored in the
	 * memory cells at the end of the chain of pointers
	 * and the length of this chain.
	 */
	int ref_depth;

	type_category_t category;
	union {
		basic_type_t basic_type;
		class_type_t class_type;
		enum_type_t enum_type;
		template_type_t template_type;
		function_type_t function_type;
	};

	int is_const;
	int is_static;
	/* is_volatile */
	/* ... */

	/* type_def, name and reference counting is removed */

	struct identifier_s *definition;

	/* This is more a helper for the parser than a part of a data type */
	int nested;
};

extern int type_show_names;

/*
 * The data type arithmetics.
 *
 * TODO: many of these can be made into macros to speed things up.
 * TODO: type_function(a, b)
 */
struct type_s type_class(class_style_t type);
struct type_s type_string();
struct type_s type_enum();
struct type_s type_none();
struct type_s type_copy(struct type_s type);
struct type_s type_named(struct type_s type, const char *name);
struct type_s type_return(struct type_s func);
struct type_s type_connect(struct type_s type0, struct type_s type1);
struct type_s type_parametrized(struct type_s decl, struct symbol_table_s *p);
void type_visual(struct type_s type, char *buffer);

# ifdef NDEBUG
#  define type_dispose(_)		({ _; })
#  define type_const(x)			((x.is_const = 1), x)
#  define type_function_const(x)	((x.function_type.is_const = 1), x)
#  define type_virtual(x)		((x.function_type.is_virtual = 1), x)
#  define type_fn_reference(x)		(	\
		(x.function_type.ref_depth += x.ref_depth),	\
		(x.ref_depth = 0),	\
		x)
#  define type_signed(x)		({	\
		if (x.category == basic_t)	\
			x.basic_type.is_signed = 1;	\
		x; })
#  define type_unsigned(x)		({	\
		if (x.category == basic_t)	\
			x.basic_type.is_unsigned = 1;	\
		x; })
#  define type_reference(x)		((x.ref_depth ++), x)
#  define type_dereference(x)		((x.ref_depth --), x) /* No checking */
#  define type_simple(t)		type_simple_ ## t
extern const struct type_s type_simple_void_t;
extern const struct type_s type_simple_char_t;
extern const struct type_s type_simple_short_t;
extern const struct type_s type_simple_int_t;
extern const struct type_s type_simple_bool_t;
extern const struct type_s type_simple_float_t;
extern const struct type_s type_simple_double_t;
# else

struct type_s type_simple(simple_type_t type);
void type_dispose(struct type_s type);
struct type_s type_const(struct type_s type);
struct type_s type_signed(struct type_s type);
struct type_s type_virtual(struct type_s type);
struct type_s type_unsigned(struct type_s type);
struct type_s type_reference(struct type_s type);
struct type_s type_dereference(struct type_s type);
struct type_s type_fn_reference(struct type_s type);
struct type_s type_function_const(struct type_s type);

# endif /* NDEBUG */

#endif /* __type_h_ */
