#include"header.h"

void main()
{
	int ret;
	printf("Enter\n");
	ret=system("ls");
	printf("ret_ls = %d\n",ret);
	ret = system("cal;ls");
	printf("ret_cal = %d\n",ret);
	printf("Done...\n");
}

/*

q(bash) --> q(a.out)
		|
		|
	  /   \
	 /     \
	q(sh)  q(sh)
	  |       |
	q(ls)   q(cal)

*/
