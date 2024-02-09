#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int* a;
int size;

void swap(int *a, int *b) {
    int p = *a;
    *a = *b;
    *b = p;
    return;
}

void insertionSort() {
    for(int i = 1; i < size; i++) {
        int j = 0;
        while(j < i && a[j] <= a[i]) j++;
        int t = a[i];
        for(int k = i - 1; k >= j; k--) a[k + 1] = a[k];
        a[j] = t;
    }
    return;
}

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    a = (int*)malloc(size*sizeof(int));

    printf("Enter the elements of the array: ");
    for(int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    insertionSort();

    for(int i = 0; i < size; i++) {
        printf("%d  ", a[i]);
    }
}

