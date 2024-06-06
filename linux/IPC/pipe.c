#include "header.h"

void main()
{
    int p[2];
    if(pipe(p) < 0)
    {
        perror("pipe");
        return;
    }
    printf("ReadEnd = p[0] = %d\nWriteEnd p[1] = %d\n",p[0],p[1]);

    if(fork() == 0)
    {
        char s[20];
        printf("In Child Before Read...\n");
        read(p[0],s,sizeof(s));
        printf("In Child Data = %s\n",s);
    }
    else
    {
        char w[20];
        printf("Enter the String...\n");
        scanf(" %s",w);
        write(p[1],w,sizeof(w));
    }
}