#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 1000

struct Stack {
    int d[SIZE];
    int size;
};

typedef struct Stack Stack;

Stack* getStack();
void push(Stack* s, int x);
void pop(Stack* s);
int top(Stack* s);
bool isFull(Stack* s);
bool isEmpty(Stack* s);
void display(Stack* s);
void createGraph();
void addEdge(int a, int b);
void dfs();

int vertices, edges;
bool* visited;
int** adj;

Stack* stack;

int main() {
    stack = getStack();

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
 
    push(stack, 0);
    dfs();
    return 0; 
}

Stack* getStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->size = 0;
    return s;
}

void push(Stack* s, int x) {
    if(isFull(s)) {
        printf("Stack Overflow\n");
    }
    else {
        s->d[s->size++] = x;
    }
    return;
}

void pop(Stack* s) {
    if(isEmpty(s)) {
        printf("Stack Underflow\n");
    }
    else {
        s->size--;
    }
    return;
}

int top(Stack* s) {
    if(isEmpty(s)) {
        printf("Stack Underflow\n");
        return INT_MIN;
    }
    else {
        return s->d[s->size - 1];
    }
}

bool isEmpty(Stack* s) {
    return s->size == 0;
}

bool isFull(Stack* s) {
    return s->size == SIZE;
}

void display(Stack* s) {
    for(int i = 0; i < s->size; i++) {
        printf("%d  ", s->d[i]);
    }
    printf("\n");
    return;
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

void dfs() {
    while(!isEmpty(stack)) {
        int vertex = top(stack);
        pop(stack);
        printf("%d   ", vertex);
        visited[vertex] = true;

        for(int i = 0; i < vertices; i++) {
            if(adj[vertex][i] == 1 && visited[i] == false) {
                push(stack, i);
            }
        }
    }
    
    return;
}
