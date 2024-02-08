#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int *a;
int size;

void mergeSort(int l, int r);
void merge(int l, int m, int r);

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    a = (int*)malloc(size*sizeof(int));

    printf("Enter the elements in the array\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    mergeSort(0, size - 1);

    for(int i = 0; i < size; i++) {
        printf("%d  ", a[i]);
    }

    return 0;
}

void mergeSort(int l, int r) {
    if(l >= r) return;

    int m = l + (r - l)/2;

    mergeSort(l, m);
    mergeSort(m + 1, r);

    merge(l, m, r); 
    return;
}

void merge(int l, int m, int r) {
    int len = r - l + 1;
    int* c = (int*)malloc(len*sizeof(int));

    int i = l, j = m + 1, k = 0;

    while(i <= m && j <= r) {
        if(a[i] <= a[j]) c[k++] = a[i++];
        else c[k++] = a[j++];
    }
    while(i <= m) c[k++] = a[i++];
    while(j <= r) c[k++] = a[j++];

    k = 0;

    for(int i = l; i <= r; i++) {
        a[i] = c[k++];
    }

    return;
}
