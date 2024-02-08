#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node {
    struct Node* next;
    int x;
};

typedef struct Node Node;

Node **List;
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
        addEdge(b, a);
    }

    dfs(0);
    return 0;
}

void createGraph() {
    List = (Node**)malloc(vertices*sizeof(Node*));
    for(int i = 0; i < vertices; i++) {
        List[i] = (Node*)malloc(sizeof(Node));
        List[i]->x = -1;
        List[i]->next = NULL;
    }

    visited = (bool*)malloc(vertices*sizeof(bool));
    for(int i = 0; i < vertices; i++) visited[i] = false;
}

void addEdge(int a, int b) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->next = NULL;
    newnode->x = b;
    Node* rover = List[a];

    while(rover->next != NULL)
        rover = rover->next;
    rover->next = newnode; 

    return;
}

void dfs(int vertex) {
    printf("%d  ", vertex);
    visited[vertex] = true;

    Node* rover = List[vertex];
    rover = rover->next;
    while(rover != NULL) {
       if(visited[rover->x] == false)
           dfs(rover->x); 
       rover = rover->next;
    }
    return;
}
