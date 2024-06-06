#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

#define SHM_KEY 0x1234
#define SHM_SIZE 1024

int main() {
    int shm_id;
    void *shm_ptr;

    // Get the shared memory segment
    shm_id = shmget(SHM_KEY, SHM_SIZE, 0644);
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

    // Read the message from the shared memory
    printf("Message read from shared memory: %s\n", (char *)shm_ptr);

    // Detach from the shared memory segment
    if (shmdt(shm_ptr) == -1) {
        perror("shmdt");
        return 1;
    }

    return 0;
}
