#include "header.h"

void main()
{
    char s[200];
    int fd, i, f1;
    mkfifo("f1",0777);
    perror("mkfifo");
    printf("Before.... %d\n",getpid());
    fd = open("f1",O_RDONLY);
    perror("open");
    printf("After.... %d\n",getpid());

   // f1 = open("data",O_WRONLY | O_RDONLY | O_CREAT,0644);
   // bzero(s, sizeof(s));
    read(fd, s, sizeof(s));
   /* for(i = 0; s[i];i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            s[i] = s[i] - 32;
        }
    }*/
    printf("DATA: %s\n",s);
    printf("done");
}