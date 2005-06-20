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
 * CGUESS program entry point.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef VERSION
# define VERSION unknown
#endif /* VERSION */

#define V_STR(v) STR(v)
#define STR(v) #v
#define VERSION_STR V_STR(VERSION)

void *(*original_malloc)(size_t size) = malloc;
void (*original_free)(void *ptr) = free;

#include "cguess.h"
#include "parser.h"
#include "scope.h"
#include "language.h"

extern int line;

int result = 1;
int types;

void usage(const char *arg) {
	fprintf(stderr,
			"cguess - C, C++, Java(tm) syntax auto-completer\n"
			"Usage: %s [options]\n"
			"Options:\n"
			"\t-d, --debug\tdisplay errors in parsing and "
			"enquire parser's verbose\n\t\t\tmessages (only "
			"when compiled with %%debug in c++.y)\n"
			"\t-h, --help\tdisplay short usage information"
			" and exit\n"
			"\t-v, --version\tshow program version and exit\n"
			"\t-t, --types\tshow types for identifiers\n"
			"\t-l, --lang=\ttreat input as code in the specified"
			" language\n"
			"\t-c, --c\t\tequivalent to --lang=c\n"
			"\t--c++, --cpp\tequivalent to --lang=cpp"
			" (default)\n"
			"\t-j, --java\tequivalent to --lang=java (not "
			"implemented)\n",
			arg);
	exit(0);
}

void version() {
	printf("cguess-%s\n", VERSION_STR);
	exit(0);
}

int set_language(const char *arg, int argc, const char *next) {
	const char *lang = 0;
	if (arg[0] == '-' && arg[1] == '-') {
		if (arg[6] == '=')
			lang = arg + 7;
		else if (arg[6] == 0)
			lang = next;
		else
			lang = arg + 6;
	} else if (arg[0] == '-' && arg[1] == 'l') {
		if (arg[2] == '=')
			lang = arg + 3;
		else if (arg[2] == 0)
			lang = next;
		else
			lang = arg + 2;
	}

	if (!lang || (lang == next && argc <= 1) || !lang[0]) {
		fprintf(stderr, "wrong format for --lang\n");
		return 0;
	}

	if (!strcmp(lang, "c")) {
		language_set_global(c);
		return (lang == next);
	}

	if (!strcmp(lang, "c++") || !strcmp(lang, "cpp") ||
			!strcmp(lang, "cxx")) {
		language_set_global(cpp);
		return (lang == next);
	}

	if (!strcmp(lang, "java")) {
		language_set_global(java);
		return (lang == next);
	}

	fprintf(stderr, "language \"%s\" unknown\n", lang);
	return (lang == next);
}

void params_default() {
	debug = 0;
	types = 0;
	language_set_global(cpp);
}

/*
 * TODO: Add --verbose, --file-local=, --tree, --cache=
 */
int params_process(int argc, const char *argv[]) {
	int i;
	const char *arg;
	for (i = 1; i < argc; i ++) {
		arg = argv[i];

		/* Debug mode */
		if (
				!strcmp(arg, "-d") ||
				!strcmp(arg, "--debug")) {
			debug = 1;
			continue;
		}

		/* Help message */
		if (
				!strcmp(arg, "-h") ||
				!strcmp(arg, "--help")) {
			usage(*argv);
			continue;
		}

		/* Version */
		if (
				!strcmp(arg, "-v") ||
				!strcmp(arg, "--version")) {
			version();
			continue;
		}

		/* Types */
		if (
				!strcmp(arg, "-t") ||
				!strcmp(arg, "--types")) {
			types = 1;
			continue;
		}

		/* Languages */
		if (
				!strncmp(arg, "-l", 2) ||
				!strncmp(arg, "--lang", 6)) {
			i += set_language(arg, argc - i, argv[i + 1]);
			continue;
		}

		if (
				!strcmp(arg, "-c") ||
				!strcmp(arg, "--c")) {
			set_language("--lang=c", argc - i, argv[i + 1]);
			continue;
		}

		if (
				!strcmp(arg, "--c++") ||
				!strcmp(arg, "--cpp")) {
			set_language("--lang=cpp", argc - i, argv[i + 1]);
			continue;
		}

		if (
				!strcmp(arg, "-j") ||
				!strcmp(arg, "--java")) {
			set_language("--lang=java", argc - i, argv[i + 1]);
			continue;
		}

		fprintf(stderr, "\"%s\" parameter unrecognised\n", arg);
	}

	return argc;
}

int main(int argc, const char *argv[]) {
	params_default();
	params_process(argc, argv);
	parse();
	return result;
}

void error(const char *s) {
	if (debug && !eof)
		fprintf(stderr, "%i: %s\n", line, s);
	if (debug && eof)
		fprintf(stderr, "%i: EOF reached succesfully\n", line);
}

#ifndef NDEBUG

void *malloc(size_t size) {
	void *ret = original_malloc(size);
/*	fprintf(stderr, "allocated %i bytes at %i\n", size, (int) ret);	*/
	return ret;
}

void free(void *ptr) {
	original_free(ptr);
/*	fprintf(stderr, "freed at %i\n", (int) ptr);	*/
}

#endif /* NDEBUG */
