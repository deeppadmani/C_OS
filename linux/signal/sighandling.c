#include"header.h"
void my_isr(int);
void main()
{
	signal(SIGINT,my_isr);
	signal(SIGQUIT,my_isr);
	while(1);	
}
void my_isr(int n)
{
	static int c=0,c1=0;
	
	printf("In ISR ...%d\n",n);
	if(n==SIGINT)
		c++;
	else if(n==SIGQUIT)
		c1++;
	if(c==4)
		signal(SIGINT,SIG_DFL);
	if(c1==3)
		signal(SIGQUIT,SIG_DFL);
}
