/*
 * struct.c
 *
 */

#include "information.h"

struct CharCharInt{
	char c1;
	char c2;
	int i;
};

int main() {
	struct CharCharInt x;
	x.c1 = 'a'; x.c2 = 'b'; x.i = 0xDEADBEEF;
	show_bytes((byte_pointer) &x, 8);
}
