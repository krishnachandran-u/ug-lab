#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/shm.h>
#include <sys/ipc.h>

#define SHM_SIZE 1024

int main() {
    key_t key = IPC_CREAT | ftok(".", 'p');
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmid");
        exit(1);
    }
    char* shm = shmat(shmid, NULL, 0);
    if (shm == (char*)-1) {
        perror("shmat");
        exit(1);
    }
    printf("Producer has attached to the memory\n");
    sprintf(shm, "Hello from producer");
    printf("Producer has written to the memory\n");
    sleep(20);
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    sleep(20);
}
