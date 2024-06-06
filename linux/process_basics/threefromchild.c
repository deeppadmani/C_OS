#include"header.h"

void main()
{
	int r;
	r=fork();
	printf("Hello pid=%d r=%d\n",getpid(),r);
	//if(fork()==0) //if(fork())-->parent
	if(r==0)		//Exclusive child code
	{
		printf("In child..y+1\n");
		if(fork()==0)
		{
			printf("child...Y+2\n");
			if(fork()==0)
			{
				printf("child...Y+3\n");	
			}
			else
			{
				printf("3rd Parent...\n");
			}
		}
		else
		{
			printf("2nd Parent..Y\n");
		
		}
	}
	else			//Exclusiv parent code
	{
		printf("1st Parent..Y\n");
	}
	while(1);
}
