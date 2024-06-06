#include"header.h"

void main()
{
	int ret;
	printf("Hello...\n");
	ret=alarm(10);
	printf("ret=%d\n",ret);
	sleep(3);
	ret=alarm(2);
	printf("ret=%d\n",ret);
	printf("Hai...\n");
	while(1);
}
