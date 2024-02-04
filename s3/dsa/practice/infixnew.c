#include <stdio.h>
#include <stdlib.h> 
#include <limits.h>
#include <stdbool.h>

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
Stack* convert(char* s);
void action(Stack* post, Stack* op, char ch);
void display(Stack* s);

int main() {
    char infix[100];
    printf("Enter the expr: ");
    scanf("%s", infix);
    Stack* postfix = convert(infix);
    display(postfix);
    return 0;
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

Stack* convert(char* s) {
    Stack* post = getStack();
    Stack* op = getStack();

    for(int i = 0; s[i] != '\0'; i++) {
        action(post, op, s[i]);
    }

    while(!isEmpty(op)){
        push(post, top(op));
        pop(op);
    }

    return post;
}

void action(Stack* post, Stack* op, char ch) {
    if(ch >= 'a' && ch <= 'z') {
        push(post, ch);
    }
    if(ch == '+' || ch == '-') {
        while(!isEmpty(op) && top(op) != '(') {
            push(post, top(op));
            pop(op);
        }
        push(op, ch);
    }
    if(ch == '*' || ch == '-') {
        while(!isEmpty(op) && top(op) != '(' && top(op) != '+' && top(op) != '-') {
            push(post, top(op));
            pop(op);
        }
        push(op, ch);
    }
    if(ch == '^') {
        while(!isEmpty(op) && top(op) != '(' && top(op) != '+' && top(op) != '-' && top(op) != '*' && top(op) != '/' && top(op) != '^') {
            push(post, top(op));
            pop(op);
        }
        push(op, ch);
    }
    if(ch == '(') {
        push(op, ch);
    }
    if(ch == ')') {
        while(top(op) != '(') {
            push(post, top(op));
            pop(op);
        }
        pop(op);
    }
}
