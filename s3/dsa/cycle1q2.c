#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct Tuple {
    int row;
    int col;
    int val;
};

typedef struct Tuple Tuple;

struct SparseMatrix { 
    Tuple tuple[100];
    int m;
    int n;
    int length;
};

typedef struct SparseMatrix SparseMatrix;

void initSparseMatrix(SparseMatrix* sm, int m, int n) {
    sm->m = m; 
    sm->n = n;
    sm->length = 0;
    return;
}

void displaySparseMatrix(SparseMatrix* sm) {
    printf("\nrow        col        value\n");
    for(int i = 0; i < sm->length; i++){
        printf("%d: %d        %d        %d\n", i, sm->tuple[i].row, sm->tuple[i].col, sm->tuple[i].val);
    }
    printf("\n");
}

void setRowSparseMatrix(SparseMatrix* sm, int i, int j, int x) {
    sm->tuple[sm->length].row = i; 
    sm->tuple[sm->length].col = j;
    sm->tuple[sm->length].val = x;
    sm->length++;
}

void setSparseMatrix(SparseMatrix* sm) {
    for(int i = 0; i < sm->m; i++) {
        for(int j = 0; j < sm->n; j++) {
            int x;
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &x);
            if(x != 0) {
                setRowSparseMatrix(sm, i, j, x);
            }
        }
    }
}

SparseMatrix* addSparseMatrix(SparseMatrix* p, SparseMatrix* q) {
    if(p->m != q->m || p->n != q->n) {
        printf("incompatible\n");
        exit(0);
    }
    SparseMatrix* r = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    initSparseMatrix(r, p->m, p->n);
    int i = 0, j = 0;
    for(; i < p->length;) {    
        while(j < q->length && ((q->tuple[j].row <= p->tuple[i].row && q->tuple[j].col < p->tuple[i].col) || (q->tuple[j].row < p->tuple[i].row))) {
            setRowSparseMatrix(r, q->tuple[j].row, q->tuple[j].col, q->tuple[j].val);
            j++;
        }
        printf("%d %d\n", i, j);
        if(j < q->length && q->tuple[j].row == p->tuple[i].row && q->tuple[j].col == p->tuple[i].col) {
            setRowSparseMatrix(r, p->tuple[i].row, p->tuple[i].col, p->tuple[i].val + q->tuple[j].val);
            j++;
        }
        else {
            setRowSparseMatrix(r, p->tuple[i].row, p->tuple[i].col, p->tuple[i].val);
        } 
        i++;
    }
    for(; j < q->length; j++) {
        setRowSparseMatrix(r, q->tuple[j].row, q->tuple[j].col, q->tuple[j].val);
    }

    return r;
}

int main() {
    SparseMatrix* p = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    SparseMatrix* q = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    int m, n;
    printf("enter the order of p: ");
    scanf("%d%d", &m, &n);
    initSparseMatrix(p, m, n);
    printf("enter the order of q: ");
    scanf("%d%d", &m, &n);
    initSparseMatrix(q, m, n);
    setSparseMatrix(p);
    setSparseMatrix(q);
    SparseMatrix* r = addSparseMatrix(p, q);
    displaySparseMatrix(p);
    displaySparseMatrix(q);
    displaySparseMatrix(r);
    return 0;
}
