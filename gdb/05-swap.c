// 05-swap.c
//
// swap_wrong takes int parameters: it receives copies and leaves main unchanged.
// swap_right takes int * parameters: it writes through the caller's addresses.
//
// Run sheet: README.md, 05-swap.c.
#include <stdio.h>

// a and b are copies of the caller's values.
void swap_wrong(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// a and b hold the addresses of the caller's variables.
void swap_right(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void) {
    int x = 1, y = 2;

    swap_wrong(x, y);
    printf("after swap_wrong: x = %d, y = %d\n", x, y);// <-- unchanged

    swap_right(&x, &y);
    printf("after swap_right: x = %d, y = %d\n", x, y); // <-- changed

    return 0;
}
