/*
    author: https://codeforces.com/profile/krishnachandran
    text editor: NVIM v0.9.1
    compiler: GNU G++20 11.2.0 (64 bit,  winlibs)
*/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct Q{
    int *a;
    int r;
};

void initQ(struct Q* q){
    q->a = NULL;
    q->r = -1;
}

bool isEmpty(struct Q* q){
    return q->a == NULL;
}

void enQ(struct Q* q, int value){
    q->r++; 
    q->a = (int*)realloc(q->a, sizeof(int)*(q->r + 1));
    q->a[q->r] = value;
}

void dQ(struct Q* q){
    if(isEmpty(q)){
        printf("[UNSUCCESSFUL] Queue underflow. cannot dequeue\n");
        return;
    }
    printf("[SUCCESSFUL] Dequeued: %d\n", q->a[q->r]);
    q->r--;
    if(q->r == -1){
        q->a = NULL;
    }
    else{
        q->a = (int*)realloc(q->a, sizeof(int)*(q->r + 1));
    }
    return;
}

void display(struct Q* q){
    if(isEmpty(q)){
        printf("[SUCCESSFUL] Queue empty\n");
        return;
    }
    for(int i = 0; i <= q->r; i++){
        printf("%d ", q->a[i]);
    }
    printf("\n");
    return;
}

int main(){
    struct Q myQ;
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

