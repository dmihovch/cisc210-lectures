/*

The return code of a program doesn't vanish, it is actually quite useful.

The programmer can see what value a program exited with, with ` echo $? `

Arguably more importantly, other programs can see the exit code, and do useful things with that info.

*/


#include <stdio.h>

int main(void) {
    printf("C program running...\n");
    return 500;
}
