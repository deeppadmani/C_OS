#include"header.h"

void main()
{
	if(fork()==0)
	{
		printf("In child....%d\n",getpid());
		sleep(10);
		printf("In child after sleep...\n");
		exit(1);
	}
	else
	{
		int s,r;
		printf("In parent...\n");
		r=wait(&s);
		printf("In parent after sleep..%d,    r=%d\n",s,r);
		r=wait(0);
		printf("r=%d\n",r);
		while(1);
	}
}

/*
	
	0 0 0 0  0 0 0 1 | 0 0 0 0  0 0 0 0	//normal termination
s=	exit status(0-255)
	         Ex:-exit(1) //s=256 check in above program

	
	0 0 0 0  0 0 0 0 | f| x x x  x x x x       //killed by signal
s= 			   ^|< transmition >
			   |    signal(!=0)
			core dump
			  flag 	


         <---stop signal--->|<-----0x7F----->     //stoped by signal
 s=   

 s =   0xFFFF //countinue signal

*/
