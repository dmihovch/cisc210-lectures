#include <stdio.h>

#define THIS_IS_A_MACRO 10

int main(void) {
    int argument = 8;

	argument += THIS_IS_A_MACRO;

    int result = getResult(argument);
    return result;
}
//and this is a comment :)

//try compiling with -E
