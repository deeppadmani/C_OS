#include"header.h"
void main(int argc,char **argv)
{
	if(argc != 3)
	{
		printf("Usage: ./my_kill pid signal\n");
		return;
	}
	kill(atoi(argv[1]),atoi(argv[2]));
	perror("kill");
}
