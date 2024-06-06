#include"header.h"

void my_isr(int);

void main()
{
	signal(SIGHUP,SIG_IGN);
	printf("pid=%d\n",getpid());
	while(1);
}

