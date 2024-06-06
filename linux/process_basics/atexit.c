#include"header.h"
void exitfun();
void main()
{
	printf("hello..\n");	//1
	atexit(exitfun);
	printf("Hai..\n");	//4
	sleep(10);
    exit(0);
}


void exitfun()
{
    printf("In exitfun Exit...\n");
}