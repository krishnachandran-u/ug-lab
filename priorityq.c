#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct PriorityQueue{
    int a[100];
    int sz;
};

void initPQ(struct PriorityQueue* pq){
    pq->sz = -1; 
}

bool isEmpty(struct PriorityQueue* pq){
    return pq->sz == -1;
}

bool isFull(struct PriorityQueue* pq){
    return pq->sz == MAX - 1;
}

void enPQ(struct PriorityQueue* pq, int value){
    if(isFull(pq)){
        printf("[UNSUCCESSFUL] Queue overflow. cannot enqueue\n");
        return;
    }
    int l = -1, r = pq->sz + 1;
    while(r - l > 1){
        int m = l + (r - l)/2;
        if(pq->a[m] <= value) l = m;
        else r = m;
    }
    for(int i = pq->sz; i >= r; i--){
        pq->a[i + 1] = pq->a[i];
    }
    pq->a[r] = value;
    pq->sz++;
    return;
}

void dPQ(struct PriorityQueue* pq){
    if(isEmpty(pq)){
        printf("[UNSUCCESSFUL] Queue underflow. cannot dequeue\n");
        return;
    }
    printf("[SUCCESSFUL] Dequeued: %d\n", pq->a[pq->sz]);
    pq->sz--;
}

void display(struct PriorityQueue* pq){
    if(isEmpty(pq)){
        printf("[SUCCESSFUL] Queue empty\n");
        return;
    }
    printf("[SUCCESSFUL]\n");
    for(int i = 0; i <= pq->sz; i++){
        printf("%d ", pq->a[i]);
    }
    printf("\n");
    return;
}

int main(){
    struct PriorityQueue mypq;
    initPQ(&mypq);
    display(&mypq);
    enPQ(&mypq, 30);
    display(&mypq);
    enPQ(&mypq, 25);
    display(&mypq);
    enPQ(&mypq, 40);
    display(&mypq);
    enPQ(&mypq, 10);
    display(&mypq);
    dPQ(&mypq);
    display(&mypq);
    dPQ(&mypq);
    dPQ(&mypq);
    dPQ(&mypq);
    dPQ(&mypq);
    return 0;
}
