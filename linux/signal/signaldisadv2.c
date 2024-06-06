#include"header.h"
void my_isr(int n)
{
	printf("In Isr...\n");
	sleep(10);
	printf("In Isr After sleep...\n");
}
void main()
{
	signal(SIGINT,my_isr);
	printf("Hello...\n");
	while(1);
}
