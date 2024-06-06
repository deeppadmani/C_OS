#include"header.h"

void main()
{
	int i=10;
	if(fork()==0)
	{
		i=getpid();
		printf("In child  = %d\n",i);
	}
	else
	{
		sleep(1);
		printf("In parent...%d\n",i);
	}
}
