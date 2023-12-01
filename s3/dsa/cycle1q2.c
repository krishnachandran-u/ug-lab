#include <stdio.h>

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
    printf("row        col        value\n");
    for(int i = 0; i < sm->length; i++){
        printf("%d        %d        %d\n", sm->tuple[i].row, sm->tuple[i].col, sm->tuple[i].value);
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

void addSparseMatrix(SparseMatrix* p, SparseMatrix* q) {
    if(p->m != q->m || p->n != q->n){
        printf("incompatible\n");
        return;
    }
    SparseMatrix* r = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    initSparseMatrix(r, p->m, p->n);
    for(int i = 0, j = 0; i < p->length; i++) {    
        while(q->tuple[j].row <= p->tuple[i].row && q->tuple[j].col < p->tuple[i].col &&  j < q->length) {
            setRowSparseMatrix(r, q->tuple[j].row, q->tuple[j].col, q->tuple[j].val);
            j++;
        }
        if(q->tuple[j].row == p->tuple[i].row && q->tuple[j].col == p->tuple[i].row) {
            setRowSparseMatrix(r, p->tuple[i].row, p->tuple[i].col, p->tuple[i].val + q->tuple[i].val);
        }
        else {
            setRowSparseMatrix(r, p->tuple[i].row, p->tuple[i].col, p->tuple[i].val);
        }
        i++;
    }
}

int main(){
    return 0;
}