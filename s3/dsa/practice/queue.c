#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 100

struct Queue {
    int d[SIZE];
    int size;
    int f, r;
};

typedef struct Queue Queue;

Queue* getQueue();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void push(Queue* q, int x);
void pop(Queue* q);
int front(Queue* q);
int rear(Queue* q);
void display(Queue* q);

int main() {
    Queue* q = getQueue();
    printf("1.push(x)\n2.pop()\n3.front()\n4.rear()\n5.display\n6.exit\n");
    int ch, x;
    while(true) {
        printf("enter choice: \n");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("enter x: "); scanf("%d", &x); push(q, x);
                    break;
            case 2: pop(q);
                    break;
            case 3: front(q);
                    break;
            case 4: rear(q);
                    break;
            case 5: display(q);
                    break;
            default: return 0;
        }
    }
    return 0;
}

Queue* getQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->size = 0;
    q->r = 0;
    q->f = 0;
    return q;
}

bool isFull(Queue* q) {
    return q->size == SIZE;
}

bool isEmpty(Queue* q) {
    return q->size == 0;
}

void push(Queue* q, int x) {
    if(isFull(q)) {
        printf("Stack Overflow. Cannot push");
    }
    else {
        q->d[q->r++] = x;
        q->size++;
    }
    return;
}

void pop(Queue* q) {
    if(isEmpty(q)) {
        printf("Stack Underflow. Cannot pop");
    }
    else {
        q->f++;
        q->size--;
    }
}

int front(Queue* q) {
    if(isEmpty(q)) {
        printf("Stack Underflow. Cannot pop");
        return INT_MIN;
    }
    else {
        return q->d[q->f];
    }
}

int rear(Queue* q) {
    if(isEmpty(q)) {
        printf("Stack Underflow. Cannot pop");
        return INT_MIN;
    }
    else {
        return q->d[q->r - 1];
    }
}

void display(Queue* q) {
    for(int i = q->f; i < q->r; i++) {
        printf("%d  ", q->d[i]);
    }
    printf("\n");
}
