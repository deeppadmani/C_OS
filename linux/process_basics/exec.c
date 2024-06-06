#include"header.h"

void main()
{
	char *p[]={"ls","-l","-i",NULL};
	printf("hello...\n");
//	execl("/bin/ls","ls","-l","-i",NULL);
	execvp(p[0],p);
	printf("bye\n");
}
/*void main(int argc,char **argv,char **env)
{
	int i;
	for(i=0;env[i];i++)
	{
		printf("%s\n",env[i]);
		sleep(1);
	}
}*/
