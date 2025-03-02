/*
 * prelims.c
 *
 *  Created on: Mar 1, 2025
 *      Author: pierc
 */

int sum_upto(int n) {
	if (n == 0) return 0;
	else if (n > 0) return n + sum_upto(n - 1);
	else return n + sum_upto(n + 1);
}

int sum_upto_iter(int n) {
	int sum = 0;
	for (int i = n; i > 0; i--) {
		sum += i;
	}
	return sum;
}
