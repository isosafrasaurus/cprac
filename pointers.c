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

void pointer_abuse() {
	int int1 = 153;
	int *ptr_to_int1 = &int1;
	
	// get actual value of ptr_to_int1 out.
	size_t ptrval1 = (size_t) ptr_to_int1;
	unsigned long long ptrval2 = (unsigned long long) ptr_to_int1;
	printf("Value of ptrval1: %zu\n", ptrval1);
	printf("Value of ptrval1 in hex: %llX\n", ptrval2);
	printf("Value of ptrval1 officially: %p\n", ptr_to_int1);
}

void pointer_arith() {
	int intarray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	char chararray[10] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74};
	
	int (*ptri)[10] = &intarray;
	char (*ptrc)[10] = &chararray;
	printf("Pointer of intarray: %p\n", ptri);
	printf("Pointer of chararray: %p\n", ptrc);
	
	int *ptri0 = &intarray[0];
	char *ptrc0 = &chararray[0];
	printf("First of intarray: %p\n", ptri0);
	printf("First of chararray: %p\n", ptrc0);
	
	printf("Should be the same: %p %p\n", *(ptri0 + 1), intarray[1]);
	printf("Should be the same: %c %c\n", *(ptrc0 + 1), chararray[1]);
	
	// What happens if you add to an array pointer?
	printf("%p\n", ptri + 1);
	// This outputs 0x000000F9C67FF8E8
	// Difference 0x000000F9C67FF8E8 - 0x000000F9C67FF8C0 = 40 bytes, sizeof(intarray)
	
	// In other words, ptr_to_thing + n = &thing + (sizeof(thing) * n)
	int x = 0;
	int *ptrx = &x;
	printf("Pointer to x: %p\n", ptrx);
	printf("Should be the same: %p %p\n", ptrx + 3, (size_t) &x + (sizeof(x) * 3));
}