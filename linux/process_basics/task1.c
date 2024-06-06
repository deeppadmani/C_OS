#include"header.h"

void main()
{

	int d,s;
	if(fork()==0)
	{//child
		srand(getpid());
		d=rand()%10+1;
		printf("In C1 %d sec delay\n",d);
			sleep(d);
	//	printf("C1-------------\n");
		exit(1);
	}
	else
	{//parent
		int d;
		if(fork()==0)
		{//child-2
			srand(getpid());
			d=rand()%10+1;
			printf("In C2 %d sec delay\n",d);
			sleep(d);
	//		printf("C2-------------\n");
			exit(2);
		}
		else
		{
			
			int d;
			if(fork()==0)
			{//child-3
				srand(getpid());
				d=rand()%10+1;
				printf("In C3 %d sec delay\n",d);
				sleep(d);
	//			printf("C3-------------\n");
				exit(3);
			}
			else
				printf("In parent...\n");
				while(wait(&s)!=-1)
				{
					s=s>>8;
					if(s==1)
						printf("C1 done\n");
					else if(s==2)
						printf("C2 done\n");
					else if(s==3)
						printf("C3 done\n");
				}
				printf("Done...\n");
			}
		}
}

