#include "header.h"
void *thread_1(void *p)
{
    while(1)
        printf("IN t1....%s\n",(char *)p);
        sleep(5);
        pthread_exit("BYE...");
}
void *thread_2(void *p)
{
    while(1)
        printf("IN t2....\n");
}

void main()
{
    void *p;
    pthread_t t1, t2;
    pthread_create(&t1,NULL,thread_1,"DEEP");
//    pthread_create(&t2,NULL,thread_2,NULL);
    printf("IN MAIN T1 = %u\n",(unsigned int)t1);
    pthread_join(t1,&p);
    printf("AFTER :-- %s\n",(char *)p);
    while(1);
}
//cc -pthread ThreadBaisc.c