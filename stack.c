#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

struct stack{
    int* a;
    int tos;
    int size;
};

void push(struct stack*);
void pop(struct stack*);
void display(struct stack*);
void tos(struct stack*);

int main(){
    struct stack *stk = (struct stack*)malloc(sizeof(struct stack)); stk->tos = -1;
    printf("capacity of stack: "); scanf("%d", &stk->size);
    stk->a = (int*)malloc(stk->size*sizeof(int));
    int ch, x;
    do{
        printf("1.push\n2.pop\n3.display\n4.tos\nchoice: ");
        scanf("%d", &x);
        switch(x){
            case 1: push(stk); break;
            case 2: pop(stk); break;
            case 3: display(stk); break;
            case 4: tos(stk); break;
        }
        printf("continue? (1/0): "); scanf("%d", &ch);
    }while(ch == 1);
}

void push(struct stack *stk){
    int x;
    printf("element to push: "); scanf("%d", &x);
    if(stk->tos < stk->size - 1){
        stk->a[++stk->tos] = x;
    }
    else{
        printf("stack overflow. can't push\n");
    }
}

void pop(struct stack *stk){
    if(stk->tos > -1) stk->tos--;
    else{
        printf("Stack underflow. can't pop\n");
    }
}

void display(struct stack *stk){
    if(stk->tos == -1){
        printf("stack empty. no elements to display\n");
    }
    else{
        for(int i = 0; i <= stk->tos; i++){
            printf("%d ", stk->a[i]);
        }
        printf("\n");
    }
}

void tos(struct stack *stk){
    printf("top of stack: %d\n", stk->a[stk->tos]);
}

