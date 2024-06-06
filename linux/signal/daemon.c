#include "header.h"

void my_isr(int n)
{
	printf("In ISR....%d\n",n);
		wait(0);
}
void main()
{
	if(fork()==0)
	{
		sleep(5);
	}
	else
	{
		signal(SIGCHLD,my_isr);
		while(1);
	}
}
