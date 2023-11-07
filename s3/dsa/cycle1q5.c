/*
    author: krishnachandran u
    github: https://github.com/krishnachandran-u
    text-editor: NVIM v0.9.1
    compiler: gcc 11.4.0
*/

/*
5. Write a menu driven C Program to implement a circular queue using arrays with the
following operations:
a) Insert an element to the queue.
b) Delete an element from the queue.
c) Display the contents of the queue.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

struct CQ{
    int *a; 
    int f, r, sz, cp;
};

void init(struct CQ* cq, int n){
    cq->cp = n;
    cq->a = (int*)malloc(sizeof(int)*cq->cp); 
    cq->r = 0;
    cq->f = 0;
    cq->sz = 0;
}

void push(struct CQ* cq, int x){
    if(cq->sz == cq->cp){
        printf("overflow\n");
        return;
    }
    cq->a[cq->r] = x;
    cq->r = (cq->r + 1) % cq->cp;
    cq->sz++;
    return;
}

void pop(struct CQ* cq){
    if(cq->sz == 0){
        printf("underlow\n");
        return;
    }
    cq->f = (cq->f + 1) % cq->cp;
    cq->sz--;
    return;
}

void disp(struct CQ* cq){
    int k = cq->sz;
    for(int i = cq->f; k--; i = (i + 1) % cq->cp){
        printf("%d  ", cq->a[i]);
    }
    printf("\n");
}

int main(){
    struct CQ cq;
    int n;
    printf("n: "); scanf("%d", &n); 
    init(&cq, n);

    while(true){
        int ch;
        printf("1.push(x)\n2.pop\n3.display\n4.exi\n");
        scanf("%d", &ch);
        switch(ch){
            case 1: int x; printf("x: "); scanf("%d", &x); push(&cq, x);
                    break;
            case 2: pop(&cq);
                    break;
            case 3: disp(&cq);
                    break;
            case 4: exit(0);
        }
    }
    return 0;
}

/*

n: 5
1.push(x)
2.pop
3.display
4.exi
1
x: 5
1.push(x)
2.pop
3.display
4.exi
1
x: 6
1.push(x)
2.pop
3.display
4.exi
3
5  6  
1.push(x)
2.pop
3.display
4.exi
1
x: 7
1.push(x)
2.pop
3.display
4.exi
3
5  6  7  
1.push(x)
2.pop
3.display
4.exi
1
x: 8
1.push(x)
2.pop
3.display
4.exi
1 
x: 3
1.push(x)
2.pop
3.display
4.exi
3
5  6  7  8  3  
1.push(x)
2.pop
3.display
4.exi
1
x: 3
overflow1.push(x)
2.pop
3.display
4.exi
2
1.push(x)
2.pop
3.display
4.exi
3
6  7  8  3  
1.push(x)
2.pop
3.display
4.exi
1
x: 8
1.push(x)
2.pop
3.display
4.exi
3
6  7  8  3  8  
1.push(x)
2.pop
3.display
4.exi
3
6  7  8  3  8  
1.push(x)
2.pop
3.display
4.exi
2
1.push(x)
2.pop
3.display
4.exi
3
7  8  3  8  
1.push(x)
2.pop
3.display
4.exi
1
x: 9
1.push(x)
2.pop
3.display
4.exi
3
7  8  3  8  9  
1.push(x)
2.pop
3.display
4.exi
2
1.push(x)
2.pop
3.display
4.exi
2
1.push(x)
2.pop
3.display
4.exi
3
3  8  9  
1.push(x)
2.pop
3.display
4.exi
2
1.push(x)
2.pop
3.display
4.exi
2
1.push(x)
2.pop
3.display
4.exi
2
1.push(x)
2.pop
3.display
4.exi
3

1.push(x)
2.pop
3.display
4.exi
1
x: 3
1.push(x)
2.pop
3.display
4.exi
3
3  
1.push(x)
2.pop
3.display
4.exi
2
1.push(x)
2.pop
3.display
4.exi
2
underlow1.push(x)
2.pop
3.display
4.exi

*/
