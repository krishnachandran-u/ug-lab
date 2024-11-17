#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int r, n;
int* avb;
int* seq;
int seq_cnt = 0;

struct Res {
    int* max;
    int* alloc;
    int* need;
    bool done;
} *res;

typedef struct Res Res;

void load() {
    FILE* fp = fopen("bankers.txt", "r");
    fscanf(fp, "%d%d", &n, &r);
    res = (Res*)malloc(n*sizeof(Res));
    avb = (int*)malloc(r*sizeof(int));
    seq = (int*)malloc(r*sizeof(int));
    for (int i = 0; i < n; i++) {
        res[i].max = (int*)malloc(r*sizeof(int));
        res[i].alloc = (int*)malloc(r*sizeof(int));
        for (int j = 0; j < r; j++) {
            fscanf(fp, "%d", &res[i].max[j]);
        }
        for (int j = 0; j < r; j++) {
            fscanf(fp, "%d", &res[i].alloc[j]);
        }
        for (int j = 0; j < r; j++) {
            res[i].need[j] = res[i].max[j] - res[i].alloc[j];
            res[i].done = false;
        }
    }
    for (int i = 0; i < r; i++) {
        fscanf(fp, "%d", &avb[i]);
    }
    return;
}

void run_bankers() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool feas = true;
            if (res[j].done) continue;
            for (int k = 0; k < r; k++) {
                if (res[j].need[k] > avb[k]) {
                    feas = false; 
                    break;
                }
            }
            if(feas) {
                seq[seq_cnt++] = j;
                for (int k = 0; k < r; k++) {
                    avb[k] += res[j].alloc[k];
                }
                res[j].done = true;
                break;
            }
        }
    }
}

void check_safe() {
    for (int i = 0; i < n; i++) {
        if(!res[i].done) {
            printf("No safe sequence");
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d\t", seq[i]);
    }
    return;
}
 
int main() {
    
}
