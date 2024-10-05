#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/shm.h>

#define CNT 5

sem_t mutex;
sem_t forks[CNT];

void thinking(int phil_num) {
    printf("philosopher %d is thinking...", phil_num);
    return;
}

void pick_up_forks(int phil_num) {
    sem_wait(&mutex);

    sem_wait(&forks[phil_num]);

    int lt_nbr = (phil_num - 1 + CNT) % CNT;
    int rt_nbr = (phil_num + 1) % CNT;

    if (phil_num % 2 == 0) {
        sem_wait(&forks[lt_nbr]);
    }
    else {
        sem_wait(&forks[rt_nbr]);
    }

    printf("philosopher %d has picked up forks %d and %d", phil_num, phil_num, phil_num % 2 == 0? lt_nbr: rt_nbr); 

    sem_post(&mutex);
    return;
}

void eating(int phil_num) {
    printf("philosopher %d is eating...", phil_num);
    return;
}

void put_down_forks(int phil_num) {
    sem_post(&forks[phil_num]);

    int lt_nbr = (phil_num - 1 + CNT) % CNT;
    int rt_nbr = (phil_num + 1) % CNT;
    
    if (phil_num % 2 == 0) {
        sem_post(&forks[lt_nbr]);
    }
    else {
        sem_post(&forks[rt_nbr]);
    }

    printf("philosopher %d has put down forks %d and %d", phil_num, phil_num, phil_num % 2 == 0? lt_nbr: rt_nbr); 
    return;
}

void* philosopher(void *arg) {
    int id = *(int*)arg;

    thinking(id);    
    pick_up_forks(id);    
    eating(id);    
    put_down_forks(id);
    return NULL;  
}

int main() {
    pthread_t threads[CNT];
    sem_init(&mutex, 0, 1); 

    for (int i = 0; i < CNT; i++) {
        sem_init(&forks[i], 0, 1);
    }

    for (int i = 0; i < CNT; i++) {
        int* id = (int*)malloc(sizeof(int));
        *id = i;
        pthread_create(&threads[i], NULL, philosopher, id);
    }
    
    for (int i = 0; i < CNT; i++) {
        pthread_join(threads[i], NULL);
    }

    for (int i = 0; i < CNT; i++) {
        sem_destroy(&forks[i]);
    }

    return 0;
}
