/*
 * main.c
 *
 *  Created on: Mar 1, 2025
 *      Author: pierc
 */

#include <stdio.h>
#include "prelims.h"
#include "arrays.h"

/*
 * In C, re-declaration of methods with consistent return types and argument
 * types does not cause an error.
 *
 * These are already defined in stdio.h
 */
int getchar(void);
int putchar(int c);

/*
 * LB 01
 * Preliminaries.
 */
void prelims() {
	printf("%d", sum_upto(5));
	printf("%d", sum_upto_iter(5));
	putchar('A');
}

/*
 * LB 02
 * Echo characters typed at the terminal. For consistency, flush output buffer.
 * This is because of the difference between line-buffered and full buffered
 * stdout.
 */
void echo() {
	char c;
	while ((c = getchar()) != EOF) {
		putchar(c);
		fflush(stdout); // Force line-buffer
	}
	return;
}

int main() {
	sizes();
	array_alignment();
}
