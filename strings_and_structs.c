#include <stdio.h>

void dump_string_to_out(char *str) {
	while (*str != '\0') {
		putchar(*str);
		// Use pointer arithmetic
		str++;
	}
	fflush(stdout);
}

 