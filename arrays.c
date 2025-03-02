/*
 * In C, all arrays are homogeneous. Unlike Java, the size is in the definition
 */
 
#include <stdio.h>
#include <limits.h>

void sizes() {
    printf("Word size: %zu bytes\n", sizeof(void *));

    printf("Size of char: %zu bytes, Range: %d to %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("Size of short: %zu bytes, Range: %d to %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("Size of int: %zu bytes, Range: %d to %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("Size of long: %zu bytes, Range: %ld to %ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("Size of long long: %zu bytes, Range: %lld to %lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);

    printf("Size of size_t: %zu bytes\n", sizeof(size_t));

    return;
}
 
void array_demo() {
	int array[10];
	int b;
	
	array[0] = 3;
	array[9] = 4;
	array[10] = -1; // Allowed but will corrupt
	array[-1] = -1; // Not the last element. Allowed but will corrupt.
}

/*
 * Say the element stored contains s bytes. Then an array of m data values is
 * a sequence of m * s bytes. We index by 0 at s * 0, 1 at s * 1, etc.
 * The last index is m - 1 corresponding to (m - 1) * s.
 * s is known by the compiler, but m is often not. It must be saved by the
 * programmer.
 */
 
void array_alignment() {
	char c1;
	int arr[3];
	char c2;
	int i;
	
	printf("%p ", (void *) &c1);
	printf("%p ", (void *) &arr);
	printf("%p ", (void *) &c2);
	printf("%p ", (void *) &i);
}

/*
 * The above produced the output
 * 00000017B0BFFA8F 00000017B0BFFA80 00000017B0BFFA7F 00000017B0BFFA78
 * Call attention to the last four digits of the address
 * FA8F FA80 FA7F FA78
 * 
 * The addresses grow down as they are placed onto the stack.
 * Notice that the address of the integer array (arr) is 0xFA80. This address
 * is divisible by 4 (0x80 = 128), which satisfies the typical alignment.
 *
 * Similarly, the integer i is at FA78 which is also aligned.
 * The gap between c1 (at 0xFA8F) and arr (at 0xFA80) indicates that padding
 * has been inserted by the compiler.
 */