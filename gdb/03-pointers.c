// 03-pointers.c
//
// &x produces the address of x. A pointer stores an address.
// *p reads or writes the object at the address p holds.
// Every variable has its own address; p has its own address too.
//
// Run sheet: README.md, 03-pointers.c.
#include <stdio.h>

int main(void) {
    int value = 42;
    int other = 7;
    int *p = &value;      // p holds the address of value

    printf("value      = %d\n", value);
    printf("&value     = %p   <- value lives here\n", (void *)&value);
    printf("&other     = %p   <- other lives at a different address\n", (void *)&other);

    printf("p          = %p   <- this is the value stored in p\n", (void *)p);
    printf("*p         = %d   <- *p means \"go to that address\"\n", *p);
    printf("&p         = %p   <- p itself also lives somewhere\n", (void *)&p);
    printf("sizeof(p)  = %zu bytes  (an address is %zu bytes on this machine)\n",
           sizeof(p), sizeof(void *));

    *p = 99;             

	int something = 10;

    return 0;
}
