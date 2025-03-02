#include <stdio.h>

/*
 * A word is a fixed-size unit of data that a processor can handle in a single
 * operation.
 * However, you can still address individual bytes. The processor registers
 * just don't do it that way.
 */

size_t get_pointer_size() {
	return sizeof(void *);
}

void using_pointers() {
	int int1 = 1036;
	int int2 = 8;
	// & variable = address
	// * address = variable stored at address
	// * address = val : stores value at address (indirectly)
	
	
}