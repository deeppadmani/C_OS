#include"header.h"

void main()
{
	int r=1;
	printf("Hello Pid=%d\n",getpid());
	r=fork();
	printf("Hai pid=%d  r=%d\n",getpid(),r);
	while(1);	
}


/*
1
2
3
4
5
6	pf(Hello pid)
7 	pf(hai)   fork---------------> pf(Hai)
8					
9

*/