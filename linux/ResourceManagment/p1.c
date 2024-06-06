#include"header.h"

void main()
{
	struct rlimit v;
	printf("Pid = %d\n",getpid());
	getrlimit(RLIMIT_FSIZE,&v);
	perror("getrlimit");
	printf("Soft limit=%u\nHard link=%u\n",v.rlim_cur,v.rlim_max);
	
	v.rlim_cur=8;
//	v.rlim_cur=5;
	setrlimit(RLIMIT_FSIZE,&v);
	perror("setrlimit");
	FILE *fp=fopen("data","w");
	fwrite("DEEP PADMANI",8,1,fp);
	getrlimit(RLIMIT_STACK,&v);
	perror("getrlimit");
	printf("Soft limit=%u\nHard link=%u\n",v.rlim_cur,v.rlim_max);

}
