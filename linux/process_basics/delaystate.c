#include"header.h"
void main()
{
	printf("pid=%d\n",getpid());
	printf("Delay of 10s\n");
	sleep(10);
	printf("Done\n");
	while(1);
}

/*

						|-----|
						|     V
Ready-->Run-->Delay-->Ready-->Run
				|		^     |
				v		|_____|
			sleep(10)
*/
