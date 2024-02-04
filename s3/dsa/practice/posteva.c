//incomplete
#include <stdio.h>
#include <stdlib.h> 
#include <limits.h>
#include <stdbool.h>
#include <math.h>

#define SIZE 100

struct Stack {
    char d[100];
    int size;
};

typedef struct Stack Stack;

Stack* getStack();
bool isEmpty(Stack* s);
bool isFull(Stack* s);
void push(Stack* s, char x);
void pop(Stack* s);
char top(Stack* s);
void display(Stack* s);

int main() {
    char expr[100];
    printf("enter the postfix expr: ");
    scanf("%s", expr);
    Stack* res = getStack();
    Stack* op = getStack();
    for(int i = 0; expr[i] != '\0'; i++) {
        char ch = expr[i];
        if(ch >= '0' && ch <= '9') {
            push(res, ch);
        }
        else {
            char x = top(res) - '0'; pop(res);  
            char y = top(res) - '0'; pop(res);
            switch(ch) {
                case '+': push(res, (y + x) + ('0'));
                          break;
                case '-': push(res, (y - x) + ('0'));
                          break;
                case '*': push(res, (y * x) + ('0'));
                          break;
                case '/': push(res, (y - x) + ('0'));
                          break;
                case '^': push(res, ((float)pow(y, x)) + ('0'));
                          break;
            }
        }
    }
}

Stack* getStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->size = 0;
    return s;
}

bool isEmpty(Stack* s) {
    return s->size == 0;
}

bool isFull(Stack* s) {
    return s->size == SIZE; 
}

void push(Stack* s, char ch) {
    if(isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->d[s->size++] = ch;
    return;
}

void pop(Stack* s) {
    if(isEmpty(s)) {
        printf("Stack Underflow\n");
        return;
    }
    s->size--;
    return;
}

char top(Stack* s) {
    if(isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';
    }
    return s->d[s->size - 1];
}

void display(Stack *s) {
    for(int i = 0; i < s->size; i++) {
        printf("%c  ", s->d[i]);
    }
    printf("\n");
    return;
}
