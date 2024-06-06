#include"header.h"
struct data
{
	int n;
	char str[10];
	float f;	
};
void main(int argc,char **argv)
{
	int k;
	if(argc!=2)
	{
		printf("Usage: ./a.out fname\n");	
		return;
	}
	close(1);
	char s[]="hello";
	int i=10;
	int a[5]={1,2,3,4,5};
	char ch='a';
	struct data v={10,"abc",23.5};
	
	int fd;	
	fd=open(argv[1],O_RDONLY|O_TRUNC|O_APPEND|O_CREAT,0644);
//	write(fd,s,strlen(s));
//	write(fd,&i,sizeof(i));
//	write(fd,a,sizeof(a));
//	write(fd,&ch,sizeof(ch));
//	write(fd,&v,sizeof(struct data));
	printf("%s\n",s);
	printf("%d\n",i);
	for(k=0;k<5;k++)
		printf("%d ",a[k]);
	printf("\n");
	printf("%c\n",ch);
	printf("%d %s %f\n",v.n,v.str,v.f);
	
}
