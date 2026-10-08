#include <stdio.h>

int main(void) {
    unsigned char c = 'C';
    unsigned char bang = '!';

    printf("'C' is the number %d\n", c);
    printf("'!' is the number %d\n", bang);
    printf("67 printed as a character: %c\n", 67);
    printf("33 printed as a character: %c\n", 33);
    printf("67 and 33 together: %c%c\n", 67, 33);

    return 0;
}