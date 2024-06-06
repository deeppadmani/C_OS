#include"header.h"

void main()
{
	printf("Hello...\n");
	sleep(5);
	kill(getpid(),8);
//	raise(8);
	perror("kill");
}
