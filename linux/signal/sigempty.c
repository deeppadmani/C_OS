#include"header.h"
void my_isr(int n)
{
	printf("In isr....\n");
	sleep(20);
	printf("after sleep...\n");
}
void main()
{
	struct sigaction v;
	v.sa_handler=my_isr;
	sigemptyset(&v.sa_mask);
	sigaddset(&v.sa_mask,3);
	v.sa_flags=0;
	sigaction(2,&v,0);
	printf("Hello....pid=%d\n",getpid());
	while(1);







}
