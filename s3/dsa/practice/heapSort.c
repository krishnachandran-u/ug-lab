#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int size;
int* a;

void heapSort();
void heapify(int len, int i);
void swap(int* a, int* b);

int main() {
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    a = (int*)malloc(size*sizeof(int));

    printf("Enter the elements in the array: ");
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
}

void heapify(int len, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < len && a[left] > a[largest]) largest = left;
    if(right < len && a[right] > a[largest]) largest = right;

    if(largest != i) {
        swap(&a[largest], &a[i]);
        heapify(len, largest);
    }
}

void swap(int* a, int* b) {
    int p = *a;
    *a = *b;
    *b = p;
    return;
}
