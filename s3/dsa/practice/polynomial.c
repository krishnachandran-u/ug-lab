#include <stdio.h>
#include <stdlib.h>

struct Polynomial {
    int size;
    int cf[100];
    int exp[100];
};

typedef struct Polynomial Polynomial;

Polynomial* getPolynomial() {
    Polynomial* p = (Polynomial*)malloc(sizeof(Polynomial));
    p->size = 0;
    return p;
}

void createPolynomial(Polynomial* p, int highestExp) {
    for(int i = highestExp; i >= 0; i--) {
        int x;
        printf("Enter coefficient of x^%d: ", i);
        scanf("%d", &x);
        if(x != 0) {
            p->cf[p->size] = x;
            p->exp[p->size] = i;
            p->size++;
        }
    }
}

Polynomial* addPolynomial(Polynomial* p, Polynomial* q) {
    Polynomial* r = getPolynomial();
    for(int i = 0, j = 0; i < p->size || j < q->size;) {
        while(i < p->size && j < q->size && p->exp[i] > q->exp[j]) {
            r->exp[r->size] = p->exp[i];
            r->cf[r->size] = p->exp[i];
            r->size++; i++;
        }
        if(i < p->size && j < q->size && p->exp[i] == q->exp[j]) {
            r->exp[r->size] = p->exp[i];
            r->cf[r->size] = p->cf[i] + q->cf[j];
            r->size++; i++; j++;
        }
        else if(i < p->size && j < q->size && p->exp[i] < q->exp[j]) {
            r->exp[r->size] = q->exp[j];
            r->cf[r->size] = q->cf[j];
            r->size++; j++;
        }
        else if(i < p->size) {
            r->exp[r->size] = p->exp[i]; 
            r->cf[r->size] = p->cf[i];
            r->size++; i++;
        }
        else { //j < q->size
            r->exp[r->size] = q->exp[j];
            r->cf[r->size] = q->cf[j];
            r->size++; j++;
        }
    }
    return r;
}

void displayPolynomial(Polynomial* p) {
    for(int i = 0; i < p->size; i++) {
        printf("%dx^%d  ", p->cf[i], p->exp[i]);
    }
    printf("\n");
}

int main() {
    int n;
    Polynomial *p1 = getPolynomial();
    Polynomial *p2 = getPolynomial();
    printf("Enter the largest exponent in polynomial 1\n");
    scanf("%d", &n);
    createPolynomial(p1, n);
    displayPolynomial(p1);
    printf("Enter the largest exponent in polynomial 2\n");
    scanf("%d", &n);
    createPolynomial(p2, n);
    displayPolynomial(p2);
    Polynomial* r = addPolynomial(p1, p2);
    displayPolynomial(r);
    return 0;
}
