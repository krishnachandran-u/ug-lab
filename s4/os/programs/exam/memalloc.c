#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;
    printf("Enter the size of the memory block: ");
    scanf("%d", &size);
    int alloc_n;
    printf("Enter the number of allocations: ");
    scanf("%d", &alloc_n);
    int* seq = (int*)malloc(alloc_n*sizeof(int));
    printf("Enter the allocation sequence: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &seq[i]);
    }
    first_fit(get_copy(seq, alloc_n), alloc_n, size);
    best_fit(get_copy(seq, alloc_n), alloc_n, size);
    worst_fit(get_copy(seq, alloc_n), alloc_n, size);
    return 0;
}
