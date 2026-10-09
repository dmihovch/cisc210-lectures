#include <stdio.h>

int main(void) {
    unsigned char c = 'C';
    unsigned char bang = '!';

    printf("01000011 = %d = '%c'\n", c, c);
    printf("00100001 = %d = '%c'\n", bang, bang);
	printf("The secret message was...\n             C!\nSince everybody is so excited to program in C, right!?\n");

    return 0;
}
