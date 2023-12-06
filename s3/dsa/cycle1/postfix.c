#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

struct Stack {
    float a[100];
    int sz;
};

typedef struct Stack Stack;

void init(Stack* s);
void push(Stack* s, float x);
void pop(Stack* s);
float top(Stack* s);
bool isEmpty(Stack* s);
float evaluate(char* post);
void display(Stack* s);

int main() {
    char post[100];
    printf("enter the expression with numbers and operators separated by spaces\n");
    fgets(post, 100, stdin); 
    float expr = evaluate(post);
    printf("%f\n", expr);
}

void init(Stack* s) {
    s->sz = 0;
}

void push(Stack* s, float x) {
    s->a[s->sz] = x;
    s->sz++;
}

void pop(Stack* s) {
    if(isEmpty(s)) {
        printf("--underflow--\n");
        return;
    }
    s->sz--;
}

float top(Stack* s) {
    if(isEmpty(s)) {
        printf("--underflow--\n");
        return INT_MAX;
    }
    return s->a[s->sz - 1];
}

bool isEmpty(Stack* s) {
    return s->sz == 0;
}

void display(Stack* s) {
    for(int i = 0; i < s->sz; i++) {
        printf("%f  ", s->a[i]);
    }
    printf("\n");
}

float evaluate(char* post) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    init(s);
    for(int i = 0; post[i] != '\0';) {
        if(post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '^') {
            float x = top(s);
            pop(s);
            float y = top(s);
            pop(s);
            
            float res;
            switch(post[i]) {
                case '+': res = y + x; break;
                case '-': res = y - x; break;
                case '*': res = y * x; break;
                case '/': res = y / x; break;
                case '^': res = pow(y, x); break;
            }

            push(s, res);
            i++;
        }
        else if(post[i] >= '0' && post[i] <= '9') {
            Stack* tmp = (Stack*)malloc(sizeof(Stack));
            init(tmp);
            while(post[i] != '\0' && post[i] >= '0' && post[i] <= '9') {
                push(tmp, post[i] - '0');
                i++;
            }
            float x = 0;
            int len = tmp->sz;
            for(int j = 0; j < len; j++) {
                x += top(tmp)*pow(10, j);
                pop(tmp);
            }
            push(s, x);
        }
        else {
            i++;
        }
        display(s);
    }
    return top(s);
}


