#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM 5
#define TBL_RWS 5

struct {
    int now, next;
} store[DIM][DIM];

void init_store() {
    printf("Store\n");
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            store[i][j].now = DIM*i + j;
            store[i][j].next = (DIM*i + j + 5) % (DIM*DIM);
            printf("%d:%d\t" , store[i][j].now, store[i][j].next);
        }
        printf("\n");
    }
}

void seq() {
    // generate directory
    int dir[TBL_RWS][2];
    printf("sequential : directory\n");
    printf("start | length\n");
    for (int i = 0; i < TBL_RWS; i++) {
        dir[i][0] = rand() % (DIM*DIM);
        dir[i][1] = rand() % ((DIM*DIM) - dir[i][0]);
        printf("%d\t%d\n", dir[i][0], dir[i][1]);
    }
    printf("\n");

    printf("Allocation: \n");
    for (int i = 0; i < TBL_RWS; i++) {
        for(int j = dir[i][0]; j < (dir[i][0] + dir[i][1]); j++) {
            printf("%d\t", j);
        }
        printf("\n");
    }
    printf("\n");
    return;
}

void linked() {
    int st, nd;
    printf("From the store enter a valid start and end addresses: ");
    scanf("%d%d", &st, &nd);

    printf("Allocation\n");
    for (int i = st / DIM, j = st % DIM;;) {
        printf("%d\t", DIM*i + j); 
        if(DIM*i + j == nd) break;
        i = store[i][j].next / DIM;
        j = store[i][j].next % DIM;
    }
    printf("\n");
    return;
}

void indexed() {
    printf("Index table has %d rows. Enter the %d indexes (0 - 24): \n", TBL_RWS, TBL_RWS);
    for (int i = 0; i < TBL_RWS; i++) {
        int x;
        scanf("%d", &x);
        printf("Accessed: %d:%d\n", store[x / DIM][x % DIM].now, store[x / DIM][x % DIM].next);
    }
    printf("\n");
    return;
}

int main() {
    srand(time(NULL));
    init_store();
    seq();
    linked();
    indexed();
    return 0;
}
