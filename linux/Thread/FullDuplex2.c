#include "header.h"
void *thread_1(void *p)
{
    char s[20];
    int fd;
    fd = open("f2",O_WRONLY);
    while(1)
    {
        scanf(" %s",s);
        write(fd,s,strlen(s)+1);
    }
}
void *thread_2(void *p)
{
    char s1[20];
    int fd;
    fd = open("f1",O_RDONLY);
    while(1)
    {
        read(fd,s1,sizeof(s1));
        printf("DATA: %s\n",s1);
    }
}

int main()
{
    void *p;
    pthread_t t1, t2;
    mkfifo("f1",0644);
    mkfifo("f2",0644);

    pthread_create(&t1,NULL,thread_1,NULL);
    pthread_create(&t2,NULL,thread_2,NULL);
    while(1);
}
//cc -pthread FullDuplex2.c -o FD2