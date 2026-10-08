/* A variable is a NAME for a PLACE.
 *      age   = the value stored there
 *      &age  = the address of that place
 *      %p    = print an address
 *


QUESTION: Why do you think we get a different address every time we run the program?


 */
#include <stdio.h>

int main(void) {
    int first  = 111;
    int second = 222;

    printf("first  = %d  lives at %p\n", first,  &first);
    printf("second = %d  lives at %p\n", second, &second);
    printf("an int is %lu bytes, so they sit %lu apart\n",
           sizeof(int), sizeof(int));

    return 0;
}
