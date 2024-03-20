#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

#define NUM_PHILOSOPHERS 5

sem_t mutex;
sem_t forks[NUM_PHILOSOPHERS];

void thinking(int phil_num) {
    printf("Philosopher %d is thinking\n", phil_num + 1);
}

void eating(int phil_num) {
    printf("Philosopher %d is eating\n", phil_num + 1);
}

void pick_up_forks(int phil_num) {
    sem_wait(&mutex);

    sem_wait(&forks[phil_num]);

    int left_neighbor = (phil_num + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS;
    int right_neighbor = (phil_num + 1) % NUM_PHILOSOPHERS;
    if (phil_num % 2 == 0) {
        sem_wait(&forks[right_neighbor]);
    } else {
        sem_wait(&forks[left_neighbor]);
    }

    printf("Philosopher %d picked up forks %d and %d\n",
           phil_num + 1, phil_num + 1, right_neighbor + 1);

    sem_post(&mutex);
}

void put_down_forks(int phil_num) {
    sem_post(&forks[phil_num]);
    sem_post(&forks[(phil_num + 1) % NUM_PHILOSOPHERS]);
}

void *philosopher(void *arg) {
    int phil_num = *(int *)arg;

    while (1) {
        thinking(phil_num);
        pick_up_forks(phil_num);
        eating(phil_num);
        put_down_forks(phil_num);
    }
}

int main() {
    int i;
    pthread_t phil_threads[NUM_PHILOSOPHERS];

    sem_init(&mutex, 0, 1);
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&forks[i], 0, 1);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        int *id = malloc(sizeof(int));
        *id = i;
        pthread_create(&phil_threads[i], NULL, philosopher, id);
    }

    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(phil_threads[i], NULL);
    }

    sem_destroy(&mutex);
    for (i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_destroy(&forks[i]);
    }

    return 0;
}

