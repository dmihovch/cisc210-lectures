#include <stdio.h>

int main(void) {
    printf("default:\n%d\n%d\n%d\n", 9, 376, -4096);

    printf("width 8, ones place lines up:\n");
    printf("%8d\n%8d\n%8d\n", 9, 376, -4096);

    printf("left justified: |%-8d|\n", 9);
    printf("right justified: |%+8d|\n", 9);

    printf("pi default:  %f\n",   3.14159265);
    printf("pi 2 places: %.2f\n", 3.14159265);

    printf("tabs:\ta\tb\n");
    printf("a backslash: \\ and a quote: \" and a percent: 100%%\n");

    return 0;
}
