// 02-callstack.c
//
// Each call allocates a frame holding its own parameters and locals.
// main calls plusTen(4); plusTen calls triple(14).
//
// Run sheet: README.md, 02-callstack.c.
#include <stdio.h>

int multiplyAndSome(int n, int m) {
    int* t = (NULL);
    int multi = n * m * *t;
    return multi;
}

int plusTen(int n) {

    int x = 3;
    int p = n + 10;
    p = multiplyAndSome(p, 10);
    return p;
}

int main(void) {
    int start = 4;
    int answer = plusTen(start);
    printf("answer = %d\n", answer);
    return 0;
}
