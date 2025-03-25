#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = fork();
    if (n > 0) {
        int sum = 0;
        for (int i = 1; i < 10; i+=2) {
            sum += a[i];
        }
        printf("Parent: %d\n", sum);
    }
    else if (n == 0) {
        int sum = 0;
        for (int i = 0; i < 10; i+=2) {
            sum += a[i];
        }
        printf("Child: %d\n", sum);
    }
    return 0;
}
