#include <stdio.h>

/* bits is a string of '0' and '1' characters */
unsigned int binary_to_decimal(const char *bits) {
    unsigned int value = 0;
    for (int i = 0; bits[i] != '\0'; i++) {
        value = value * 2 + (bits[i] - '0');
    }
    return value;
}

void print_with_commas(unsigned int value) {
    char digits[16];
    int count = 0;
    do {
        digits[count] = '0' + value % 10;
        count++;
        value /= 10;
    } while (value > 0);

    for (int i = count - 1; i >= 0; i--) {
        printf("%c", digits[i]);
        if (i > 0 && i % 3 == 0) {
            printf(",");
        }
    }
}

void print_binary(unsigned int value) {
    if (value == 0) {
        printf("0");
        return;
    }
    int highest = 31;
    while ((value >> highest) == 0) {
        highest--;
    }
    /* value >> bit moves the bit to position 0, & 1 masks off the other bits */
    for (int bit = highest; bit >= 0; bit--) {
        printf("%u", (value >> bit) & 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("usage: %s <binary strings>\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        unsigned int value = binary_to_decimal(argv[i]);
        printf("%s = ", argv[i]);
        print_with_commas(value);
        if (value <= 127) {
            printf(" = '%c'", value);
        }
        printf(" = ");
        print_binary(value);
        printf("\n");
    }

    return 0;
}