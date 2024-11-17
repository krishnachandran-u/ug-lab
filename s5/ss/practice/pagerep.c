#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

int n_r, n_f;
int *r, *f, *ps; 
int hits = 0, miss = 0;

void load() {
    FILE* fp = fopen("pagerep.txt", "r");
    fscanf(fp, "%d%d", &n_r, &n_f);
    r = (int*)malloc(n_r*sizeof(int));
    f = (int*)malloc(n_f*sizeof(int));
    ps = (int*)malloc(n_f*sizeof(int));
    for(int i = 0; i < n_r; i++) {
        fscanf(fp, "%d", &r[i]);
    }
    for (int i = 0; i < n_f; i++) {
        f[i] = -1;
        ps[i] = 0;
    }
    return;
}

void print_frames() {
    for (int i = 0; i < n_f; i++) {
        printf("%d\t", f[i]);
    }
    printf("\n");
    return;
}

void run_fifo() {
    for (int i = 0; i < n_r; i++) {
        for (int j = 0; j < n_f; j++) {
            if (f[j] == r[i]) {
                hits++;
                print_frames();
                goto skip;
            }
        }
        int fst = INT_MAX;
        int fst_i = -1;
        for (int j = 0; j < n_f; j++) {
            if (ps[j] < fst) {
                fst = ps[j];
                fst_i = j;
            }
        }
        f[fst_i] = r[i];
        ps[fst_i] = i;
        miss++;
        print_frames();
        skip:;
    }
    printf("hit ratio: %f\nmiss ratio: %f\n", (float)hits/n_r, (float)miss/n_r);
    return;
}

int main() {
    load();
    run_fifo();
    return 0;
}
