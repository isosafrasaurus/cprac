#include <stdio.h>
#include <stdlib.h> 

/*
 * A word is a fixed-size unit of data that a processor can handle in a single
 * operation.
 * However, you can still address individual bytes. The processor registers
 * just don't do it that way.
 */

void using_pointers() {
	int int1 = 1036;
	int int2 = 8;
	// & variable : address (create pointer)
	// * address : variable stored at address (dereference)
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
	
	// Get value of pointer and do traditional addition
	printf("Should be the same: %p %p\n", ptrx + 3, (size_t) &x + (sizeof(x) * 3));
	
	// Convert pointer to char * so that you need to move it manually bytewise
	printf("Should be the same: %p %p\n", ptrx + 3, (char *) &x + (sizeof(x) * 3));
}

void generic_pointers() {
	// Generic pointer is defined as
	void *p;
	// You can't use pointer arithmetic here
	
	int i = 43242; char c = 'Y';
	// Both work:
	p = &i;
	p = &c;
	
	// Type cast tells compiler to change object type without actuall affecting
	// underlying bytes
	// By changing the pointer type to re-interpret data at address
	putchar(*(char *) p);
}

/*
 * Input: void *p, a pointer to anything
 * Output: char, the byte present at void *p
 */
char probe_byte(void *p) {
	return (*(char *) p);
}

/*
 * When passing arrays, the size is lost. Therefore you need to pass the size
 * manually.
 */
size_t passed_array_size(int array[]) {
	return sizeof(array);
}

size_t passed_array_pointer(int (*ptri)[]) {
	return sizeof(ptri);
}

void reverse_int_array(int array[], unsigned int length) {
	for (unsigned int i = 0; i < (length << 1); i++) {
		int t = array[i];
		array[i] = array[length - i];
		array[length - i] = t;
	}
}

/*
 * This approach does not work because static_array is defined within
 * bad_array_return's scope. Upon return, its memory can be overwritten.
 */
int* bad_array_return() {
    int static_array[3] = {1, 2, 3};
    return static_array;
}

/*
 * The recommended way to return an array is to use malloc. However the space
 * must be freed once it is used. Unlike VLA, malloc allocates on the heap,
 * so there is no risk of the memory being corrupted later.
 *
 * int* my_array = array_return(5); free(my_array);
 */
int* array_return(int size) {
    if (size <= 0) {
        return NULL;
    }

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        return NULL;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = i;
    }

    return arr;
}

void passed_array_demo() {
	int arr[10];
	int (*ptr_intarr)[10] = &arr;
	printf("Prints 40: %zu\n", sizeof(arr));
	printf("Prints 8, the pointer size: %zu\n", passed_array_size(arr));
	printf("Prints 8, the pointer size: %zu\n", passed_array_pointer(ptr_intarr));
	
	// In fact, it is the same as just casting &arr to (int *)
	printf("Print 8 equivalently: %zu\n", sizeof((int *) &arr));
}