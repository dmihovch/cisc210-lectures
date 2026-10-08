/* Anything in the format string that is not a % must be typed exactly.
 * Here the user has to type the / themselves.
 *
 * try all of these!:
 *      ./43-fraction
 *      echo "3/4" | ./43-fraction
 *      ./43-fraction < input.txt
 */
#include <stdio.h>

int main(void) {
    int top, bottom;

    printf("Enter a fraction as n/m: ");
    int got = scanf("%d/%d", &top, &bottom);

    if (got != 2) {
        printf("\nI matched only %d item(s).\n", got);
        return 1;  
	}


    /* top/bottom would be INTEGER division: 3/4 would be 0.
     * Multiplying by 1.0 forces the float version. */
    printf("%d/%d is %f\n", top, bottom, top * 1.0 / bottom);
    return 0;                     /* zero: report success */
}
