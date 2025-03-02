/*
 * In C, all arrays are homogeneous. Unlike Java, the size is in the definition
 */
 
#include <stdio.h>
#include <limits.h>

/* 
 * Since the result of arithmetic on size_t is size_t, it is best to use
 * size_t for all operations resulting from sizeof().
 * This avoids implicit conversion. However, if you must do a conversion,
 * then if SIZE_MAX is less than or equal to UINT_MAX, then any size_t value
 * can be represented by an unsigned int, so that's safe.
 * Else, if SIZE_MAX is less than or equal to ULONG_MAX, then you should
 * use unsigned long.
 * However, it is possible for SIZE_MAX to be even bigger than LLONG_MAX.
 *
 * The size() function contains printers for these values.
 */

void sizes() {
    printf("Size of char: %zu bytes, Range: %d to %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("Size of short: %zu bytes, Range: %d to %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("Size of int: %zu bytes, Range: %d to %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("Size of long: %zu bytes, Range: %ld to %ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("Size of long long: %zu bytes, Range: %lld to %lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);

    printf("Pointer size: %zu bytes\n", sizeof(void *));
    printf("Size of size_t: %zu bytes\n", sizeof(size_t));
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
	int array[3];
	char c2;
	int i;
	
	printf("%p ", (void *) &c1);
	printf("%p ", (void *) &array);
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
 
void array_sizes() {
	int array[10];
	
	printf("Size of array: %zu\n", sizeof(array));
	printf("Size of array[0]: %zu\n", sizeof(array[0]));
		 
	size_t array_len = sizeof(array) / sizeof(array[0]);
	
	printf("Length of array: %zu\n", array_len);
	for (size_t i = 0; i < array_len; i++) {
		printf("%p\n", (void *) &array[i]);
	}
}

/*
 * VLA size is known at compilation because it must be passed by the callee.
 * Thus, no malloc required.
 */
void variable_arrays(int n) {
	int array[n];
	printf("Size of array: %zu\n", sizeof(array));
	printf("Size of array[0]: %zu\n", sizeof(array[0]));
	
	size_t array_len = sizeof(array) / sizeof(array[0]);
	printf("Length of array: %d\n", array_len);
	for (size_t i = 0; i < 10; i++) {
		printf("%p\n", (void *) &array[i]);
	}
}

/*
 * Multidimensional arrays.
 */
void matrices() {
	int matrix[2][3];
	matrix[1][0] = 17;
	
	/*
	 * Storage is achieved in row-major order.
	 * (TOP)
	 * matrix[1][2]
	 * matrix[1][1]
	 * matrix[1][0]
	 * matrix[0][2]
	 * matrix[0][1]
	 * matrix[0][0]
	 * (BOTTOM)
	 */
}