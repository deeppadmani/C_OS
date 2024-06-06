#include "header.h"

void main()
{
    struct flock v;
    int fd = open("test.txt", O_RDWR | O_APPEND | O_CREAT, 0644);
    char a[] = "Deep";
    int i;
    if(fd < 0)
    {
        perror("open");
        return;
    }   
    v.l_type = F_WRLCK; // LOCKTYPE
    v.l_whence = SEEK_SET;
    v.l_start = 0;
    v.l_len = 0;
    printf("BEFORE....\n");
    fcntl(fd, F_SETLKW, &v);
    printf("I AM WRITING....\n");

    for(i=0;a[i];i++)
    {
        write(fd,&a[i],1);
        sleep(1);
    }
    v.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &v);
}