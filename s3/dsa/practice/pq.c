#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 100

struct PQ {
    int d[SIZE];
    int size;
};

typedef struct PQ PQ;

PQ* getPQ();
bool isFull(PQ* pq);
bool isEmpty(PQ* pq);
void push(PQ* pq, int x);
void pop(PQ* pq);
int top(PQ* pq);
void display(PQ* pq);

int main() {
    PQ* pq = getPQ();
    int ch, x;
    printf("1.push(PQ, x)\n2.pop(PQ)\n3.top(PQ)\n4.display(PQ)\n5.exit\n");
    while(true) {
        printf("enter the choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("enter x: "); scanf("%d", &x); push(pq, x);
                    break;
            case 2: pop(pq);
                    break;
            case 3: printf("%d\n", top(pq));
                    break;
            case 4: display(pq);
                    break;
            default: return 0;
        }
    }

    return 0;

}

PQ* getPQ() {
    PQ* pq = (PQ*)malloc(sizeof(PQ));
    pq->size = 0;
    return pq;
}

bool isFull(PQ* pq) {
    return pq->size == SIZE;
}

bool isEmpty(PQ* pq) {
    return pq->size == 0; 
}

void push(PQ* pq, int x) {
    if(isFull(pq)) {
        printf("Overflow\n");
        return;
    }

    int l = -1, r = pq->size;
    while(r - l > 1) {
        int m = l + (r - l)/2;
        if(pq->d[m] > x) r = m;
        else l = m;
    }
    for(int i = pq->size - 1; i >= r; i--) {
        pq->d[i + 1] = pq->d[i];
    }
    pq->d[r] = x;
    pq->size++;
    return;
}

void pop(PQ* pq) {
    if(isEmpty(pq)) {
        printf("Underflow\n");
        return;
    }

    pq->size--;
    return;
}

int top(PQ* pq) {
    if(isEmpty(pq)) {
        printf("Underflow\n");
        return INT_MAX;
    }

    return pq->d[pq->size - 1];
}

void display(PQ* pq) {
    for(int i = 0; i < pq->size; i++) {
        printf("%d  ", pq->d[i]);
    }
    printf("\n");
    return;
}
