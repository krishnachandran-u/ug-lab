#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

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
void push(LL* ll, int x);
void pop(LL* ll);
void display(LL* ll);

int main() {
    LL* ll = getLL();
    push(ll, 1); 
    display(ll);
    push(ll, 2);
    display(ll);
    push(ll, 5);
    display(ll);
    push(ll, 6);
    display(ll);
    pop(ll);
    display(ll);
    pop(ll);
    display(ll);
    push(ll, 7);
    display(ll);
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

void push(LL* ll, int x) {
    Node* node = getNode();
    node->x = x;
    if(ll->head == NULL) {
        ll->head = node;
    }
    else {
        Node* tmp = ll->head;
        while(tmp->next != NULL) {
            tmp = tmp->next; 
        }
        tmp->next = node;
    }
    return;
}

void pop(LL *ll) {
    if(ll->head == NULL) {
        printf("Underflow; cannot pop\n");
    }
    else if(ll->head->next == NULL) {
        Node* tmp = ll->head;
        ll->head = NULL;
        free(tmp);
    }
    else {
        Node* tmp = ll->head;
        Node* prev = NULL;
        while(tmp->next != NULL) {
            prev = tmp;
            tmp = tmp->next;
        }
        free(tmp);
        prev->next = NULL;
    }
    return;
}

void display(LL* ll) {
    Node* tmp = ll->head;
    while(tmp != NULL) {
        printf("%d  ", tmp->x);
        tmp = tmp->next;
    }
    printf("\n");
}


