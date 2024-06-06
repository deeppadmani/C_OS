#include"header.h"
void my_isr(int);

void main()
{
	signal(SIGINT,SIG_IGN);
	signal(SIGQUIT,SIG_IGN);
	signal(SIGALRM,my_isr);
	alarm(10);
	while(1);	
}
void my_isr(int n)
{
	printf("In ISR ...%d\n",n);
	signal(SIGINT,SIG_DFL);
	signal(SIGQUIT,SIG_DFL);
}
