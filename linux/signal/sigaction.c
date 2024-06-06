#include"header.h"
void my_isr(int n)
{
	printf("In ISR....%d\n",n);
}
void main()
{
	struct sigaction v;
	v.sa_handler=my_isr;
	sigemptyset(&v.sa_mask);
	v.sa_flags=0;
	sigaction(SIGINT,&v,0);
	printf("Hello...\n");
	while(1);
}
