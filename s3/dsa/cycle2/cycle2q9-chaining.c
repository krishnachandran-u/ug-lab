#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int key;
    int value;
    struct Node* next;
};

struct Node* hashTable[SIZE];

struct Node* createNode(int key, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insert(int key, int value) {
    int index = key % SIZE;

    if (hashTable[index] == NULL) {
        hashTable[index] = createNode(key, value);
    } else {
        struct Node* currentNode = hashTable[index];
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = createNode(key, value);
    }
}

int search(int key) {
    int index = key % SIZE;

    if (hashTable[index] == NULL) {
        return -1;
    } else {
        struct Node* currentNode = hashTable[index];
        while (currentNode != NULL) {
            if (currentNode->key == key) {
                return currentNode->value;
            }
            currentNode = currentNode->next;
        }
        return -1;
    }
}

void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* currentNode = hashTable[i];
        while (currentNode != NULL) {
            printf("(%d, %d) ", currentNode->key, currentNode->value);
            currentNode = currentNode->next;
        }
        printf("\n");
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

    insert(1, 10);
    insert(11, 20);
    insert(21, 30);
    insert(2, 40);
    insert(12, 50);

    display();

    int key = 11;
    int value = search(key);
    if (value != -1) {
        printf("Value for key %d: %d\n", key, value);
    } else {
        printf("Key %d not found\n", key);
    }

    return 0;
}
