#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main(int argc, char* argv[]) {
    key_t key = IPC_CREAT | ftok(".", 'p');
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if(shmid < 0) {
        perror("shmget");
        return 1;
    }
    char* shm = shmat(shmid, NULL, 0);
    if(shm == (char*)-1) {
        perror("shmat");
        return 1;
    }
    printf("Consumer has attached to the shared memory\n");
    printf("Consumer reads: %s\n", shm);
    printf("Consumer has read from the shared memory\n");
    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}
