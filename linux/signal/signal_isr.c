#include"header.h"
void my_isr(int n)
{
	printf("In Isr....%d\n",n);
	alarm(2);
}
void main()
{

	printf("hello....%d\n",getpid());
//	signal(2,my_isr);
	signal(SIGALRM,my_isr);
//	pause();
	alarm(10);

	printf("Bye...\n");
	while(1);
}
