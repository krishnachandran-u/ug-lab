#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Stack {
    char a[100];
    int sz;
};

typedef struct Stack Stack;

void init(Stack *s);
bool isEmpty(Stack* s);
void push(Stack* s, char ch);
void pop(Stack* s);
char top(Stack* s);
Stack* infixtopostfix(char* inf);
void action(Stack* post, Stack* op, char ch);
void display(Stack* s);

int main() {
    char a[100];
    scanf("%s", a);
    Stack* p = infixtopostfix(a);
    display(p);
    return 0;
}

void init(Stack* s) {
    s->sz = 0;
}

bool isEmpty(Stack* s) {
    return s->sz == 0;
}

void push(Stack* s, char ch) {
    s->a[s->sz++] = ch;
    return;
}

void pop(Stack* s) {
    if(isEmpty(s)) {
        printf("underflow\n");
        return;
    }
    s->a[s->sz--];
}

char top(Stack* s) {
    if(isEmpty(s)) {
        printf("stack empty\n");
        return '\0';
    }
    return s->a[s->sz - 1];
}

void display(Stack* s) {
    for(int i = 0; i < s->sz; i++)  {
        printf("%c ", s->a[i]);

    }
    printf("\n");
    return;
}

Stack* infixtopostfix(char* inf) {

    Stack* post = (Stack*)malloc(sizeof(Stack));
    Stack* op = (Stack*)malloc(sizeof(Stack));

    for(int i = 0; inf[i] != '\0'; i++) {
        action(post, op, inf[i]);
    }

    while(!isEmpty(op)) {
        push(post, top(op));
        pop(op);
    }    

    return post; 
}

void action(Stack* post, Stack* op, char ch) {
    if(ch >= 'a' && ch <= 'z') {
        push(post, ch);
        return;
    }
    if(ch == '+' || ch == '-') {
        while(!isEmpty(op) && top(op) != '(') {
            push(post, top(op));
            pop(op);
        }
        push(op, ch);
    }
    if(ch == '*' || ch == '/') {
        while(!isEmpty(op) && top(op) != '+' && top(op) != '-' && top(op) != '(') {
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
        while(top(op) != '(')  {
            push(post, top(op));
            pop(op);
        }
        pop(op);
    }
}
