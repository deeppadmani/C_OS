#include"header.h"

void main()
{
	struct sigaction v;
	int num;
	printf("Signal No. : \n");
	scanf("%d",&num);
	signal(2,SIG_IGN);
	sigaction(num,NULL,&v);
	if(v.sa_handler==SIG_DFL)
		printf("Default...\n");
	else if(v.sa_handler==SIG_IGN)
		printf("Ignore...\n");
	else
		printf("In Isr....\n");
}
