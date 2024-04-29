#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define CAP 1000
#define TQ 5

typedef struct proc_t proc_t;
typedef struct queue queue;

//process
struct proc_t {
    int pid, at, bt, ct, tat, wt, rt; 
};

//queue
struct queue {
    int f, r, size;
    proc_t a[CAP];
};

queue* get_queue() {
    queue* q = (queue*)malloc(sizeof(queue));
    q->f = 0;
    q->r = -1;
    q->size = 0;
    return q;
}

bool is_empty(queue* q) {
    return q->size == 0;
}

bool is_full(queue* q) {
    return q->size == CAP;
}

void push(queue* q, proc_t x) {
    if(is_full(q)) {
        perror("push");
        exit(1);
    }
    q->a[++q->r] = x;
    q->size++;
    return;
}

void pop(queue* q) {
    if(is_empty(q)) {
        perror("pop");
        exit(1);
    }
    q->f++;
    q->size--;
    return;
}

proc_t front(queue* q) {
    if(is_empty(q)) {
        perror("front");
        exit(1);
    }
    return q->a[q->f];
}

proc_t rear(queue* q) {
    if(is_empty(q)) {
        perror("rear");
        exit(1);
    }
    return q->a[q->r];
}

void print_gantt(int pid, int end) {
    printf("P:%d <%d>", pid, end);
}

void print_stat(proc_t* procs, int n) {
    printf("\n");
    for(int i = 0;  i < n; i++) {
        printf("P:%d -> at: %d, bt: %d, ct: %d, tat: %d, wt: %d, rt: %d\n", procs[i].pid, procs[i].at, procs[i].bt, procs[i].ct, procs[i].tat, procs[i].wt, procs[i].rt);
    }
    return;
}

void run_rr(proc_t* procs, int n, int tq) {
    queue* q = get_queue();

    for(int i = 0; i < n; i++) {
        push(q, procs[i]);
    }

    int t_tat = 0;
    int t_wt = 0;

    int elap = 0;
    while(!is_empty(q)) {
        int t_lt = tq;
        proc_t proc = front(q);      
        pop(q);

        if(proc.at > elap) {
            print_gantt(-1, proc.at);
            elap = proc.at; 
        }

        if(proc.rt > t_lt) {
            print_gantt(proc.pid, elap + t_lt);

            proc.rt -= t_lt;
            elap += t_lt;
            t_lt = 0;

            push(q, proc);
        }
        else {
            print_gantt(proc.pid, elap + proc.rt);

            t_lt -= proc.rt;
            elap += proc.rt;
            proc.rt = 0;

            proc.ct = elap;
            proc.tat = proc.ct - proc.at;
            proc.wt = proc.tat - proc.bt;

            t_tat += proc.tat;
            t_wt += proc.wt;
            
            procs[proc.pid] = proc;
        }
    }
    print_stat(procs, n);   
    printf("avg tat: %f", 1.0*t_tat/n);
    printf("avg wq: %f", 1.0*t_wt/n);
    printf("\n");

    return;
}

proc_t* set_procs(int n) {
    proc_t* procs = (proc_t*)malloc(n*sizeof(proc_t));

    for(int i = 0; i < n; i++) {
        procs[i].pid = i;
        printf("Enter at and bt of process %d: ", procs[i].pid);
        scanf("%d%d", &procs[i].at, &procs[i].bt);
        procs[i].rt = procs[i].bt;
        procs[i].tat = procs[i].wt = 0;
    }
    return procs;
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    proc_t* procs = set_procs(n);
    
    run_rr(procs, n, TQ);

    return 0;
}
