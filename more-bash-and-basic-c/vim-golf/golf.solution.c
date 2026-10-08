/* SOLUTION - do not open until you have tried it.
 *
 * Par is 12 keystrokes. One reasonable route:
 *
 *   /incl<Enter>    jump to the include line   (or: gg then j's)
 *   I#<Esc>         insert # at the START of the line          -> 3
 *   /garbage<Enter> jump to the junk line
 *   dd              delete the whole line                      -> 2
 *   /bottles of<Enter>
 *   A;<Esc>         append ; at the END of the line            -> 3
 *
 * Fixed file below.
 */
#include <stdio.h>

int main(void) {
    int bottles = 99;

    printf("%d bottles of root beer on the wall\n", bottles);

    printf("take one down, %d left\n", bottles - 1);

    return 0;
}
