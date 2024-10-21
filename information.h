/*
 * information.h
 *
 *  Created on: Oct 20, 2024
 *      Author: pierc
 */

#include <stdio.h>

#ifndef INFORMATION_H_
#define INFORMATION_H_

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len);

void show_int(int x);

void show_float(float x);

void show_pointer(void *x);

int is_little_endian();

#endif /* INFORMATION_H_ */
