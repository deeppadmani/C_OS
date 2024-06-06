#include"header.h"

void main()
{
	int i;
	srand(getpid());
	for(i=0;i<5;i++)
	{
		printf("%d) %d\n",i+1,rand()%100);
	}
}

