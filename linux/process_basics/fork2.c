#include"header.h"
void main()
{
	printf("hello..\n");	//1
	fork();			//2
	fork();			//3
	fork();		 	//4
	printf("Hai..\n");	//5
	while(1);		//6
}

