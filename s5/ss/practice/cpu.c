#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAXLEN 100
#define max(a, b) a > b? a: b
#define min(a, b) a < b? a: b

int procs_len = 0;
int t;

struct proc_t {
    int at, bt, ct, tat, wt, rm; 
} *procs;

typedef struct proc_t proc_t;

void load_procs() {
    FILE* fp = fopen("cpu.txt", "r");
    //printf("Enter the number of processes: ");
    fscanf(fp, "%d", &procs_len);
    procs = (proc_t*)malloc(sizeof(proc_t)*procs_len);
    for (int i = 0; i < procs_len; i++) {
        //printf("Proc %d: Enter at, bt in order: ", i);
        fscanf(fp, "%d%d", &procs[i].at, &procs[i].bt);
        procs[i].ct = procs[i].tat = procs[i].wt = -1;
        procs[i].rm = procs[i].bt;
    }
    return;
}

void reset_procs() {
    for (int i = 0; i < procs_len; i++) {
        procs[i].ct = procs[i].tat = procs[i].wt = -1;
        procs[i].rm = procs[i].bt;
    }
    return;
}

void print_gantt(int i) {
    printf("< p%d >%d", i, t);
    return;
}

void print_stat() {
    printf("at\tbt\tct\ttat\twt\n");
    float avg_tat = 0, avg_wt = 0;
    for (int i = 0; i < procs_len; i++) {
        avg_tat += procs[i].tat;
        avg_wt += procs[i].wt;
        printf("%d\t%d\t%d\t%d\t%d\n", procs[i].at, procs[i].bt, procs[i].ct, procs[i].tat, procs[i].wt);  
    }
    avg_tat /= procs_len;
    avg_wt /= procs_len;
    printf("avg tat: %f\n", avg_tat);
    printf("avg wt: %f\n", avg_wt);
    return;
}

void run_fifo() {
    printf("fifo\n");
    t = 0;
    for (int i = 0; i < procs_len; i++) {
        if(procs[i].at > t) {
            t = procs[i].at;
            print_gantt(-1);
        }
        t += procs[i].bt;
        print_gantt(i);
        procs[i].rm = 0;
        procs[i].ct = t;
        procs[i].tat = procs[i].ct - procs[i].at;
        procs[i].wt = procs[i].tat - procs[i].bt;
    }
    printf("\n");
    print_stat();
    return;
}

void run_sjf() {
    printf("sjf\n");
    t = 0;
    for (int i = 0; i < procs_len; i++) {
        int pos = -1;
        int l_at = INT_MAX;
        int l_bt = INT_MAX;
        for (int j = 0; j < procs_len; j++) {
            if(procs[j].rm != 0) {
                if (procs[j].at < l_at) {
                    l_at = procs[j].at;
                    l_bt = procs[j].bt;
                    pos = j;
                }
                else if (procs[j].at == l_at && procs[j].bt < l_bt) {
                    //l_at = procs[i].at; 
                    l_bt = procs[j].bt;
                    pos = j;
                }
            }
            
        }
        if (t < l_at) {
            t = l_at;
            print_gantt(-1);
        }
        t += procs[pos].bt;
        print_gantt(pos);
        procs[pos].rm = 0;
        procs[pos].ct = t;
        procs[pos].tat = procs[pos].ct - procs[pos].at;
        procs[pos].wt = procs[pos].tat - procs[pos].bt;
    }
    printf("\n");
    print_stat();
    return;
}

int main() {
    load_procs();
    run_fifo();
    reset_procs();
    run_sjf();
    return 0;
}
