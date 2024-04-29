#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>

#define N 10

int store[10][10];

void reset_store() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            store[i][j] = -1;
        }
    }
    return;
}

void print_store() {
    printf("\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", store[i][j]);
        }
        printf("\n");
    }
}

void seq(int x) {
    int st = -1;
    for(int i = N - 1; x > 0; i--) {
        st = i;
        store[3][i] = x % 10;
        x /= 10;
    }
    print_store();
    
    printf("allocation: start -> %d, length -> %d", st, (N - 1 - st) + 1);
    return;
}

struct node {
    int x;
    int nx;
    int ny;
};

typedef struct node node;

node nodes[N][N];

void reset_nodes() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            nodes[i][j].x = -1;
            nodes[i][j].nx = 0;
            nodes[i][j].ny = 0;
        }
    }
}

void print_nodes() {
    printf("\n");
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d:[%d][%d]\t", nodes[i][j].x, nodes[i][j].nx, nodes[i][j].ny);
        }
        printf("\n");
    }
}

void linked(int x) {
    reset_nodes();
    int X = 0;
    int Y = 0;
    while(x > 0) {
        nodes[X][Y].x = 0;

        if(X == 0 && Y == 0) continue;
        if(nodes[X][Y].x != -1) continue;

        int curx = X;
        int cury = Y;

        while(X != 0 && Y != 0 && nodes[X][Y].x == -1) {
            X = rand() % 10;
            Y = rand() % 10;
        }

        nodes[curx][cury].nx
        //incomplete
    }
    reset_nodes();
    return;
}

void indexed(int x) {
    
}

int main() {
    srand(time(0));
    int x;
    printf("Enter a string to store: ");
    scanf("%d", &x);

    return 0;
}

