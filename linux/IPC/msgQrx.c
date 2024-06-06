#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <errno.h>

struct msgbuf {
    long mtype;
    char mtext[20];
};

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <type>\n", argv[0]);
        return 1;
    }

    int id;
    struct msgbuf m;
    int msg_type = atoi(argv[1]);

    id = msgget(5, IPC_CREAT | 0644);
    if (id == -1) {
        perror("msgget");
        return 1;
    }
    printf("Message Queue ID: %d\n", id);

    if (msgrcv(id, &m, sizeof(m.mtext), msg_type, IPC_NOWAIT) == -1) {
        if (errno == ENOMSG) {
            printf("No message of type %d available in the queue.\n", msg_type);
        } else {
            perror("msgrcv");
        }
        return 1;
    }

    printf("Received DATA: %s\n", m.mtext);

    return 0;
}
