#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int *a;
int size;

void swap(int *a, int *b) {
    int p = *a;
    *a = *b;
    *b = p;
    return;
}

void selectionSort() {
    for(int i = 0; i < size; i++) {
        int min = INT_MAX;
        int min_j = -1;
        for(int j = i; j < size; j++) {
            if(a[j] < a[i]) {
                min = a[j];
                min_j = j;
            }
        }
        if(min_j != -1) swap(&a[i], &a[min_j]);
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

    selectionSort();

    for(int i = 0; i < size; i++) {
        printf("%d  ", a[i]);
    }

    return 0;
}

