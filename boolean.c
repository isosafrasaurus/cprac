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

int main(){
	int a[] = {1,2,3,4};
	printf("%lld",sizeof(a[0])); // In bytes
}
