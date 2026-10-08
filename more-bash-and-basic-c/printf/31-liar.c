#include <stdio.h>

int main(void) {
    printf("1. the truth:          %d\n", 42);
    printf("2. int read as %%f:     %f\n", 42); //undefined behavior, but only prints 0.00000?
    printf("3. float read as %%d:   %d\n", 42.42); //undefined behavior again!
    printf("4. two format specifiers, only  one arg: %d and %d\n", 42);
    printf("5. 300 squeezed into a char (0-255): %c  <- 300-256 = byte 44\n", 300);

    return 0;
}
