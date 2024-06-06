#include"header.h"
void main(int argc,char **argv)
{
	int i;
	if(argc !=2)
	{
		printf("Usage: ./a.out cmd,cmd,..,cmd\n");
		return;
	}
	for(i=0;argv[1][i];i++)
	{
		if(argv[1][i]==',')
		{
			argv[1][i]=';';
		}
	}
	system(argv[1]);
}

