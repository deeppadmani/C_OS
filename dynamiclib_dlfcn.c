
#include "header.h"
#include<dlfcn.h>

int main()
{
    int i=10,j=20,k,op;
	void *handler;
	int(*p)(int,int);
	printf("Enter op..\n");
	scanf("%d",&op);
    if(op==1)
	{
		handler=dlopen("./libmath.so",RTLD_LAZY);
		if(handler==0)
		{
			printf("%s\n",dlerror());
			return;
		}
		p=dlsym(handler,"sum");
		if(p==0)
		{
			printf("%s\n",dlerror());
			return;
		}
		k=(*p)(i,j);
		printf("%d\n",k);
		dlclose(handler);
	}
	else if(op==2)
	{
		handler=dlopen("./libmath.so",RTLD_LAZY);
		if(handler==0)
		{
			printf("%s\n",dlerror());
			return;
		}
		p=dlsym(handler,"mul");
		if(p==0)
		{
			printf("%s\n",dlerror());
			return;
		}
		k=(*p)(i,j);
		printf("%d\n",k);
		dlclose(handler);
	}
	else
	{
		printf("Invalid Option..\n");
	}
	while(1);
}
