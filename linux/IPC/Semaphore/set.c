#include "header.h"

void main(int argc, char **argv)
{
    int id,ret;
    if (argc != 2) {
        printf("Usage: %s <SemNum>\n", argv[0]);
        return;
    }
    id = semget(5,5,IPC_CREAT|0644);
    if(id<0)
    {
        perror("semget");
        return;
    }
    printf("ID: %d\n",id);
    ret = semctl(id,atoi(argv[1]),GETVAL);
    printf("RET : %d\n",ret);
    

}