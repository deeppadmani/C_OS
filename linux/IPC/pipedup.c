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
        close(0);
        dup(p[0]);
        close(p[1]);
        execlp("grep","grep","pts/0",NULL);
    }
    else
    {
        close(0);
        dup(p[1]);
        close(p[0]);
        execlp("ps","ps","-el",NULL);
    }
}