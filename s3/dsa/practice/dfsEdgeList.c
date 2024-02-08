#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Node Node;
typedef struct Edge Edge;

struct Edge {
    struct Edge* nextEdge;
    struct Node* sinkVertex;
};

struct Node {
    struct Edge* edgeList;
    int x;
};

Node** List;
bool* visited;
int vertices, edges;

void createGraph();
void addEdge(int a, int b);
void dfs(int vertex);

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    createGraph();

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for(int i = 0; i < edges; i++) {
        int a, b; 
        scanf("%d%d", &a, &b);
        addEdge(a, b);
        addEdge(a, b);
    }

    dfs(0);
    return 0;
}

void createGraph() {
    List = (Node**)malloc(vertices*sizeof(Node*));
    for(int i = 0; i < vertices; i++) {
        List[i] = (Node*)malloc(sizeof(Node));
        List[i]->edgeList = NULL;
        List[i]->x = i;
    }

    visited = (bool*)malloc(vertices*sizeof(bool));
    for(int i = 0; i < vertices; i++) 
        visited[i] = false;
    return;
}

void addEdge(int a, int b) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge)); 
    newEdge->nextEdge = NULL;
    newEdge->sinkVertex = List[b];

    Node* source = List[a];
    Edge* edge = source->edgeList;

    if(edge == NULL) {
        source->edgeList = newEdge;
    }
    else {
        while(edge->nextEdge != NULL) {
            edge = edge->nextEdge;
        }
        edge->nextEdge = newEdge;
    }
    return;
}

void dfs(int vertex) {
    printf("%d  ", vertex);
    visited[vertex] = true;

    Node* source = List[vertex];
    Edge* edge = source->edgeList;

    while(edge != NULL) {
        if(visited[edge->sinkVertex->x] == false) {
            dfs(edge->sinkVertex->x);
        }
        edge = edge->nextEdge;
    }
    return;
}


