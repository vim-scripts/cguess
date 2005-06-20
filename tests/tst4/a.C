#include <stdio.h>

char a = 'a';

namespace {
	char a = 'b';
	void b() {
		printf("%c %c\n", ::a, a);
	}
}

int main(int argc, char *argv[]) {
	b();
	printf("%c %c\n", ::a, a);
	return 0;
}
