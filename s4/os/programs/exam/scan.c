#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    int n; 
    printf("enter the number of disk request sequence: ");
    scanf("%d", &n);
    int* seq = (int*)malloc(n*sizeof(int));
    printf("enter the disk request sequence: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
    }
    int head;
    printf("enter initial position of head pointer: ");
    scanf("%d", &head);
    int cyl = 0;
    int pos = 0;
    sort(seq, n);
    while (seq[pos] < head && pos < n) pos++;
    if (pos == n) pos = -1;
    else if (seq[pos] != head) pos--;
    for (int i = pos; i >= 0; i--) {
        if(i == pos) cyl += abs(seq[i] - head);
        else cyl += abs(seq[i] - seq[i + 1]);
        printf("*: %d\n", seq[i]);
        printf("cyl: %d\n", cyl);
    }
    cyl += (n != 0? seq[0] : 0) + (pos != n - 1? seq[pos + 1]: 0); 
    printf("hitting 0\n");
    printf("hitting %d\n", pos + 1);
    printf("cyl: %d\n", cyl);
    for (int i = pos + 2; i < n; i++) {
        cyl += abs(seq[i] - seq[i - 1]);
        printf("*: %d\n", seq[i]);
        printf("cyl: %d\n", cyl);
    }
    printf("No: of cylinders: %d", cyl);
    return 0;
}
