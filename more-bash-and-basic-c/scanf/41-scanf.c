/* printf only READS, so a copy of the value is enough.
 * scanf must WRITE, so a copy is useless and it needs the address.
 * That is the entire reason for the &.
 *
 * Arrays are already addresses, so we don't need to provide a &
 *
 * scanf returns HOW MANY items it converted. 
 * Try:   Alice 19        then try:   Alice hello
 */
#include <stdio.h>

int main(void) {
    char name[10];
    int  age;

    printf("age lives at %p, and that is what I hand to scanf\n", &age);
    printf("Enter name and age: ");

    int got = scanf("%s %d", name, &age);
    /*                       ^no&  ^& */


    printf("scanf converted %d of 2 items\n", got);
    printf("name = %s, age = %d\n", name, age);

    return 0;
}
