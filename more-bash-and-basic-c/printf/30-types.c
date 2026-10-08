
/*
   types just specify how many bytes, and how to interpret them
*/

#include <stdio.h>

int main(void) {
    char  c = 65;
    int   i = 65;
    float f = 65;


    printf("char  is %lu byte,  holds %c\n",  sizeof(char),  c);
    printf("int   is %lu bytes, holds %d\n",  sizeof(int),   i);
    printf("float is %lu bytes, holds %f\n",  sizeof(float), f);


    printf("\n65 printed as a character: %c\n", 65);
    printf("'A' printed as a number:   %d\n", 'A');
    printf("'A' + 1 is %c\n", 'A' + 1);
    printf("'\\n' is really the number %d\n", '\n');
    printf("'0' is really the number %d  <- not zero!\n", '0');

    return 0;
}
