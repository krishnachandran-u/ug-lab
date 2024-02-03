#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 100

struct Stack {
    int d[SIZE];
    int size;
};

typedef struct Stack Stack;

Stack* getStack();
void push(Stack* s, int x);
void pop(Stack* s);
int top(Stack* s);
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void display(Stack* s);

int main() {
    Stack* s = getStack();
    printf("1.push(x)\n2.pop()\n3.top()\n4.display()\n5.exit()\n");
    int ch, x;
    while(true) {
        printf("enter choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: printf("enter x: "); scanf("%d", &x); push(s, x);
                    break;
            case 2: pop(s);
                    break;
            case 3: printf("%d", top(s));
                    break;
            case 4: display(s);
                    break;
            default: return 0;
        }
    }
    return 0;
}

Stack* getStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->size = 0;
    return s;
}

void push(Stack* s, int x) {
    if(isFull(s)) {
        printf("Stack Overflow\n");
    }
    else {
        s->d[s->size++] = x;
    }
    return;
}

void pop(Stack* s) {
    if(isEmpty(s)) {
        printf("Stack Underflow\n");
    }
    else {
        s->size--;
    }
    return;
}

int top(Stack* s) {
    if(isEmpty(s)) {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    else {
        return s->d[s->size - 1];
    }
}

bool isEmpty(Stack* s) {
    return s->size == 0;
}

bool isFull(Stack* s) {
    return s->size == SIZE;
}

void display(Stack* s) {
    for(int i = 0; i < s->size; i++) {
        printf("%d  ", s->d[i]);
    }
    printf("\n");
    return;
}

