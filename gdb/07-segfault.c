// 07-segfault.c
//
// p is NULL (0x0). writeValue writes through p and faults with SIGSEGV.
//
// Run sheet: README.md, 07-segfault.c.
#include <stdio.h>

void writeValue(int *p, int v) {
    *p = v;               // faults if p is NULL
}

int main(void) {
    int *p = NULL;        // BUG: should be &x
    int x = 5;

    printf("about to write through p...\n");
    writeValue(p, 10);
    printf("done, x = %d\n", x);   // unreachable

    return 0;
}
