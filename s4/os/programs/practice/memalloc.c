#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int* get_clone(int* loc, int n) {
    int* clone = (int*)malloc(n*sizeof(int));
    for(int i = 0; i < n; i++) {
        clone[i] = loc[i]; 
    }
    return clone;
}

void run_first_fit(int* loc, int n, int* seq, int m) {
    printf("first_fit_begin\n");
    for(int i = 0; i < m; i++) {
        printf("%d:\t", seq[i]);
        for(int j = 0; j < n; j++) {
            if(seq[i] <= loc[j]) {
                loc[j] -= seq[i];
                printf("[successful]\t");
                break;
            }
            else if(j == n-1) {
                printf("[failed    ]\t");
            }
        }
        for(int j = 0; j < n; j++) {
            printf("%d\t", loc[j]); 
        }
        printf("\n");
    }
    printf("first_fit_end\n\n");
    return;
}

void run_best_fit(int* loc, int n, int* seq, int m) {
    printf("best_fit_begin\n");
    for(int i = 0; i < m; i++) {
        printf("%d:\t", seq[i]);

        int best = INT_MAX;
        int best_j = -1;

        for(int j = 0; j < n; j++) {
            if(seq[i] <= loc[j] && loc[j] < best) {
                best = loc[j];
                best_j = j;
            }
        }

        if(best_j != -1) {
            loc[best_j] -= seq[i];
            printf("[successful]\t");
        }
        else printf("[failed    ]\t");

        for(int j = 0; j < n; j++) {
            printf("%d\t", loc[j]); 
        }
        printf("\n");
    }
    printf("best_fit_end\n\n");
    return;
}

void run_worst_fit(int* loc, int n, int* seq, int m) {
    printf("worst_fit_begin\n");
    for(int i = 0; i < m; i++) {
        printf("%d:\t", seq[i]);
        
        int worst = INT_MIN;
        int worst_j = -1;

        for(int j = 0; j < n; j++) {
            if(loc[j] > worst) {
                worst = loc[j];
                worst_j = j;
            }
        }
        
        if(seq[i] <= worst) {
            loc[worst_j] -= seq[i];
            printf("[successful]\t");
        }
        else printf("[failed    ]\t"); 

        for(int j = 0; j < n; j++) {
            printf("%d\t", loc[j]); 
        }
        printf("\n");
    }
    printf("worst_fit_end\n");
    return;
}

int main() {
    int n, m;
    int *loc, *seq;

    printf("Enter number of memory locations: ");
    scanf("%d", &n);

    loc = (int*)malloc(n*sizeof(int));
    printf("Enter the size of each memory locations: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &loc[i]);
    }

    printf("Enter the number of memory allocations: ");
    scanf("%d", &m);

    seq = (int*)malloc(m*sizeof(int));
    printf("Enter the memory allocation sequence: ");
    for(int i = 0; i < m; i++) {
        scanf("%d", &seq[i]);
    }
    
    run_first_fit(get_clone(loc, n), n, seq, m);
    run_best_fit(get_clone(loc, n), n, seq, m);
    run_worst_fit(get_clone(loc, n), n, seq, m);
    
    return 0;
}
