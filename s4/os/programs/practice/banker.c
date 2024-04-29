#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>

int main() {
    int n; 
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int aloc[10][3], mx[10][3], need[10][3], avlbl[3];
    
    for(int i = 0; i < n; i++) {
        printf("Enter aloc for P%d: ", i);
        for(int j = 0; j < 3; j++) {
            scanf("%d", &aloc[i][j]);
        }

        printf("Enter mx for P%d: ", i);
        for(int j = 0; j < 3; j++) {
            scanf("%d", &mx[i][j]);
            need[i][j] = mx[i][j] - aloc[i][j];
        }
    }

    printf("Enter avlbl: ");
    for(int i = 0; i < 3; i++) {
        scanf("%d", &avlbl[i]);
    }

    int cnt = 100;

    int end = 0;

    printf("\n");
    while(cnt--) {
        for(int i = 0; i < n; i++) {
            if(need[i][0] <= avlbl[0] && need[i][1] <= avlbl[1] && need[i][2] <= avlbl[2]) {
                avlbl[0] += aloc[i][0];
                avlbl[1] += aloc[i][1];
                avlbl[2] += aloc[i][2];
                need[i][0] = need[i][1] = need[i][2] = INT_MAX;
                printf("P%d\t", i);
                end++;
            }
        }
    }

    printf("\n");
    if(end == n) {
        printf("Successful\n");
    }
    else {
        printf("fail\n");
    }

    return 0;
}

