#include <stdio.h>
#include <stdlib.h>

void sort(int* arr, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return;
}

int main() {
    int len;
    printf("Enter the length: ");
    scanf("%d", &len);
    int* seq = (int*)malloc(len*sizeof(int));
    printf("Enter the seq: ");
    for (int i = 0; i < len; i++) {
        scanf("%d", &seq[i]); 
    }
    sort(seq, len);
    int head;
    printf("Enter the position of the head pointer: ");
    scanf("%d", &head);
    int pos = 0;
    while (seq[pos] <= head && pos < len) pos++;
    if (seq[pos] > head) pos--;
    if (pos == len) {
        perror("pos == n");
        exit(0);
    }
    int cyl = 0;
    for (int i = pos; i >= 0; i--) {
        if (i == pos) cyl += abs(seq[i] - head);
        else cyl += abs(seq[i] - seq[i + 1]);
        printf("i: %d\n", i);
        printf("*: %d\n", seq[i]);
        printf("cyl: %d\n", cyl);
    }
    cyl += seq[0];
    printf("hitting 0\n");
    printf("cyl: %d\n", cyl);
    cyl += 199;
    printf("hitting 199\n");
    printf("cyl: %d\n", cyl);
    for (int i = len - 1; i >= pos + 1; i--) {
        if (i == len - 1) cyl += abs(199 - seq[len - 1]);
        else cyl += abs(seq[i] - seq[i + 1]);
        printf("i: %d\n", i);
        printf("*: %d\n", seq[i]);
        printf("cyl: %d\n", cyl);
    }
    printf("cyl = %d\n", cyl);
    return 0;
}
