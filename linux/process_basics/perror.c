#include"header.h"

void main()
{
	FILE *fp;
	fp=fopen("data","r");
	if(fp==0)
	{
		perror("fopen");
		return;
	}
	printf("file present..\n");
}
/* 








*/
