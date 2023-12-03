#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char x) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

char pop() {
    if (top == -1) {
        return '\0'; // Use null character to indicate stack underflow
    } else {
        return stack[top--];
    }
}

int priority(char x) {
    if (x == '(') return 0;
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    return 0;
}

void infixToPostfix(char *exp) {
    char *e = exp;
    char x;

    while (*e != '\0') {
        if (isalnum(*e)) {
            printf("%c ", *e);
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            while ((x = pop()) != '(')
                printf("%c ", x);
        } else {
            while (top != -1 && priority(stack[top]) >= priority(*e))
                printf("%c ", pop());
            push(*e);
        }
        e++;
    }

    while (top != -1) {
        printf("%c ", pop());
    }
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter the expression: ");
    scanf("%s", exp);

    printf("Postfix Expression: ");
    infixToPostfix(exp);

    return 0;
}
