#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct CQ {
    int* d;
    int f, r, size, cap;
};

typedef struct CQ CQ;

CQ* getCQ(int cap);
bool isFull(CQ* cq);
bool isEmpty(CQ* cq);
void push(CQ* cq, int x);
void pop(CQ* cq);
int front(CQ* cq);
int rear(CQ* cq);
void display(CQ* cq);

int main() {
    CQ* cq = getCQ(5);
    int ch, x;
    printf("1.push(CQ, x)\n2.pop(CQ)\n3.front(CQ)\n4.rear(CQ)\n5.display(CQ)\n6.exit\n");
    while(true) {
        printf("enter the choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("enter x: "); scanf("%d", &x); push(cq, x);
                    break;
            case 2: pop(cq);
                    break;
            case 3: printf("%d", front(cq));
                    break;
            case 4: printf("%d", rear(cq));
                    break;
            case 5: display(cq);
                    break;
            default: return 0;
        }
    }

    return 0;
}

CQ* getCQ(int cap) {
    CQ* cq = (CQ*)malloc(sizeof(CQ));
    cq->cap = cap;
    cq->d = (int*)malloc(cq->cap*sizeof(int));
    cq->size = cq->f = cq->r = 0;
    return cq;
}

bool isFull(CQ *cq) {
    return cq->size == cq->cap;
}

bool isEmpty(CQ *cq) {
    return cq->size == 0;
}

void push(CQ* cq, int x) {
    if(isFull(cq)) {
        printf("Queue overflow. cannot push\n");
    }
    else {
        cq->d[cq->r] = x;
        cq->r = (cq->r + 1) % cq->cap;
        cq->size++;
    }
    return;
}

void pop(CQ* cq) {
    if(isEmpty(cq)) {
       printf("Queue underflow. cannot pop\n"); 
    }
    else {
        cq->f = (cq->f + 1) % cq->cap;
        cq->size--;
    }
}

int front(CQ* cq) {
    if(isEmpty(cq)) {
        printf("Queue empty\n");
        return INT_MIN;
    }
    else {
        return cq->d[cq->f];
    }
}

int rear(CQ* cq) {
    if(isEmpty(cq)) {
        printf("Queue empty\n");
        return INT_MIN;
    }
    else {
        return cq->d[(cq->r - 1) % cq->cap];
    }
}

void display(CQ* cq) {  
    int cnt = 0;
    for(int i = cq->f; cnt < cq->size; i = (i + 1) % cq->cap, cnt++) {
        printf("%d  ", cq->d[i]);
    }
    printf("\n");
    return;
}
