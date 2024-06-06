#include"header.h"

void main()
{
	if(fork()==0)
	{
		printf("In child...%d\n",getpid());
		sleep(10);
		printf("In Child after sleep..\n");
		exit(1);
	}
	else
	{
		int r,s;
		printf("in Parent before wait %d&\n ",getpid());
		r=wait(&s);
		if(WIFEXITED(s))
			printf("Normal...%d\n",WEXITSTATUS(s));
		else if(WIFSIGNALED(s))
			printf("signal..... %d\n",WTERMSIG(s));
		while(1);
	}
}
