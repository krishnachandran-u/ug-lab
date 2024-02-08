#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 100

struct Queue {
    int d[SIZE];
    int size;
    int f, r;
};

typedef struct Queue Queue;

Queue* getQueue();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void push(Queue* q, int x);
void pop(Queue* q);
int front(Queue* q);
int rear(Queue* q);
void display(Queue* q);
void createGraph();
void addEdge(int a, int b);
void bfs();

int vertices, edges;
bool* visited;
int** adj;
Queue* q;

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    createGraph();

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edge pairs:\n");
    for(int i = 0; i < edges; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        addEdge(a, b);
        addEdge(b, a);
    }

    q = getQueue();
    push(q, 0);

    bfs();

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

Queue* getQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->size = 0;
    q->r = 0;
    q->f = 0;
    return q;
}

bool isFull(Queue* q) {
    return q->size == SIZE;
}

bool isEmpty(Queue* q) {
    return q->size == 0;
}

void push(Queue* q, int x) {
    if(isFull(q)) {
        printf("Stack Overflow. Cannot push");
    }
    else {
        q->d[q->r++] = x;
        q->size++;
    }
    return;
}

void pop(Queue* q) {
    if(isEmpty(q)) {
        printf("Stack Underflow. Cannot pop");
    }
    else {
        q->f++;
        q->size--;
    }
}

int front(Queue* q) {
    if(isEmpty(q)) {
        printf("Stack Underflow. Cannot pop");
        return INT_MIN;
    }
    else {
        return q->d[q->f];
    }
}

int rear(Queue* q) {
    if(isEmpty(q)) {
        printf("Stack Underflow. Cannot pop");
        return INT_MIN;
    }
    else {
        return q->d[q->r - 1];
    }
}

void display(Queue* q) {
    for(int i = q->f; i < q->r; i++) {
        printf("%d  ", q->d[i]);
    }
    printf("\n");
}

void bfs() {
    while(!isEmpty(q)) {
        int vertex = front(q); 
        pop(q);
        printf("%d  ", vertex);
        visited[vertex] = true;

        for(int i = 0; i < vertices; i++) {
            if(adj[vertex][i] == 1 && visited[i] == false) {
                push(q, i);
            }
        }
    }
}
