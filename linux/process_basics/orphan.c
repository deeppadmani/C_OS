#include"header.h"

void main()
{
	if(fork()==0)
	{
		printf("in Child pid=%d   ppid=%d\n",getpid(),getppid());
		sleep(2);
		printf("in Child pid=%d   ppid=%d\n",getpid(),getppid());
	}
	else
	{
		printf("in Parent pid=%d\n",getpid());
		sleep(10);
		printf("in Parent after sleep..\n");
		
	}
}
