#include <stdio.h>

/*
 * A word is a fixed-size unit of data that a processor can handle in a single
 * operation.
 * However, you can still address individual bytes. The processor registers
 * just don't do it that way.
 */

void using_pointers() {
	int int1 = 1036;
	int int2 = 8;
	// & variable = address
	// * address = variable stored at address
	// * address = val : stores value at address (indirectly)
	
	// Declare pointers to int
	int *ptr1;
	int *ptr2;
	int *ptr3;
	
	// Initialize pointers to the existing integers
	ptr1 = &int1;
	ptr2 = ptr1;
	ptr3 = &int2;
	
	// Change int1 using the pointers
	// For printing, %p refers to generic void * so that's the reason for the
    // cast
	*ptr1 = 151;
	printf("Should be the same: %d %d\n", int1, *ptr2);
	printf("Actual address of ptr1: %p\n", (void *) ptr1);
	printf("Actual address of ptr2: %p\n", (void *) ptr2);
	*ptr2 = 525;
	printf("Should be the same: %d %d\n", int1, *ptr2);
	printf("Actual address of ptr1: %p\n", (void *) ptr1);
	printf("Actual address of ptr2: %p\n", (void *) ptr2);
}

void pointer_arith() {
	
}