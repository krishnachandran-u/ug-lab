#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    key_t key = IPC_CREAT | ftok(".", 'p');
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if(shmid < 0) {
        perror("shmget");
        exit(1);
    }
    char *shm = (char*) shmat(shmid, NULL, 0);
    if(shm == (char*) -1) {
        perror("shmat");
        exit(1);
    }
    printf("Consumer has attached the shared memory...\n");
    printf("Consumer read: %s\n", shm);
    printf("Consumer has read from the shared memory: %s\n", shm);
    sleep(5);
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
