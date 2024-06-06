#include"header.h"

void main(int argc,char **argv)
{
	char a[10];
	int ret;
	if(argc !=2)
	{
		printf("Usage: ./a.out fname\n");
		return;
	}
	int fd;
	fd=open(argv[1],O_RDONLY);
	if(fd<0)
	{
		perror("open");
		return;
	}
	printf("fd=%d...\n",fd);
	bzero(a,sizeof(a));
	ret=read(fd,a,5);
	printf("ret=%d\nData= %s\n",ret,a);
}
