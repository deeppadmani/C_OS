#include "header.h"

void main(int argc, char **argv)
{
    int id,ret, fd, i;
    struct sembuf v;
    char a[] = "Padmani\n";

    if (argc != 2) {
        printf("Usage: %s <value>\n", argv[0]);
        return;
    }
    id = semget(5,5,IPC_CREAT|0644);
    if(id<0)
    {
        perror("semget");
        return;
    }
    printf("ID: %d\n",id);

    fd = open("data",O_RDWR | O_APPEND | O_CREAT,0644);
    if(fd<0)
    {
        perror("open");
        return;
    }

    v.sem_num = 2;
    v.sem_flg = 0;
    v.sem_op = 0; //atoi(argv[1]);
    ret = semop(id,&v,1);

    semctl(id,2,SETVAL,1);
    printf("AFTER....\n");
    for(i=0;a[i];i++)
    {
        write(fd,&a[i],1);
        sleep(1);
    }
    printf("DONE....\n");
    semctl(id,2,SETVAL,0);
}