#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>

int main() {
    key_t key = IPC_CREAT | ftok(".", 'p');
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    char* shm = shmat(shmid, NULL, 0);
    printf("Consumer reading from shared memory\n");
    printf("Consumer read: %s\n", shm);
    printf("Consumer read from the shared memory\n");
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
    return 0;
}
