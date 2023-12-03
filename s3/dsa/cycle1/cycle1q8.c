#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top;
    int size;
    int arr[100];
} stack;

stack* createStack();
void push(stack* s, int data);
void pop(stack* s);
void infixToPostfix(char* infix, stack* s);
void postfixEvaluate(char* postfix, stack* s);
int getPriority(char op);

int main() {
    printf("\nEnter the expression: ");
    char exp[100];
    fgets(exp, 100, stdin);
    stack* s = createStack();
    printf("1) Infix to postfix\n2) evaluate Postfix\nChoice: ");
    int ch;
    scanf("%d", &ch);
    if (ch == 1) {
        infixToPostfix(exp, s);
    } else if (ch == 2) {
        postfixEvaluate(exp, s);
    } else {
        printf("Invalid choice\n");
    }
}

void infixToPostfix(char* infix, stack* s) {
    int j = 0;
    for (j = 0; infix[j] != '\0'; j++)
        ;
    infix[j] = ')';
    for (int i = 0; i <= j; i++) {
        if (infix[i] >= 'a' && infix[i] <= 'z') {
            printf("%c", infix[i]);
        } else if (infix[i] == '(') {
            push(s, infix[i]);
        } else if (infix[i] == ')') {
            while (s->top >= 0 && s->arr[s->top] != '(') {
                printf("%c", s->arr[s->top]);
                pop(s);
            }
            if (s->top >= 0)
                pop(s);
        } else {
            while (s->top >= 0 && getPriority(infix[i]) <= getPriority(s->arr[s->top])) {
                printf("%c", s->arr[s->top]);
                pop(s);
            }
            push(s, infix[i]);
        }
    }
}

void postfixEvaluate(char* postfix, stack* s) {
    int j = 0;
    for (j = 0; postfix[j] != '\0'; j++)
        ;
    for (int i = 0; i < j; i++) {
        printf("%c", postfix[i]);
    }
    for (int i = 0; i < j; i++) {
        int c = postfix[i] - '0';
        if (postfix[i] == ' ')
            continue;
        if (c >= 0 && c <= 9) {
            int val = 0;
            while (i < j && postfix[i] >= '0' && postfix[i] <= '9') {
                val = val * 10 + (postfix[i] - '0');
                i++;
            }
            i--;
            push(s, val);
        } else {
            int a = s->arr[s->top];
            pop(s);
            int b = s->arr[s->top];
            pop(s);
            if (postfix[i] == '+') {
                push(s, a + b);
            } else if (postfix[i] == '-') {
                push(s, b - a);
            } else if (postfix[i] == '*') {
                push(s, a * b);
            } else if (postfix[i] == '/') {
                push(s, b / a);
            } else {
                printf("Invalid character\n");
                return;
            }
        }
    }
    printf("\nExpression = %d\n", s->arr[s->top]);
}

int getPriority(char op) {
    switch (op) {
        case '(':
            return 0;
            break;
        case '+':
            return 1;
            break;
        case '-':
            return 1;
            break;
        case '*':
            return 2;
            break;
        case '/':
            return 2;
            break;
        case '^':
            return 3;
        default:
            return -1;
    }
}

stack* createStack() {
    stack* s = (stack*)malloc(sizeof(stack));
    s->top = -1;
    s->size = 100;
    return s;
}

void push(stack* s, int data) {
    if (s->top == s->size - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->arr[s->top] = data;
}

void pop(stack* s) {
    if (s->top < 0) {
        printf("Stack Underflow\n");
        return;
    }
    s->top--;
}
