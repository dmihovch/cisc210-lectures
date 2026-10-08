/* Typing   42 <ENTER>   sends three bytes: '4' '2' '\n'
 * %d eats the 4 and the 2 and stops. The newline is still waiting.
 * The next %c will read it.
 *
 * A space in the format string means "skip whitespace first".
 */
#include <stdio.h>

int main(void) {
    int  num;
    char grade;

    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Enter a letter: ");
    scanf("%c", &grade);        /* <-- delete that space and rerun */

    printf("num = %d, grade = '%c' which is byte %d\n", num, grade, grade);

    return 0;
}
