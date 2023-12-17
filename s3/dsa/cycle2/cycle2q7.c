#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define max(a, b) (a > b)? a: b;
#define min(a, b) (a < b)? a: b;

struct Q{
    int *a; // array
    int cp; // size && capacity
    int f, r; //front and rear
};

void initQ(struct Q* q){
    q->a = NULL;
    q->f = 0; q->r = -1;
    q->cp = 0;
}

bool isEmpty(struct Q* q){
    return (q->r - q->f + 1 == 0);
} 

void pushQ(struct Q* q, int x){
    q->r++;
    if(q->r - q->f + 1 > q->cp){
        q->cp = max(1, q->cp << 1); 
        int *p = (int*)malloc(sizeof(int)*q->cp);
        int cnt = 0;
        for(int i = q->f; i < q->r; i++){
            p[cnt++] = q->a[i];
        }
        free(q->a);
        q->a = p;
        q->f = 0; q->r = cnt;
    }
    q->a[q->r] = x; 
    return;
}

void popQ(struct Q* q){
    if(q->r - q->f + 1 == 0){
        return;
    }
    q->f++;
    if(q->r - q->f + 1 <= (q->cp >> 1)){
        q->cp >>= 1;
        int *p = (int*) malloc(sizeof(int)*q->cp);
        int cnt = 0;
        for(int i = q->f; i <= q->r; i++){
            p[cnt++] = q->a[i];
        }
        free(q->a);
        q->a = p;
        q->f = 0; q->r = cnt - 1;  
    }
    return;
}

int adjMatrix[10][10];
int adjList[10];

void dfs(int v, int visited[], int vert) {
    visited[v] = 1;
    printf("%d ", v);
    for(int i = 0; i < vert; i++) {
        if(adjMatrix[v][i] == 1 && visited[i] == 0) {
            dfs(i, visited, vert);
        }
    }
}

int main() {
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            adjMatrix[i][j] = 0;
        }
    }

    int vert, edg;
    printf("enter number of vertices: ");
    scanf("%d", &vert);
    printf("enter number of edges: ");
    scanf("%d", &edg);

    printf("enter each edge (src dest):\n");
    for(int i = 0; i < edg; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;
    }

    for(int i = 0; i < vert; i++) {
        for(int j = 0; j < vert; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    for(int i = 0; i < vert; i++) {
        printf("%d -> ", i);
        for(int j = 0; j < vert; j++) {
            if(adjMatrix[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    int visited[vert];
    for(int i = 0; i < vert; i++) {
        visited[i] = 0;
    }
    printf("dfs:\n");
    printf("staring from 0\n");
    dfs(0, visited, vert);

    for(int i = 0; i < vert; i++) {
        visited[i] = 0;
    }

    struct Q q;
    initQ(&q);

    printf("\nbfs:\n");
    //bfs
    //starting from 0
    pushQ(&q, 0);
    visited[0] = 1;
    while(!isEmpty(&q)) {
        int v = q.a[q.f];
        popQ(&q);
        printf("%d ", v);
        for(int i = 0; i < vert; i++) {
            if(adjMatrix[v][i] == 1 && visited[i] == 0) {
                pushQ(&q, i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}
