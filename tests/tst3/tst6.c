#include <stdio.h>

#include "parser.h"

int _main(int _argc, char *_argv[]) {
	_printf("%i\n", _parse());
	return 0;
}

void _error(const char *_s) {
	_fprintf(stderr, "%s\n", _s);
}
