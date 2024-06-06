#include"header.h"

void main(int argc,char **argv)
{
	struct stat v;
	if(argc != 2)
	{
		printf("Usage: ./a.out fname\n");
		return;
	}
	if(stat(argv[1],&v)<0)
	{
		perror("stat");
		return;
	}
	printf("fsize =%d\n",v.st_size);
	printf("inode=%d\n",v.st_ino);
	printf("st_mode=%d\n",v.st_mode);
	printf("st_mode=%o\n",v.st_mode&0777);
	
}
