#include"header.h"

void main()
{
	if(fork()==0)
	{
//		printf("child..\n");
		system("ls");
	}
	else
	{
//		printf("Parent..\n");
		system("cal");
	}
}
