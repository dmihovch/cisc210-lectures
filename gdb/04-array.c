// 04-array.c
//
// int arr[5] is 5 contiguous ints; arr decays to &arr[0].
// arr + i is the address of arr[i]; *(arr + i) equals arr[i].
//
// Run sheet: README.md, 04-array.c.
#include <stdio.h>

int main(void) {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;         // arr decays to &arr[0]

    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d   (via *(p + %d) = %d)\n",
               i, arr[i], i, *(p + i));
    }

    printf("arr     = %p\n", arr);
    printf("&arr[0] = %p\n", &arr[0]);
    printf("arr + 1 = %p\n", arr + 1);   // 4 bytes past arr on most systems

    return 0;
}
