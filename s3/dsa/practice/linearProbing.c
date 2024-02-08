#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define SIZE 100

int hashTable[SIZE];

void initializeHashTable();
void insert(int x);
void search(int x);
int hashFunction(int x);

int main() {
    initializeHashTable();

    insert(2);
    insert(2393);
    insert(2345);
    insert(359202);
    insert(345);
    insert(45);
    insert(997);
    insert(97);

    search(2);
    search(2393);
    search(2345);
    search(359202);
    search(345);
    search(45);
    search(997);
    search(97);
    search(56);
    search(2239);

    return 0;
}

void initializeHashTable() {
    for(int i = 0; i < SIZE; i++) {
        hashTable[i] = INT_MIN;
    }
}

void insert(int x) {
    int index = hashFunction(x);

    if(hashTable[index] == INT_MIN) {
        hashTable[index] = x;
    }
    else {
        int i = (index + 1) % SIZE;
        while(i != index) {
            if(hashTable[i] == INT_MIN) {
                hashTable[i] = x;
                return;
            }
            i = (i + 1) % SIZE;
        }
        printf("hashTable is full :(\n");
    }

    return;
}

void search(int x) {
    int index = hashFunction(x);

    if(hashTable[index] == INT_MIN) {
        printf("%d not found\n", x);
    }
    else if(hashTable[index] == x) {
        printf("%d found at index %d\n", x, index);
    }
    else {
        int i = (index + 1) % SIZE;
        while(i != index && hashTable[i] != INT_MIN) {
            if(hashTable[i] == x) {
                printf("%d found at index %d\n", x, i);
                return;
            }
            i = (i + 1) % SIZE;
        }
        printf("%d not found\n", x);
    }
    return;
}

int hashFunction(int x) {
    return x % SIZE;
}
