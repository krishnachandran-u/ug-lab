#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int vertices, edges;
bool* visited;
int** adj;

void createGraph();
void addEdge(int a, int b);
void dfs(int vertex);

int main() {
    printf("enter the number of vertices: ");
    scanf("%d", &vertices);

    createGraph();

    printf("enter the number of edges\n"); 
    scanf("%d", &edges);

    printf("enter the pairs\n");
    for(int i = 0; i < edges; i++) {
        int a, b; scanf("%d%d", &a, &b);
        addEdge(a, b); 
        addEdge(b, a);
    }

    dfs(0);
    return 0;
}

void createGraph() {
    adj = (int**)malloc(vertices*sizeof(int*));
    for(int i = 0; i < vertices; i++) {
        adj[i] = (int*)malloc(vertices*sizeof(int));
    }
    for(int i = 0; i < vertices; i++) {
        for(int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }

    visited = (bool*)malloc(vertices*sizeof(bool));
    for(int i = 0; i < vertices; i++) visited[i] = false;

    return;
}

void addEdge(int a, int b) {
    if(a < vertices && b < vertices) {
        adj[a][b] = 1;
    }

    return;
}

void dfs(int vertex) {
    visited[vertex] = true;  
    printf("%d  ", vertex);
    
    for(int i = 0; i < vertices; i++) {
        if(adj[vertex][i] == 1 && visited[i] == false) {
            dfs(i); 
        }
    }
    return;
}

