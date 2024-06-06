#include"header.h"
void main()
{
	if(fork()==0)
	{
 		printf("In Child...%d\n",getpid());
	//	sleep(10);
	//	printf("In child after  sleep..\n");
//		while(1);
	}
	else
	{
		int s,r;
		printf("In parent Before Wait....\n");
	//	waitpid(-1,&s,0);
	//	waitpid(-1,&s,WNOHANG);
	//	waitpid(-1,0,0);
			
		waitpid(-1,&s,WUNTRACED);
		sleep(5);
		printf("In Parent...After\n");
		waitpid(-1,&s,WCONTINUED);
	}
}
