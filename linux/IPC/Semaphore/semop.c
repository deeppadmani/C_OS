#include "header.h"

void main(int argc, char **argv)
{
    int id,ret;
    struct sembuf v;

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
    v.sem_num = 2;
    v.sem_flg = 0;
    v.sem_op = atoi(argv[1]);
    ret = semop(id,&v,1);
    
    printf("AFTER....\n");
}