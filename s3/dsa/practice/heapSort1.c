#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int *a;
int size;

void heapSort();
void heapify(int n, int i);
void swap(int* a, int* b);

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    a = (int*)malloc(size*sizeof(int));

    printf("Enter the elements of the array:\n");
    for(int i = 0; i < size; i++) {
        scanf("%d", &a[i]);
    }

    heapSort();

    for(int i = 0; i < size; i++) {
        printf("%d  ", a[i]);
    }

    return 0;
}


void heapSort() {
    for(int i = size/2 - 1; i >= 0; i--) {
        heapify(size, i);
    }
    for(int i = size - 1; i >= 0; i--) {
        swap(&a[i], &a[0]);
        heapify(i, 0);
    }

    return;
}

void heapify(int n, int i) {
    int largest = i;    
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && a[left] > a[largest]) largest = left;
    if(right < n && a[right] > a[largest]) largest = right;

    if(largest != i) {
        swap(&a[i], &a[largest]);
        heapify(n, largest);
    }

    return;
}

void swap(int *a, int *b) {
    int p = *a;
    *a = *b;
    *b = p;

    return;
}


