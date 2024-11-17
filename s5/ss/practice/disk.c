// not complete easy ahhh 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

int L, H, n, head;
int *a;

void load() {
    FILE* fp = fopen("disk.txt", "r");
    fscanf(fp, "%d%d", &L, &H);
    fscanf(fp, "%d%d", &n, &head);
    a = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d", &a[i]);
    }
    fclose(fp);
    return;
}

void fcfs() {
    printf("fcfs\n");
    int ps = head, n_c = 0;
    for (int i = 0; i < n; i++) {
        n_c += abs(a[i] - ps);
        ps = a[i];  
        printf("%d\t", a[i]);
    }
    printf("\n");
    printf("Number of cylinders: %d\n", n_c);
    return;
}

void sstf() {
    printf("sjf\n");
    int ps = head, n_c = 0;
    for (int i = 0; i < n; i++) {
        int nr = INT_MAX;
        int nr_j = -1;
        for (int j = 0; j < n; j++) {
            if(a[j] != -1 && abs(ps - a[j]) < nr) {
                nr = ps - a[j]; 
                nr_j = j;
            }
        }
        printf("%d\t", a[nr_j]);
        n_c += a[nr_j];
        a[nr_j] = -1;
    }
    printf("\n");
    printf("Number of cylinders: %d\n", n_c);
    return;
}

int cmp(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

void scan() {
    printf("scan\n");
    int ps = head, n_c = 0;
    qsort(a, n, sizeof(int), cmp);
    int l = L - 1, r = H + 1;
    while(r - l > 1) {
        int m = l + (r - l)/2;
        if(a[m] <= ps) l = m;
        else r = m;
    }
    int i = l;  
    while(i >= 0) {
        n_c += abs(ps - a[i]);
        printf("%d\t", a[i]);
        ps = a[i];
        i--;
    }
    n_c += abs(ps - 0);
    ps = 0;
    i = r;
    while(i < n) {
        n_c += abs(ps - a[i]);
        printf("%d\t", a[i]);
        ps = a[i];
        i++;
    }
    return;
}

void cscan() {
    printf("cscan\n");
    int ps = head, n_c = 0;
    qsort(a, n, sizeof(int), cmp);
    int l = L - 1, r = H + 1;
    while(r - l > 1) {
        int m = l + (r - l)/2;
        if(a[m] <= ps) l = m;
        else r = m;
    }
    int i = l;  
    while(i >= 0) {
        n_c += abs(ps - a[i]);
        printf("%d\t", a[i]);
        ps = a[i];
        i--;
    }
    n_c += abs(ps - 0);
    ps = H;
    i = r;
    while(i > l) {
        n_c += abs(ps - a[i]);
        printf("%d\t", a[i]);
        ps = a[i];
        i--;
    }
    return;
}

int main() {

}
