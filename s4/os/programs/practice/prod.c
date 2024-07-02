#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main(int argc, char* argv[]) {
    key_t key = IPC_CREAT | ftok(".", 'p');
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if(shmid < 0) {
        perror("shmget");
        return 0;
    }
    char* shm = shmat(shmid, NULL, 0);
    if(shm == (char*)-1) {
        perror("shmat");
        return 0;
    }
    printf("Producer has attached to the memory\n");
    sprintf(shm, "Helloo from producer");
    printf("Producer has written to the memory\n");
    sleep(20);
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
