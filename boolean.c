/*
 * boolean.c
 */

#import <stdio.h>

/*
 * You can reassign dereferenced values which changes the data at that location.
 */
void inplace_swap(int *x, int *y) {
	*y = *x ^ *y;
	*x = *x ^ *y;
	*y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
	int first, last;
	// 2.11: first lt last, not leq.
	for (first = 0, last = cnt - 1; first < last; first++, last--) {
		inplace_swap(&a[first], &a[last]);
	}
}

#if 0
int main(){
	int a[] = {1,2,3,4,5};
	printf("%lld\n",sizeof(a[0])); // In bytes
	reverse_array(a, 5);

	for (int i = 0; i < 5; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");

	int x = 0x87654321;
	printf("0x%x\n", x & 0xFF); // Extract LSByte
	printf("0x%x\n", x ^ ~0xFF);
	printf("0x%x", x | 0xFF);
}
#endif
