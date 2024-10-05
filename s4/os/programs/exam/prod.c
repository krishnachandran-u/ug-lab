#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    key_t key = IPC_CREAT | ftok(".", 'p');
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if (shmid < 0) {
        perror("shmid");
        return 0;
    }
    char* shm = (char*)shmat(shmid, NULL, 0); 
    if (shm == (char*)-1) {
        perror("shm");
        return 0;
    }
    printf("Producer has attached to the memory\n");
    sprintf(shm, "Hello from producer");
    printf("Producer has written to the memory\n");
    sleep(20);
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
