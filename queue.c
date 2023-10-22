/*
    author: https://codeforces.com/profile/krishnachandran
    text-editor: NVIM v0.9.1
    compiler: gcc 11.4.0
*/

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define MAX 100

struct Queue{
    int a[MAX];
    int f, r;
};

void initQ(struct Queue* q){
    q->f = -1;
    q->r = -1;
}

bool isEmpty(struct Queue* q){
    return q->f == -1 && q->r == -1;
}

bool isFull(struct Queue* q){
    return q->r == MAX - 1;
}

void enQ(struct Queue* q, int value){
    if(isFull(q)){
        printf("[UNSUCCESSFUL] Queue overflow. cannot enqueue\n");
        return;
    }
    if(isEmpty(q)){
        q->f = 0;
        q->r = 0;
    }
    else{
        q->r = (q->r + 1) % MAX;
    }
    q->a[q->r] = value;
    printf("[SUCCESSFUL] Enqueued\n");
}

void dQ(struct Queue* q){
    if(isEmpty(q)){
        printf("[UNSUCCESSFUL] Queue underflow. cannot dequeue\n");
        return;
    }
    printf("[SUCCESSFUL] Dequeued: %d\n", q->a[q->f]);
    if(q->f == q->r){
        q->f = -1;
        q->r = -1;
    }
    else{
        q->f = (q->f + 1) % MAX;
    }
}

void display(struct Queue* q){
    if(isEmpty(q)){
        printf("[SUCCESSFUL] Queue empty\n");
        return;
    }
    printf("[SUCCESSFUL]\n");
    int i = q->f;
    do{
        printf("%d ", q->a[i]); 
        i = (i + 1) % MAX;
    } while(i != (q->r + 1) % MAX);
    printf("\n");
}

int main(){
    struct Queue myQ;
    initQ(&myQ);
    display(&myQ);
    enQ(&myQ, 1);
    enQ(&myQ, 2);
    enQ(&myQ, 3);
    display(&myQ);
    dQ(&myQ);
    display(&myQ);
    dQ(&myQ);
    dQ(&myQ);
    dQ(&myQ);
    return 0;
}
