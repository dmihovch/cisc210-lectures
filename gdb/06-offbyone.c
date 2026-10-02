// 06-offbyone.c
//
// sumArray loops i = 0..n inclusive. n is 4, so i reaches 4 and arr[4] is read.
// arr has 4 elements (indices 0..3); arr[4] is outside the array.
//
// Run sheet: README.md, 06-offbyone.c.
#include <stdio.h>

int sumArray(int *arr, int n) {
    int total = 0;
    for (int i = 0; i <= n; i++) {   // BUG: should be i < n
        total += arr[i];
    }
    return total;
}

int main(void) {
    int nums[4] = {3, 6, 9, 12};
    int total = sumArray(nums, 4);   // 4 elements, valid indices 0..3
    printf("total = %d   (expected 30)\n", total);
    return 0;
}
