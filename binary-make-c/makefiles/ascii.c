#include <stdio.h>
#include "ascii.h"
#include "binary.h"

void print_row(unsigned int value) {
    printf("%3u 0x%02x ", value, value);
    print_binary(value);
    printf(" %c\n", value);
}