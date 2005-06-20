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

/*
 * This file collects functions that manage scopes. It is
 * for determining what symbols are accessibe inside a given
 * scope and what symbols lay outside of it.
 *
 * In our understanding each block of code that allows local
 * definitions has a separate scope.
 */
#ifndef __scope_h_
# define __scope_h_	1

# include "identifier.h"
# include "operator.h"

/*
 * The name of the global scope, the one that always exists
 * (only used internally).
 */
# define PRINCIPAL_SCOPE	"global"

/*
 * Indicates if parser is currently inside a compound
 * statement (somewhere where statements are allowed). It
 * is a tip for the lexer and is set by the parser.
 */
extern int code_scope;

void scope_init();
void scope_close();
void scope_done();
void scope_using(struct type_s type);
void scope_using_namespace(struct symbol_table_s *table);
void scope_using_id(struct type_s type, identifier_class_t id_class,
		const char *name);
struct type_s scope_open(const char *name, identifier_class_t id_class,
		struct type_s type);
struct type_s scope_this();
struct type_s scope_local_lookup(struct type_s type, const char *name);
struct identifier_s *scope_lookup(const char *key);
struct identifier_s *scope_stmt_lookup(const char *key);
struct type_s scope_define(
		const char *name, identifier_class_t id_class,
		struct type_s type);
struct type_s scope_define_operator(operator_t op);
struct type_s scope_define_conversion(struct type_s type);
struct symbol_table_s *scope_open_params(struct identifier_s *parent);
int scope_id_info(struct identifier_s *id, void *type_ids);
int scope_table_info(struct symbol_table_s *table, void *data);
void scope_close_template();
void scope_reset_template();
inline void scope_stmt_reset();
void scope_stmt_global();
void scope_stmt_push();
void scope_stmt_pop();
void scope_stmt_enter(struct type_s scope);
void scope_function_info(struct type_s type);
void scope_lookup_info(struct type_s type);
void scope_enum_info(struct type_s type);
void scope_stmt_lookup_info();
void scope_completion_info(struct identifier_s *id);

#endif /* __scope_h_ */
