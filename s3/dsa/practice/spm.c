#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct SparseMatrix {
    int r[100], c[100], v[100], size, n, m;
};

typedef struct SparseMatrix SparseMatrix;

SparseMatrix* create(int n, int m) {
    SparseMatrix* spm = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    spm->n = n;
    spm->m = m;
    spm->size = 0;

    printf("Enter the matrix as a matrix: ");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            if(x != 0) {
                spm->r[spm->size] = i;
                spm->c[spm->size] = j;
                spm->v[spm->size] = x;
                spm->size++;
            }
        }
    }
    return spm;
}

void display(SparseMatrix* spm) {
    printf("row | column | value\n");
    for(int i = 0; i < spm->size; i++) {
        printf("%d | %d | %d\n", spm->r[i], spm->c[i], spm->v[i]);
    }
    return;
}

SparseMatrix* transpose(SparseMatrix* spm) {
    SparseMatrix* tpm = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    tpm->size = 0;
    tpm->n = spm->m;
    tpm->m = spm->n;
    for(int i = 0; i < spm->m; i++) {
        for(int j = 0; j < spm->size; j++) {
            if(spm->c[j] == i) {
                tpm->r[tpm->size] = i;
                tpm->c[tpm->size] = spm->r[j];
                tpm->v[tpm->size] = spm->v[j];
                tpm->size++;
            }
        }
    }
    return tpm;
}

SparseMatrix* getSum(SparseMatrix* spm, SparseMatrix* tpm) {
    if(spm->n != tpm->n || spm->m != tpm->n) {
        printf("not possible. null pointer returned\n");
        return NULL;
    }
    SparseMatrix* rpm = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    rpm->size = 0;
    for(int i = 0, j = 0; i < spm->size || j < tpm->size;) {
        bool valid = (i < spm->size && j < tpm->size);
        while(valid && spm->r[i] < tpm->r[j]) {
            rpm->r[rpm->size] = spm->r[i];
            rpm->c[rpm->size] = spm->c[i];
            rpm->v[rpm->size] = spm->v[i];
            rpm->size++; i++;
        }
        if(valid && spm->r[i] == tpm->r[j]) {
            rpm->r[rpm->size] = spm->r[i];
            rpm->c[rpm->size] = spm->c[i];
            rpm->v[rpm->size] = spm->v[i] + tpm->v[j];
            rpm->size++; i++; j++;
        }
        else if(valid) {
            rpm->r[rpm->size] = tpm->r[j];
            rpm->c[rpm->size] = tpm->c[j];
            rpm->v[rpm->size] = tpm->v[j];
            rpm->size++; j++;
        }
        else if(i < spm->size) {
            rpm->r[rpm->size] = spm->r[i];
            rpm->c[rpm->size] = spm->c[i];
            rpm->v[rpm->size] = spm->v[i];
            rpm->size++; i++;
        }
        else {
            rpm->r[rpm->size] = tpm->r[j];
            rpm->c[rpm->size] = tpm->c[j];
            rpm->v[rpm->size] = tpm->v[j];
            rpm->size++; j++;
        }
    }
    return rpm;
}

int main() {
    int n, m;   
    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d%d", &n, &m);
    SparseMatrix* spm = create(n, m);
    display(spm);
    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d%d", &n, &m);
    SparseMatrix* tpm = create(n, m);
    display(tpm);
    SparseMatrix* spmTranspose = transpose(spm);  
    display(spmTranspose);
    SparseMatrix* rpm = getSum(spm, tpm);
    display(rpm);
    return 0;
}
