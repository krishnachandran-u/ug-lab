#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

#define CAP 1000

typedef struct queue queue;

int min(int a, int b) { return (a < b)? a: b; }
int max(int a, int b) { return (a > b)? a: b; }

struct queue {
    int f, r, size;
    int a[CAP];
};

void init(queue* q) {
    q->f = 0;
    q->r = -1;
    q->size = 0;
    return;
}

queue* get_queue() {
    queue* q = (queue*)malloc(sizeof(queue));
    init(q);
    return q;
}

bool is_empty(queue* q) {
    return q->size == 0;
}

bool is_full(queue* q) {
    return q->size == CAP;
}

void push(queue* q, int x) {
    if(is_full(q)) {
        perror("overflow");
        exit(1);
    }
    q->a[++q->r] = x;
    q->size++;
    return;
}

void pop(queue* q) {
    if(is_empty(q)) {
        perror("underflow");
        exit(1);
    }
    q->f++;
    q->size--;
    return;
}

int front(queue* q) {
    if(is_empty(q)) {
        perror("underflow");
        exit(1);
    }
    return q->a[q->f];
}

int rear(queue* q) {
    if(is_empty(q)) {
        perror("underflow");
        exit(1);
    }
    return q->a[q->r];
}

void delete(queue* q, int x) {
    for(int i = q->f; i <= q->r; i++) {
        if(q->a[i] == x) {
            for(int j = i; j < q->r; j++) {
                q->a[j] = q->a[j + 1]; 
            }
            q->r--;
            q->size--;
            return;
        }
    }
    return;
}

void swap(int *a, int* b) {
    int p = *a;
    *a = *b;
    *b = p;
    return;
}

void print_table(int i, int page, char* status, int* frms, int f_size) {
    printf("%d -> %d:%s\t[\t", i, page, status);
    for(int i = 0; i < f_size; i++) {
        printf("%d\t", frms[i]);
    }
    printf("]\n");
    return;
}

void run_fifo(int* ref, int r_size, int f_size) {
    queue* q = get_queue();

    int* frms = (int*)malloc(f_size*sizeof(int));
    for(int i = 0; i < f_size; i++) frms[i] = -1;

    int hit_cnt = 0;
    int miss_cnt = 0;

    for(int i = 0; i < r_size; i++) {

        bool done = false;

        for(int j = 0; j < f_size; j++) {
            //hit
            if(frms[j] == ref[i]) {
                hit_cnt++;                    
                done = true;
                break;
            }
        }

        if(done) {
            print_table(i, ref[i], "hit", frms, f_size);
            continue;
        }


        //check for empty frames;
        for(int j = 0; j < f_size; j++) {
            if(frms[j] == -1) {
                frms[j] = ref[i];                    
                miss_cnt++;
                push(q, ref[i]);
                done = true;
                break;
            }
        }

        if(done) {
            print_table(i, ref[i], "miss", frms, f_size);
            continue;
        }

        //remove a frame
        int rep = front(q);

        for(int j = 0; j < f_size; j++) {
            if(frms[j] == rep) {
                frms[j] = ref[i];
                miss_cnt++;
                pop(q);
                push(q, ref[i]);
                done = true;
                break;
            }
        }

        if(done) {
            print_table(i, ref[i], "miss", frms, f_size);
            continue;
        }
    }


    printf("\n");
    printf("hit count: %d\n", hit_cnt);
    printf("miss_count: %d\n", miss_cnt);
    printf("hit rate: %f\n", 1.0*hit_cnt/r_size);
    printf("miss_rate: %f\n", 1.0*miss_cnt/r_size);

    return;
}

void run_lru(int* ref, int r_size, int f_size) {
    queue* q = get_queue();

    int* frms = (int*)malloc(f_size*sizeof(int));
    for(int i = 0; i < f_size; i++) frms[i] = -1;

    int hit_cnt = 0;
    int miss_cnt = 0;

    for(int i = 0; i < r_size; i++) {

        bool done = false;

        for(int j = 0; j < f_size; j++) {
            //hit
            if(frms[j] == ref[i]) {
                delete(q, ref[i]); // only difference from fifo
                push(q, ref[i]); // only difference from fifo
                hit_cnt++;                    
                done = true;
                break;
            }
        }

        if(done) {
            print_table(i, ref[i], "hit", frms, f_size);
            continue;
        }


        //check for empty frames;
        for(int j = 0; j < f_size; j++) {
            if(frms[j] == -1) {
                frms[j] = ref[i];                    
                miss_cnt++;
                push(q, ref[i]);
                done = true;
                break;
            }
        }

        if(done) {
            print_table(i, ref[i], "miss", frms, f_size);
            continue;
        }

        //remove a frame
        int rep = front(q);

        for(int j = 0; j < f_size; j++) {
            if(frms[j] == rep) {
                frms[j] = ref[i];
                miss_cnt++;
                pop(q);
                push(q, ref[i]);
                done = true;
                break;
            }
        }

        if(done) {
            print_table(i, ref[i], "miss", frms, f_size);
            continue;
        }
    }


    printf("\n");
    printf("hit count: %d\n", hit_cnt);
    printf("miss_count: %d\n", miss_cnt);
    printf("hit rate: %f\n", 1.0*hit_cnt/r_size);
    printf("miss_rate: %f\n", 1.0*miss_cnt/r_size);

    return;
}

void run_lfu(int* ref, int r_size, int f_size) {
    queue* q = get_queue();

    int* frms = (int*)malloc(f_size*sizeof(int));
    for(int i = 0; i < f_size; i++) frms[i] = -1;

    int cnt[1000];
    memset(cnt, 0, 1000*sizeof(int)); 

    int hit_cnt = 0;
    int miss_cnt = 0;

    for(int i = 0; i < r_size; i++) {

        bool done = false;

        for(int j = 0; j < f_size; j++) {
            //hit
            if(frms[j] == ref[i]) {
                delete(q, ref[i]); // only difference from fifo
                push(q, ref[i]); // only difference from fifo
                hit_cnt++;                    
                cnt[ref[i]]++;
                done = true;
                break;
            }
        }

        if(done) {
            print_table(i, ref[i], "hit", frms, f_size);
            continue;
        }


        //check for empty frames;
        for(int j = 0; j < f_size; j++) {
            if(frms[j] == -1) {
                frms[j] = ref[i];                    
                push(q, ref[i]);
                miss_cnt++;
                cnt[ref[i]]++;
                done = true;
                break;
            }
        }

        if(done) {
            print_table(i, ref[i], "miss", frms, f_size);
            continue;
        }

        //lfu
        int lf_cnt = INT_MAX;  
        int lf_j = -1;
        for(int j = 0; j < f_size; j++) {
            if(cnt[frms[j]] < lf_cnt) {
                lf_cnt = cnt[frms[j]];
                lf_j = j;
            }
        }

        queue* lf_q = get_queue();

        printf("\n");
        for(int j = 0; j < f_size; j++) {
            if(cnt[frms[j]] == lf_cnt) {
                push(lf_q, j);
            }
            //printf("%d -> %d\t", frms[j], cnt[frms[j]]);
        }
        //printf("\n");
            
        if(lf_q->size == 1) {
            frms[lf_j] = ref[i];
            cnt[ref[i]]++;
            delete(q, frms[lf_j]);
            push(q, ref[i]);
            miss_cnt++;
            done = true;
        }
        
        if(done) {
            print_table(i, ref[i], "miss", frms, f_size);
            continue;
        }

        //tiebreaker using lru
        int oldest = -1;
        int oldest_k = INT_MAX;

        for(int j = lf_q->f; j <= lf_q->r; j++) {
            for(int k = q->f; k <= q->r; k++) {
                if(frms[lf_q->a[j]] == q->a[k]) {
                    if(k < oldest_k) {
                        oldest_k = k;
                        oldest = q->a[k];
                        break;
                    }
                }
            }
        }

        delete(q, oldest); 
        for(int j = 0; j < f_size; j++) {
            if(frms[j] == oldest) {
               frms[j] = ref[i]; 
               break;
            }
        }

        push(q, ref[i]);
        cnt[ref[i]]++;
        miss_cnt++;
        done = true;

        if(done) {
            print_table(i, ref[i], "miss", frms, f_size);
            continue;
        }
    }

    printf("\n");
    printf("hit count: %d\n", hit_cnt);
    printf("miss_count: %d\n", miss_cnt);
    printf("hit rate: %f\n", 1.0*hit_cnt/r_size);
    printf("miss_rate: %f\n", 1.0*miss_cnt/r_size);

    return;
}


int main() {
    int r_size, f_size;

    printf("Enter length of reference string and number of frames: ");
    scanf("%d%d", &r_size, &f_size);
    
    int *ref = (int*)malloc(r_size*sizeof(int));
      
    printf("Enter the ref string: ");
    for(int i = 0; i < r_size; i++) {
        scanf("%d", &ref[i]); 
    }
    printf("\n");

    printf("\nfifo\n");
    run_fifo(ref, r_size, f_size);
    printf("\nlru\n");
    run_lru(ref, r_size, f_size);
    printf("\nlfu\n");
    run_lfu(ref, r_size, f_size);
    
    return 0;
}
