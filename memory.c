/*
 * memory.c
 *
 */
#include <stdio.h>
#include "information.h"

int main() {
	struct CharCharInt{
		char c1;
		char c2;
		int i;
	} foo;
	foo.c1 = 'a'; foo.c2 = 'b'; foo.i = 0xDEADBEEF;
	printf("&foo.c2 = %p\n", &foo.c2);
	// 000000244E5FFB49
	printf("&foo.i = %p\n", &foo.i);
	// 000000244E5FFB4C
	// The gap is two bytes, meaning there are two bytes of padding.
	show_bytes((byte_pointer) &foo, sizeof(foo));
}
