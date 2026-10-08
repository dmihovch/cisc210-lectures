#include <stdio.h>

int main(void) {
    printf("decode this message:\n");
    printf("01000011   00100001\n\n");

    printf("dec hex binary char\n");
    for (unsigned int value = 32; value <= 126; value++) {
        printf("%3u 0x%02x ", value, value);
        for (int bit = 7; bit >= 0; bit--) {
            printf("%u", (value >> bit) & 1);
        }
        printf(" %c\n", value);
    }
    return 0;
}