#include"header.h"
void main()
{
	printf("hello..\n");	//1
	fork();			//2
	fork();			//3
	printf("Hai..\n");	//4
	while(1);		//5
}
/*

       		Y+3		Y		       Y+1		       Y+2
	1		1 pf(hello); T		1			1	
	2		2-------fork----------->2			2
	3<-------------	3 fork()<---------------3--------fork--------->	3
	4 pf(hai);T--->	4pf(hai);T		4pf(hai);T <------------4 pf(hai);T
	5		5			5			5
*/
