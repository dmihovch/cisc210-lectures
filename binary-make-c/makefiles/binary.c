#include <stdio.h>
#include "binary.h"

unsigned int binary_to_decimal(const char *bits) {
    unsigned int value = 0;
    for (int i = 0; bits[i] != '\0'; i++) {
        value = value * 2 + (bits[i] - '0');  /* bits[i] is '0' or '1' */
    }
    return value;
}

void print_binary(unsigned int value) {
    for (int bit = BITS_PER_CHAR - 1; bit >= 0; bit--) {
        printf("%u", (value >> bit) & 1);
    }
}