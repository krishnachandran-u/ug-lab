#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <unistd.h>
#include <stdbool.h>

#define QUEUE_SIZE 100
#define TQ 2

typedef struct proc_t proc_t;
typedef struct queue queue;

struct proc_t {
    int pid, at, bt, ct, tat, wt, rt, p;  
};

struct queue {
    int f, r, sz;
    proc_t a[QUEUE_SIZE];
};

bool is_full(queue*);
bool is_empty(queue*);
queue* get_q();
void enq(queue*, proc_t);
void dq(queue*);
proc_t front(queue*);
proc_t rear(queue*);
proc_t* get_procs(int);
proc_t* get_copy(proc_t*, int);
void print_gantt(int, int);
void print_stats(proc_t*, int);
void run_rr(proc_t*, int, int);


int main() {
    int n;
    printf("enter the number of process: ");
    scanf("%d", &n);
    proc_t* procs = get_procs(n);
    printf("\nround robin\n");
    run_rr(get_copy(procs, n), n, TQ);
    printf("\n");
}


bool is_full(queue* q) {
    return q->sz == QUEUE_SIZE;
}

bool is_empty(queue* q) {
    return q->sz == 0;
}

queue* get_q() {
    queue* q = (queue*)malloc(sizeof(queue));    
    q->sz = q->f = q->r = 0;
    return q;
}

void enq(queue* q, proc_t proc) {
    if (is_full(q)) {
        perror("queue full");
        exit(1);
    }
    q->a[q->r] = proc;
    q->r++;
    q->sz++;
}

void dq(queue* q) {
    if (is_empty(q)) {
        perror("queue empty");
        exit(1);
    }
    q->f++;
    q->sz--;
}

proc_t front(queue* q) {
    if (is_empty(q)) {
        perror("queue empty");
        exit(1);
    }
    return q->a[q->f];    
}

proc_t rear(queue* q) {
    if (is_empty(q)) {
        perror("queue empty");
        exit(1);
    }
    return q->a[q->r];
}

proc_t* get_procs(int n) {
    proc_t* procs = (proc_t*)malloc(n*sizeof(proc_t));

    for (int i = 0; i < n; i++) {
        printf("enter at, bt, p of process[%d]: ", i);
        scanf("%d%d%d", &procs[i].at, &procs[i].bt, &procs[i].p);
        procs[i].rt = procs[i].bt;
        procs[i].tat = procs[i].wt = 0;
        procs[i].pid = i;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (procs[j].at > procs[j + 1].at) {
                proc_t temp = procs[j];
                procs[j] = procs[j + 1];
                procs[j + 1] = temp;
            }
        }
    }

    return procs;
}

proc_t* get_copy(proc_t* procs, int n) {
    proc_t* copy = (proc_t*)malloc(n*sizeof(proc_t));
    for (int i = 0; i < n; i++) {
        copy[i] = procs[i];
    }
    return procs;
}

void print_gantt(int pid, int end) {
    printf("P:%d <%d>", pid, end); 
    return;
}

void print_stats(proc_t* procs, int n) {
    for (int i = 0; i < n; i++) {
        printf("P:%d -> at: %d | bt: %d | p: %d | ct: %d | rt: %d | tat: %d | wt: %d\n", procs[i].pid, procs[i].at, procs[i].bt, procs[i].p, procs[i].ct, procs[i].rt, procs[i].tat, procs[i].wt);
    }
}

void run_rr(proc_t* procs, int n, int tq) {
    queue* q = get_q();
    for (int i = 0; i < n; i++) {
        enq(q, procs[i]);
    }
    int t_tat = 0;
    int t_wt = 0;
    int elap = 0;

    while (!is_empty(q)) {
        proc_t proc = front(q);
        dq(q);

        if (proc.at > tq) {
            print_gantt(-1, proc.at);
            elap = proc.at;
        }

        if (proc.rt > tq) {
            elap += tq;
            proc.rt -= tq;
            enq(q, proc);
            print_gantt(-1, elap);
        }
        else {
            elap += proc.rt;
            proc.rt = 0;
            print_gantt(proc.pid, elap);
            proc.ct = elap;
            proc.tat = proc.ct - proc.at;
            t_tat += proc.tat;
            proc.wt = proc.tat - proc.bt;
            t_wt += proc.wt;
            
        }
    }
    printf("avg tat: %f", (1.0*t_tat)/n);
    printf("avg wt: %f", (1.0*t_wt)/n);
    print_stats(procs, n);
}

void run_sjf(proc_t* procs, int n) {
    int fin = 0;
    int elap = 0;
    int t_tat = 0;
    int t_wt = 0;
    
    while (fin < n) {
        int min_bt = INT_MAX;
        int min_i = -1;

        for (int i = 0; i < n; i++) {
            if(procs[i].rt > 0 && procs[i].bt < min_bt && procs[i].at <= elap) {
                min_bt = procs[i].bt;
                min_i = i;
            }
        }

        if(min_i == -1) {
            for (int i = 0; i < n; i++) {
                if(procs[i].rt > 0 && procs[i].at > elap) {
                    elap = procs[i].at;
                    print_gantt(-1, elap);
                    break;
                }
            }
        }
        else {
            elap += procs[min_i].rt;
            procs[min_i].rt = 0;
            procs[min_i].ct = elap;
            procs[min_i].tat = procs[min_i].ct -procs[min_i].at;
            procs[min_i].wt = procs[min_i].tat -procs[min_i].bt;
            t_tat += procs[min_i].tat;
            t_wt += procs[min_i].wt;
            print_gantt(min_i, elap);
            fin++;
        }
    }
    printf("avg tat: %f", (1.0*t_tat)/n);
    printf("avg wt: %f", (1.0*t_wt)/n);
    print_stats(procs, n);
}

void run_fcfs(proc_t* procs, int n) {
    int t_tat = 0;
    int t_wt = 0;
    int elap = 0;

    for (int i = 0; i < n; i++) {
        if(procs[i].at > elap) {
            elap = procs[i].at;
            print_gantt(-1, elap);
        }

        elap += procs[i].rt;  
        procs[i].rt = 0;
        procs[i].ct = elap;
        procs[i].tat = procs[i].ct - procs[i].at;
        procs[i].wt = procs[i].tat - procs[i].bt;
        t_tat += procs[i].tat;
        t_wt += procs[i].wt;
        print_gantt(procs[i].pid, elap);  
    }

    printf("avg tat: %f", (1.0*t_tat)/n);
    printf("avg wt: %f", (1.0*t_wt)/n);
    print_stats(procs, n);
}

void run_priority(proc_t* procs, int n) {
    int t_tat = 0;
    int t_wt = 0;
    int elap = 0;

    int fin = 0;

    while (fin < n) {
        int p = INT_MAX;
        int p_i = -1;
        for(int i = 0; i < n; i++) {
            if(procs[i].at <= elap && procs[i].p < p && procs[i].rt > 0) {
                p = procs[i].p;
                p_i = i;
            }
        }

        if (p_i == -1) {
            for(int i = 0; i < n; i++) {
                if(procs[i].at > elap && procs[i].rt > 0) {
                    elap = procs[i].at;
                    print_gantt(-1, elap);
                    break;
                }
            }
        }
        else {
            elap += procs[p_i].rt;
            procs[p_i].rt = 0;
            procs[p_i].ct = elap;
            procs[p_i].tat = procs[p_i].ct - procs[p_i].at;
            procs[p_i].wt = procs[p_i].tat - procs[p_i].bt;
            t_tat += procs[p_i].tat;
            t_wt += procs[p_i].wt;
            print_gantt(procs[p_i].pid, elap);
            fin++;
        }
    }

    printf("avg tat: %f", (1.0*t_tat)/n);
    printf("avg wt: %f", (1.0*t_wt)/n);
    print_stats(procs, n);
}
