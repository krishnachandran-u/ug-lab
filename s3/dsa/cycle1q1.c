#include <stdio.h>
#include <stdlib.h>
#define max(a,b) (a > b)? a: b

struct Polynomial {
    int cf[100];
    int maxp;
};

typedef struct Polynomial Polynomial;

void initPolynomial(Polynomial* p) {
    for(int i = 0; i < p->maxp + 1; i++) {
        p->cf[i] = 0;
    }
}

void setPolynomial(Polynomial* p) {
    for(int i = 0; i < p->maxp + 1; i++) {
        printf("coefficient of x^%d: ", i);
        scanf("%d", &p->cf[i]);
    }
}

void displayPolynomial(Polynomial* p) {
    for(int i = 0; i < p->maxp + 1; i++) {
        if(p->cf[i] != 0) {
            printf("%dx^%d  ", p->cf[i], i);
        }
    }
    printf("\n");
}

Polynomial* addPolynomial(Polynomial* p, Polynomial *q) {
    Polynomial *r = (Polynomial*)malloc(sizeof(Polynomial));
    r->maxp = max(p->maxp, q->maxp);
    for(int i = 0; i < r->maxp + 1; i++){ 
        r->cf[i] = p->cf[i] + q->cf[i];
    }
    return r;
}

int main() {
    Polynomial *p = (Polynomial*)malloc(sizeof(Polynomial));
    Polynomial *q = (Polynomial*)malloc(sizeof(Polynomial));
    printf("enter size of p and q: ");
    scanf("%d%d", &p->maxp, &q->maxp);
    initPolynomial(p);
    initPolynomial(q);
    printf("enter p:\n");
    setPolynomial(p);
    printf("enter q:\n");
    setPolynomial(q);
    displayPolynomial(p);
    displayPolynomial(q);
    Polynomial *r = addPolynomial(p, q);
    displayPolynomial(r);
    return 0;
}