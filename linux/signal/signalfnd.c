#include"header.h"

void main()
{
	void (*p)(int);
	int num;
	printf("Enter the num,...\n");
	scanf("%d",&num);

	signal(2,SIG_IGN);
	p=signal(num,SIG_IGN);
	signal(num,p);

	if(p==SIG_DFL)
	{
		printf("Default...\n");
	}
	else if(p==SIG_IGN)
	{
		printf("Ignore...\n");
	}
	else
	{
		printf("my_isr...\n");
	}
}
