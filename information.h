/*
 * information.h
 *
 *  Created on: Oct 20, 2024
 *      Author: pierc
 */

#include <stdio.h>

#ifndef INFORMATION_H_
#define INFORMATION_H_

/*
 * byte_pointer is a pointer to an unsigned char. Recall that unsigned char has a
 * size of exactly 1 byte.
 *
 * This references a sequence of bytes where each byte is considered a non-negative
 * integer.
 */
typedef unsigned char *byte_pointer;
// unsigned char *byte_pointer

/*
 * size_t is a variant of unsigned int which represents the largest
 * possible size of an object on the system.
 *
 * start is a pointer that holds the address of an unsigned char. start[i]
 * dereferences the pointer and accesses the value there, which has size 1 byte.
 */
void show_bytes(byte_pointer start, size_t len) {
	int i;
	for (i = 0; i < len; i++) {
		// Print byte as hexadecimal with at least two digits.
		// 8 bits = 2 hex digits
		printf("%.2x ", start[i]);
	}
	printf("\n");
}

/*
 * Cast the location of the integer pointer to byte_pointer. Essentially,
 * treat the memory location of the integer as a sequence of bytes.
 *
 * There will be sizeof(int) bytes.
 */
void show_int(int x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
	show_bytes((byte_pointer) &x, sizeof(int));
}

void show_pointer(void *x) {
	show_bytes((byte_pointer) &x, sizeof(void *));
}

/*
 * Define an unsigned int 1. Get address of first byte (&num), then cast to
 * address of a char so system reads it as just one byte. Deference *ptr
 * to get that value (happens in *ptr == 1).
 *
 * Note: in char *ptr, * is the type specifier which indicates pointer.
 * In *ptr = 'A', * is the dereference operator, which gets the value.
 */
int is_little_endian() {
    unsigned int num = 1; // 0x00000001
    char *ptr = (char *) &num;

    if (*ptr == 1) {
        return 1;
    }
    return 0;
}

#endif /* INFORMATION_H_ */
