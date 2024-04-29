#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int aloc[10][3], req[10][3], avlbl[3], fin[10] = { 0 }; 

    for(int i = 0; i < n ; i++) {
        printf("Enter the allocation of P%d: ", i);
        for(int j = 0; j < 3; j++) {
           scanf("%d", &aloc[i][j]);
        }
        printf("Enter the req of P%d: ", i);
        for(int j = 0; j < 3; j++) {
           scanf("%d", &req[i][j]);
        }
    }

    int cnt = 100;

    printf("Enter available: ");
    for(int i = 0; i < 3; i++) {
        scanf("%d", &avlbl[i]);
    }

    while(cnt--) {
        for(int i = 0; i < n; i++) {
            if(req[i][0] <= avlbl[0] && req[i][1] <= avlbl[1] && req[i][2] <= avlbl[2]) {
                avlbl[0] += aloc[i][0];
                avlbl[1] += aloc[i][1];
                avlbl[2] += aloc[i][2];

                req[i][0] = req[i][1] = req[i][2] = INT_MAX;
                fin[i] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(fin[i] == 0) {
            printf("deadlock\n");
            return 0;
        }
    }

    printf("no deadlock\n");
    return 0;
}
