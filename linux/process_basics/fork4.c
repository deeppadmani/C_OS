#include"header.h"

void main()
{
	int r;
	printf("Hello pid=%d\n",getpid());
	r=fork();
	//if(fork()==0) //if(fork())-->parent
	if(r==0)		//Exclusive child code
	{
		printf("In child..\n");
	}
	else			//Exclusiv parent code
	{
		printf("In parent ..\n");
	}
	while(1);
}
