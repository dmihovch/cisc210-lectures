#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){

	int grades[7] = {94, 83, 97, 62, 40, 58, 76};
	//which methods will work to index through the entire array 1 character at a time?
	for(int i = 0; i<7; i++){
		//printf("%d ", grades[i]);
		//printf("%d ", *(grades + i));
		//printf("%d ", grades[sizeof(int) + i]);
		fflush(stdout);
		usleep(150000);
	}
	putchar('\n');

}
