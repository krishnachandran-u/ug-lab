#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Node {
    struct Node* next;
    int x;
};

typedef struct Node Node;

struct LL {
    Node* head;
    int size;
};

typedef struct LL LL;

Node* getNode();
LL* getLL();
bool isEmpty(LL* ll);
void push(LL* ll, int x);
void pop(LL* ll);
void display(LL* ll);

int main() {
    LL* ll = getLL();

    push(ll, 1);
    display(ll);
    push(ll, 2);
    display(ll);
    push(ll, 3);
    display(ll);
    push(ll, 4);
    display(ll);
    push(ll, 5);
    display(ll);
    pop(ll);
    display(ll);
    pop(ll);
    display(ll);
    pop(ll);
    display(ll);
    push(ll, 9);
    display(ll);
    push(ll, 8);
    display(ll);
    return 0;
}

Node* getNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    return node;
}

LL* getLL() {
    LL* ll = (LL*)malloc(sizeof(LL));
    ll->head = NULL;
    ll->size = 0;
    return ll;
}

bool isEmpty(LL* ll) {
    return ll->size == 0; 
}

void push(LL* ll, int x) {
    Node* newnode = getNode();
    newnode->x = x;
    if(isEmpty(ll)) {
        ll->head = newnode;
    }
    else {
        Node* tempnode = ll->head;
        for(int i = 0; i < ll->size - 1; i++) {
            tempnode = tempnode->next;
        }
        tempnode->next = newnode;
    }
    ll->size++;
    return;
}

void pop(LL* ll) {
    if(isEmpty(ll)) {
        printf("Queue Underflow\n");
    }
    else {
        Node* delnode = ll->head;
        ll->head = ll->head->next;
        free(delnode);
    }
    ll->size--;
    return;
}

void display(LL* ll) {  
    Node* tempnode = ll->head;
    for(int i = 0 ; i < ll->size; i++) {
        printf("%d  ", tempnode->x);
        tempnode = tempnode->next;
    }
    printf("\n");
    return;
}
