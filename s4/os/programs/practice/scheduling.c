#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

#define min(a,b) (a < b)? a : b;
#define max(a,b) (a > b)? a : b;

//#define NUM_PROCS 5
//#define TIME_QUANTUM 2

typedef struct proc_t proc_t;

struct proc_t {
    int at, bt, ct, tat, wt, rt;
};

int get_rand() {
    return rand() % 10 + 1;
}

void swap_procs(proc_t* p, proc_t* q) {
    proc_t r = *p;
    *p = *q;
    *q = r;
    return;
}

void sort_procs(proc_t* procs, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if((&procs[j])->at > (&procs[j + 1])->at) swap_procs(&procs[j], &procs[j + 1]);
        }
    }
    return;
}

void print_stats(proc_t* procs, int n) {
    printf("stats_begin\n");
    for(int i = 0; i < n; i++) {
        proc_t* proc = &procs[i];
        printf("Process %d -> at: %d, bt: %d, ct: %d, tat: %d, wt: %d, rt: %d \n", i, proc->at, proc->bt, proc->ct, proc->tat, proc->wt, proc->rt);
    }
    printf("stats_end\n\n");
    return;
}

proc_t* get_procs(int n) {
    proc_t* procs = (proc_t*)malloc(n*sizeof(proc_t));

    int manual;
    printf("Manually set processes? (1/0): ");
    scanf("%d", &manual);
    for(int i = 0; i < n; i++) {
        proc_t* proc = &procs[i];
        if(manual) {
            printf("Enter the arrival time and burst time for process %d: ", i);
            scanf("%d%d", &proc->at, &proc->bt);
        }
        else {
            proc->at = get_rand();
            proc->bt = get_rand();
        }
        proc->rt = proc->bt;
        proc->ct = proc->tat = proc->wt = 0;
    }
    sort_procs(procs, n);
    return procs;
}

proc_t* reset_procs(proc_t* procs, int n) {
    for(int i = 0; i < n; i++) {
        proc_t* proc = &procs[i];
        proc->rt = proc->bt;
        proc->ct = proc->tat = proc->wt = 0;
    }
    return procs;
}

void run_round_robin(proc_t* procs, int n, int tq) {
    printf("round_robin_begin\n");
    int end_cnt = 0;
    int i = 0; 
    int elapsed = 0;
    while(true) { //time quantum
        int t_left = tq;        
        while(t_left > 0) { //run processes within one time quantum
            proc_t* proc = &procs[i];

            if(proc->rt == 0) {
                i = (i + 1) % n;
            }

            if(proc->at > elapsed) {
                elapsed = proc->at;
                t_left = (ceil(elapsed*1.0/tq)*tq) - elapsed;
            }

            if(proc->rt > t_left) {
                elapsed += t_left;
                proc->rt -= t_left;
                t_left = 0;
            }
            else {
                elapsed += proc->rt;
                t_left -= proc->rt;
                
                proc->rt = 0;
                proc->ct = elapsed;
                proc->tat = proc->ct - proc->at;
                proc->wt = proc->tat - proc->bt;

                if(++end_cnt == n) goto outer;
                if(t_left != 0) i = (i + 1) % n;
            }
        }
        i = (i + 1) % n;
    }
outer:
    printf("round_robin_end\n\n");
    print_stats(procs, n);
    return;
}

void run_fcfs(proc_t* procs, int n) {
    printf("fcfs_begin\n");
    int elapsed = 0;
    for(int i = 0; i < n; i++) {
        proc_t* proc = &procs[i];
        elapsed += proc->rt;
        proc->rt = 0;
        proc->ct = elapsed;
        proc->tat = proc->ct - proc->at;
        proc->wt = proc->tat - proc->bt;
    }
    printf("fcfs_end\n\n");
    print_stats(procs, n);
    return;
}

int main(int argc, char* argv[]) {
    srand(time(0));

    int NUM_PROCS, TIME_QUANTUM;
    
    printf("Enter NUM_PROCS and TIME_QUANTUM: ");
    scanf("%d%d", &NUM_PROCS, &TIME_QUANTUM);

    proc_t* procs = get_procs(NUM_PROCS);

    print_stats(procs, NUM_PROCS);

    run_round_robin(procs, NUM_PROCS, TIME_QUANTUM);

    procs = reset_procs(procs, NUM_PROCS);

    print_stats(procs, NUM_PROCS);

    run_fcfs(procs, NUM_PROCS);

    return 0;
}
