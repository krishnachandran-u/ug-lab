#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int* a;
int size;

void quickSort(int l, int r);
int split(int l, int r);
void swap(int *a, int *b);

int main() {
    printf("enter the size of the array: ");
    scanf("%d", &size);

    a = (int*)malloc(size*sizeof(int));

    printf("enter %d elements:\n", size);
    for(int i = 0; i < size; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }

    quickSort(0, size - 1);

    for(int i = 0; i < size; i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");

    return 0;
}

void quickSort(int l, int r) {
    if(l >= r) return;

    int p = split(l, r);

    quickSort(l, p - 1);
    quickSort(p + 1, r);

    return;
}

int split(int l, int r) {
    int pivot = a[l];

    int cnt = 0;
    for(int i = l + 1; i <= r; i++) {
        cnt += (a[i] <= pivot);
    }

    int p = l + cnt;

    swap(&a[p], &a[l]);

    int i = l, j = r;
    while(i < p && j > p) {
        while(i < p && a[i] <= pivot) i++;
        while(j > p && a[j] > pivot) j--;
        if(i < p && j > p) swap(&a[i++], &a[j--]);
    }

    return p;
}

void swap(int* x, int* y) {
    int p = *x;
    *x = *y;
    *y = p;
    return;
}
