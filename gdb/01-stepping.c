// 01-stepping.c
//
// Run sheet: README.md, 01-stepping.c.
#include <stdio.h>

int add(int a, int b) {
    int sum = a + b;      // breakpoint here shows sum
    return sum;
}

int main(void) {
    int x = 5;
    int y = 7;

    int result = add(x, y);       // next: over the call;  step: into add
    int doubled = result * 2;

    printf("result = %d, doubled = %d\n", result, doubled);

    for (int i = 0; i < 3; i++) { // breakpoint here, continue fires 3 times
        printf("i = %d\n", i);
    }

    return 0;
}
