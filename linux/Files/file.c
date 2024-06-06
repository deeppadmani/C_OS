#include"header.h"

void main(int argc,char **argv)
{
	struct stat v,v1;
	if(argc !=3)
	{
		printf("Usage :./a.out fname fname\n");
		return;
	}
	if(stat(argv[1],&v)<0)
	{
		perror("stat");
		return;
	}
	if(stat(argv[2],&v1)<0)
	{
		perror("stat");
		return;
	}
	if(v.st_ino==v1.st_ino)
	{
		lstat(argv[1],&v);
		lstat(argv[2],&v);
		if(v.st_ino==v1.st_ino)
		{
			printf("Hard Link..\n");
		}
		else
		{
			printf("Soft link...\n");
		}
	}
	else
	{
		printf("No links...\n");
	}

}
