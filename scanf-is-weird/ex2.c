#include <stdio.h>


int main(void)
{
	int x = 0;
	int y = 0;
	scanf("%d",&x);
	scanf(" %d",&y);

	printf("characters: x:{%c} y:{%c}\n",x,y);
	printf("ascii: x:{%d} y:{%d}\n",x,y);
	return 0;
}
