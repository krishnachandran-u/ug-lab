#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

struct Stack {
    char a[100];
    int sz;
};

typedef struct Stack Stack;

void initStack(Stack* stk) {
    stk->sz = 0;
}

void push(Stack* stk, char ch) {
    stk->a[stk->sz] = ch;
    stk->sz++;
}

bool isEmpty(Stack* stk) {
    return (stk->sz == 0);
}

int top(Stack* stk) {
    if(isEmpty(stk)) {
        printf ("--empty--\n");
        return INT_MAX;
    }
    return (stk->a[stk->sz - 1]);
}

char pop(Stack* stk) {
    if(isEmpty(stk)) {
        return '?'; //no action
    }
    char ch = top(stk);
    stk->sz--;
    return ch;
}

void action(Stack* opstack, Stack* postfix, char ch) {
    if(ch >= 'a' && ch <= 'z') {
        pushToPostfix(postfix, ch); 
    }
    if(ch == '(' || isEmpty(postfix) == 0) {
        pushToOPStack(opstack, ch);
    }
    if(ch == ')') {
        popTill(opstack, postfix, ')');
        return;
    }
    if(getPrecedence(ch) == getPrecedence(top(postfix)) {
        if(getAssociativity(ch) == 1) {
            popTill(ch);
            return;
        }
        if(getAssociativity(ch) == 2) {
            pushToOPStack(ch);
            return;
        }
    }
    if(getPrecedence(ch) > getPrecedence(top(postfix))) {
        pushToOPStack(opstack, ch);
        return;
    }
    if(getPrecedence(ch) < getPrecedence(top(postfix))) {
        popTill(opstack, postfix, ch);
    }
}

void pushToPostfix(Stack* postfix, char ch) {
    push(postfix, ch);
    return;
}

void pushToOPstack(Stack* opstack, char ch) {
    push(opstack, ch);
    return;
}

void popTill(Stack* opstack, Stack* postfix, char ch) {
    while(!isEmpty(opstack) && getPrecedence(ch) <= getPrecedence(top(opstack))) {
        if(top(opstack) == ')') {
            
        }
        char tmp = pop(opstack);
        pushToPostfix(postfix, tmp);
    }
}

int getPrecedence(char ch) {
    if(ch == '+' || ch == '-') {
        return 1; 
    }
    if(ch == '*' || ch == '/') {
        return 2;
    }
    if(ch == '^') {
        return 3;
    }
}

int getAssociativity(char ch) {
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return 1;
    }
    if(ch == '^') {
        return 2;
    }
}

char* infixToPostfix(char* a){
    Stack* opstack = (Stack*)malloc(sizeof(Stack));
    Stack* postfix = (Stack*)malloc(sizeof(Stack));
    for(int i = 0; a[i] != '\0'; i++){
        action(opstack, postfix, a[i]);
    }
    return postfix;
}

int main() {
    char* a = (char*)malloc(100*sizeof(char));
    scanf("%s", a);

}