#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define max(a, b) (a > b)? a: b;
#define min(a, b) (a < b)? a: b;

struct S{
    int *a;
    int top, cp;
};

void init(struct S* s){
    s->a = NULL; 
    s->top = -1;
    s->cp = 0;
}

void push(struct S* s, int x){
    s->top++;
    if(s->top + 1 > s->cp){
        s->cp = max(1, s->cp << 1);
        int *p = (int*)malloc(sizeof(int)*s->cp);
        for(int i = 0; i < s->top; i++){
            p[i] = s->a[i];
        }
        free(s->a);
        s->a = p;
    }
    s->a[s->top] = x; 
    printf("[successful] pushed %d\n", x);
    return;
}

void pop(struct S* s){
    if(s->top == -1){
        printf("[underflow] can't pop\n");
        return;
    }
    printf("[successful] popped %d\n", s->a[s->top]); 
    s->top--;
    if(s->top + 1 <= (s->cp >> 1)){
        s->cp >>= 1;
        s->a = (int*) realloc(s->a, sizeof(int)*s->cp);
    }
}

void disp(struct S* s){
    for(int i = 0; i <= s->top; i++){
        printf("%d  ", s->a[i]);
    }
    printf("\n");
    return;
}

int main(){
    struct S s; 
    init(&s);
    
    printf("1.push\n2.pop\n3.disp\n4.exit\n");

    while(true) {
        int ch;
        scanf("%d", &ch);
        int x;
        switch(ch) {
            case 1: scanf("%d", &x); push(&s, x); break;
            case 2: pop(&s); break;
            case 3: disp(&s); break;
            case 4: exit(0); break;
        }
    }
}

/*
[successful] pushed 1
1  
[successful] pushed 2
1  2  
[successful] pushed 3
1  2  3  
[successful] pushed 4
1  2  3  4  
[successful] pushed 5
1  2  3  4  5  
[successful] popped 5
1  2  3  4  
[successful] popped 4
1  2  3  
[successful] popped 3
1  2  
[successful] popped 2
1  
[successful] popped 1

[underflow] can't pop

[underflow] can't pop

[successful] pushed 1
1  
[successful] pushed 2
1  2  
[successful] popped 2
1  
[successful] popped 1

[underflow] can't pop

[underflow] can't pop

[underflow] can't pop

*/
