#include"header.h"

void my_isr(int n)
{
	printf("In ISR....\n");
	wait(0);
}
void main()
{
	if(fork()==0)
	{
//		sleep(5);
		printf("In Child....%d\n",getpid());
		while(1);
	}
	else
	{
		struct sigaction v;
		v.sa_handler=my_isr;
		sigemptyset(&v.sa_mask);
//		v.sa_flags=0;
		v.sa_flags=SA_NOCLDSTOP;
//		v.sa_flags=SA_NOCLDWAIT;
		sigaction(17,&v,NULL);
		while(1);
	}
}
