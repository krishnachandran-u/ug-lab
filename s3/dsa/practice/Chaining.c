#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 100

typedef struct Node Node;

struct Node {
    struct Node* next;
    int x; 
};

Node** hashTable;

void createHashTable();
void insert(int x);
void search(int x);
int hashFunction(int x);

int main() {
    createHashTable();

    insert(1020);
    insert(2230);
    insert(3455);
    insert(2302);
    insert(67870);
    insert(670);
    insert(67);

    search(1020);
    search(67870);
    search(670);
    search(67);
    search(100);
    search(445);

    return 0;
}

void createHashTable() {
    hashTable = (Node**)malloc(sizeof(Node*));
    for(int i = 0; i < SIZE; i++) {
        hashTable[i] = (Node*)malloc(sizeof(Node));
        hashTable[i]->next = NULL;
        hashTable[i]->x = -1; //access restricted
    }
    return;
}

void insert(int x) {
    int index = hashFunction(x);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->x = x ;

    Node* rover = hashTable[index];
    while(rover->next != NULL) {
        rover = rover->next;
    }

    rover->next = newNode;
    
    return;
}

void search(int x) {
    int index = hashFunction(x);
    Node* rover = hashTable[index];

    rover = rover->next;

    while(rover != NULL) {
        if(rover->x == x) {
            printf("%d found at index %d\n", x, index);
            return;
        }
        rover = rover->next;
    }

    printf("%d not found in the hashTable\n", x);
    return;
}

int hashFunction(int x) {
    return x % SIZE;
}
