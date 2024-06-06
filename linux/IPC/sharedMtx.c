#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <message>\n", argv[0]);
        return 1;
    }

    int shm_id;
    void *shm_ptr;

    // Create shared memory segment
    shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0644);
    if (shm_id == -1) {
        perror("shmget");
        return 1;
    }

    // Attach to the shared memory segment
    shm_ptr = shmat(shm_id, NULL, 0);
    if (shm_ptr == (void *)-1) {
        perror("shmat");
        return 1;
    }

    // Write the message to the shared memory
    strncpy((char *)shm_ptr, argv[1], SHM_SIZE - 1);
    ((char *)shm_ptr)[SHM_SIZE - 1] = '\0'; // Ensure null termination

    printf("Message written to shared memory: %s\n", (char *)shm_ptr);

    // Detach from the shared memory segment
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        return 1;
    }

    return 0;
}
