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

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void init(struct Q* q){
    q->a = NULL;
    q->f = 0; q->r = -1;
    q->cp = 0;
}

void push_back(struct Q* q, int x){
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
    printf("[successful] pushed\n");
    return;
}

void push_front(struct Q* q, int x){  
    push_back(q, x);
    for(int i = q->r; i > q->f; i--){
        swap(&q->a[i], &q->a[i - 1]);
    }
    return;
}

void pop_front(struct Q* q){
    if(q->r - q->f + 1 == 0){
        printf("[underflow] can't pop\n");
        return;
    }
    printf("[successful] popped\n"); 
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

void pop_back(struct Q* q){
    for(int i = q->r; i > q->f; i--){
        swap(&q->a[i], &q->a[i - 1]);
    }
    pop_front(q);
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
    init(&q);
    while(true){
        int ch;
        int x;
        printf("1.push_front(x)\n2.push_back(x)\n3.pop_back\n4.pop_front\n5.display\n6.exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1 : printf("x: "); scanf("%d", &x); push_front(&q, x); break;
            case 2 : printf("x: "); scanf("%d", &x); push_back(&q, x); break;
            case 3 : pop_back(&q); break;
            case 4 : pop_front(&q); break;
            case 5 : disp(&q); break;
            case 6 : return 0;

        }
    }
    return 0;
}

/*

1.push_front(x)
2.push_back(x)
3.pop_back
4.pop_front
5.display
6.exit
1
x: 5
[successful] pushed 5
1.push_front(x)
2.push_back(x)
3.pop_back
4.pop_front
5.display
6.exit
1
x: 6
[successful] pushed 6
1.push_front(x)
2.push_back(x)
3.pop_back
4.pop_front
5.display
6.exit
5
6  5  
1.push_front(x)
2.push_back(x)
3.pop_back
4.pop_front
5.display
6.exit
2
x: 9
[successful] pushed 9
1.push_front(x)
2.push_back(x)
3.pop_back
4.pop_front
5.display
6.exit
5
6  5  9  
1.push_front(x)
2.push_back(x)
3.pop_back
4.pop_front
5.display
6.exit
4
[successful] popped 6
1.push_front(x)
2.push_back(x)
3.pop_back
4.pop_front
5.display
6.exit
5
5  9  
1.push_front(x)
2.push_back(x)
3.pop_back
4.pop_front
5.display
6.exit
3
[successful] popped 9
1.push_front(x)
2.push_back(x)
3.pop_back
4.pop_front
5.display
6.exit
5
5  
1.push_front(x)
2.push_back(x)
3.pop_back
4.pop_front
5.display
6.exit
4
[successful] popped 5
1.push_front(x)
2.push_back(x)
3.pop_back
4.pop_front
5.display
6.exit
5

1.push_front(x)
2.push_back(x)
3.pop_back
4.pop_front
5.display
6.exit

*/
