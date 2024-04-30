#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <assert.h>

int* get_copy(int* req, int n) {
    int* copy = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++) copy[i] = req[i];
    return copy;
}

void run_fcfs(int* req, int n, int head) {
    int cyl = 0;
    printf("%d ", head);

    int prev = head;
    for(int i = 0; i < n; i++) {
        printf("%d ", req[i]);
        cyl += abs(req[i] - head);
        prev = req[i];
    }
    printf("\nNo: of cylinders moved: %d\n", cyl);
    return;
}

void run_sstf(int* req, int n, int head) {
    int cyl = 0;
    printf("%d ", head);

    int prev = head;
    for(int i = 0; i < n; i++) {
        int min = INT_MAX;
        int min_j = -1;
        for(int j = 0; j < n; j++) {
            if(req[j] != -1 && abs(req[j] - prev) < min) {
                min_j = j;
            }
        }
        printf("%d ", req[min_j]);
        cyl += abs(req[min_j] - prev);
        prev = req[min_j];
        req[min_j] = -1;
    }
    printf("\nNo: of cylinders moved: %d\n", cyl);
}

int* sort(int* a, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(a[j] > a[j + 1]) {
                int temp = a[j]; 
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    return a;
}

void run_scan(int* req, int n, int head) {
    req = sort(req, n);
    int cyl = 0;
    int i = 0;
    int st = -1;
    printf("%d ", head);
    while(i < n) {
        if(req[i] < head) {
            st = i;
            i++;
        }
        else break;
    }
    int prev;
    for(int j = st; j >= 0; j--) {
        cyl += abs(req[j] - prev);
        prev = req[j];
        printf("%d ", req[j]);
    }
    printf("0 ");
    cyl += prev;
    prev = 0;
    for(int j = st + 1; j < n; j++) {
        cyl += abs(req[j] - prev);
        prev = req[j];
        printf("%d ", req[j]);
    }
    printf("\nNo: of cylinders moved: %d\n", cyl);
}

void run_cscan(int* req, int n, int head) {
    req = sort(req, n);
    int cyl = 0;
    int i = 0;
    int st = -1;
    printf("%d ", head);
    while(i < n) {
        if(req[i] < head) {
            st = i;
            i++;
        }
        else break;
    }
    int prev;
    for(int j = st; j >= 0; j--) {
        cyl += abs(req[j] - prev);
        prev = req[j];
        printf("%d ", req[j]);
    }
    printf("0 199 ");
    cyl += prev;
    prev = 199;
    for(int j = n - 1; j >= st + 1; j--) {
        cyl += abs(req[j] - prev);
        prev = req[j];
        printf("%d ", req[j]);
    }
    printf("\nNo: of cylinders moved: %d\n", cyl);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    int* req = (int*)malloc(n*sizeof(int));

    printf("Enter the sequence: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &req[i]);
    }

    int head;
    printf("Enter head: ");
    scanf("%d", &head);

    printf("\nFCFS\n");
    run_fcfs(get_copy(req, n), n, head);

    printf("\nSSTF\n");
    run_sstf(get_copy(req, n), n, head);

    printf("\nSCAN\n");
    run_scan(get_copy(req, n), n, head);

    printf("\nCSCAN\n");
    run_cscan(get_copy(req, n), n, head);

    return 0;
}

