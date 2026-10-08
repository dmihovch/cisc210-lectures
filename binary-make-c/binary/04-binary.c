#include <stdio.h>

/* bits is a string of '0' and '1' characters */
unsigned int binary_to_decimal(const char *bits) {
    unsigned int value = 0;
    for (int i = 0; bits[i] != '\0'; i++) {
        value = value * 2 + (bits[i] - '0');
    }
    return value;
}

void print_binary(unsigned int value) {
    /* value >> bit moves the bit to position 0, & 1 masks off the other bits */
    for (int bit = 7; bit >= 0; bit--) {
        printf("%u", (value >> bit) & 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("usage: %s <8-bit binary strings>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        unsigned int value = binary_to_decimal(argv[i]);
        printf("%s = %u = '%c' = ", argv[i], value, value);
        print_binary(value);
        printf("\n");
    }

    return 0;
}