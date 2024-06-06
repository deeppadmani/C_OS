#include "header.h"

void main()
{
    char a[20];
    int fd;
    mkfifo("f1",0777);
    perror("mkfifo");
    printf("Before.... %d\n",getpid());
    fd = open("f1",O_WRONLY);
    printf("After.... %d\n",getpid());

    printf("Enter data...: \n");
    scanf(" %s",a);
    write(fd,a,strlen(a)+1);
    printf("done");
}