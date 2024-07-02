#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

#define SHM_SIZE 1024

int main() {
    key_t key = IPC_CREAT | ftok(".", 'p');
    int shmid = shmget(key, SHM_SIZE, 0666 | IPC_CREAT);
    if(shmid < 0) {
        perror("shmid");
        return 0;
    }
    char* shm = shmat(shmid, NULL, 0);
}
