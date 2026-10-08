#include <stdio.h>

int main(void) {
    unsigned char small = 200;
    unsigned int big = 4000000000;

    printf("unsigned char small = %hhu\n", small);
    printf("unsigned int  big   = %u\n", big);
    printf("unsigned char is %lu byte, unsigned int is %lu bytes\n",
           sizeof(unsigned char), sizeof(unsigned int));

    /* negative values wrap around */
    small = -1;
    big = -1;

    printf("small after -1: %hhu\n", small);
    printf("big after -1: %u\n", big);

    return 0;
}