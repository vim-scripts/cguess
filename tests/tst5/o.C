#include <stdio.h>
#include <ext/rope>
main() {
#ifdef __STL_DEFAULT_ALLOCATOR(x)
	printf("defined\n");
#else
	printf("undefined\n");
#endif
}
