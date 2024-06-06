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
    if (argc != 3) {
        printf("Usage: %s <type> <message>\n", argv[0]);
        return 1;
    }

    int id;
    struct msgbuf m;
    m.mtype = atoi(argv[1]);
    strncpy(m.mtext, argv[2], sizeof(m.mtext) - 1);
    m.mtext[sizeof(m.mtext) - 1] = '\0'; // Ensure null termination

    id = msgget(5, IPC_CREAT | 0644);
    if (id == -1) {
        perror("msgget");
        return 1;
    }
    printf("Message Queue ID: %d\n", id);

    if (msgsnd(id, &m, sizeof(m.mtext), 0) == -1) {
        perror("msgsnd");
        return 1;
    }

    printf("Message sent: %s\n", m.mtext);

    return 0;
}
