#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>

#define max(a, b) (a > b)? a: b;
#define min(a, b) (a < b)? a: b;

struct Q{
    int *a; // array
    int cp; // size && capacity
    int f, r; //front and rear
};

void initQ(struct Q* q){
    q->a = NULL;
    q->f = 0; q->r = -1;
    q->cp = 0;
}

void pushQ(struct Q* q, int x){
    q->r++;
    if(q->r - q->f + 1 > q->cp){
        q->cp = max(1, q->cp << 1); 
        int *p = (int*)malloc(sizeof(int)*q->cp);
        int cnt = 0;
        for(int i = q->f; i < q->r; i++){
            p[cnt++] = q->a[i];
        }
        free(q->a);
        q->a = p;
        q->f = 0; q->r = cnt;
    }
    q->a[q->r] = x; 
    printf("[successful] pushed %d\n", x);
    return;
}

void popQ(struct Q* q){
    if(q->r - q->f + 1 == 0){
        printf("[underflow] can't pop\n");
        return;
    }
    printf("[successful] popped %d\n", q->a[q->f]); 
    q->f++;
    if(q->r - q->f + 1 <= (q->cp >> 1)){
        q->cp >>= 1;
        int *p = (int*) malloc(sizeof(int)*q->cp);
        int cnt = 0;
        for(int i = q->f; i <= q->r; i++){
            p[cnt++] = q->a[i];
        }
        free(q->a);
        q->a = p;
        q->f = 0; q->r = cnt - 1;  
    }
    return;
}

void disp(struct Q* q){
    for(int i = q->f; i <= q->r; i++){
        printf("%d  ", q->a[i]);
    }
    printf("\n");
    return;
}

int main(){
    struct Q q;
    initQ(&q);

    pushQ(&q, 1);
    disp(&q);
    pushQ(&q, 2);
    disp(&q);
    pushQ(&q, 3);
    disp(&q);
    pushQ(&q, 4);
    disp(&q);
    pushQ(&q, 5);
    disp(&q);

    popQ(&q);
    disp(&q);
    popQ(&q);
    disp(&q);
    popQ(&q);
    disp(&q);
    popQ(&q);
    disp(&q);
    popQ(&q);
    disp(&q);
    popQ(&q);
    disp(&q);
    popQ(&q);
    disp(&q);
    return 0;
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
[successful] popped 1
2  3  4  5  
[successful] popped 2
3  4  5  
[successful] popped 3
4  5  
[successful] popped 4
5  
[successful] popped 5

[underflow] can't pop

[underflow] can't pop
*/

