/*
 * array.c
 *
 */
#include <stdio.h>

/*
 * When an array is passed as a parameter, it is passed as a pointer.
 * Thus only the first cell is passed. You need to also pass the size.
 */
void foo(int array[], int size) {
	printf("%d\n", sizeof(array)); // Outputs 8, because it's a pointer
	printf("0x%x\n", array); // Outputs the actual pointer itself
	printf("%d\n", *array); // Dereference first element, 0
	printf("%d\n", sizeof(*array) * size); // Outputs 40, true size
	printf("%d\n", sizeof(array[0]) * size); // Equivalent alternative
	printf("%d\n",array[2]); // True element at index 2
	printf("%d\n",*(array + 2)); // Alternative using pointer arith
}

int main() {
	int a[10] = {0,1,2,3,4,5,6,7,8,9};
	printf("%d\n", sizeof(a)); // Outputs 40, since total a 40 bytes
	// Print each element
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
	// Running foo tests
	foo(a, 10);
}
