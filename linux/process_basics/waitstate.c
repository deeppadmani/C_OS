#include"header.h"
void main()
{
	int num;
	printf("pid=%d\n",getpid());
	printf("Wait for scanning data...\n");
	scanf("%d",&num);
	while(1);
}

/*

			|-----|
			|     V
Ready-->Run-->Wait-->Ready-->Run
		|	^     |
		v	|_____|
	     for scan
*/
