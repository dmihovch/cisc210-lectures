#include <stdio.h>


int main(void)
{
	char x = 0;
	char y = 0;
	scanf("%c",&x);
	scanf("%c",&y);

	printf("characters: x:{%c} y:{%c}\n",x,y);
	printf("ascii: x:{%d} y:{%d}\n",x,y);
	return 0;
}
