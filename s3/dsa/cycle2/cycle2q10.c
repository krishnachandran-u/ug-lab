#include <stdio.h>
#include <stdlib.h>

//best fit

typedef struct Node {
    int size;
    int isAllocated;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

void initialize(int size) {
    head = (Node*)malloc(sizeof(Node));
    head->size = size;
    head->isAllocated = 0;
    head->prev = NULL;
    head->next = NULL;
}

void* allocate(int size) {
    Node* current = head;
    while (current != NULL) {
        if (!current->isAllocated && current->size >= size) {
            if (current->size > size) {
                Node* newNode = (Node*)malloc(sizeof(Node));
                newNode->size = current->size - size;
                newNode->isAllocated = 0;
                newNode->prev = current;
                newNode->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = newNode;
                }
                current->size = size;
                current->isAllocated = 1;
                current->next = newNode;
            } else {
                current->isAllocated = 1;
            }
            return (void*)(current + 1);
        }
        current = current->next;
    }
    return NULL;
}

void deallocate(void* ptr) {
    if (ptr == NULL) {
        return;
    }
    Node* current = (Node*)ptr - 1;
    current->isAllocated = 0;
    if (current->next != NULL && !current->next->isAllocated) {
        current->size += current->next->size;
        current->next = current->next->next;
        if (current->next != NULL) {
            current->next->prev = current;
        }
    }
    if (current->prev != NULL && !current->prev->isAllocated) {
        current->prev->size += current->size;
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        current = current->prev;
    }
    if (current->next == NULL) {
        free(current);
    }
}

void printMemory() {
    Node* current = head;
    while (current != NULL) {
        printf("Size: %d, Allocated: %s\n", current->size, current->isAllocated ? "Yes" : "No");
        current = current->next;
    }
}

int main() {
    initialize(1024);
    
    void* ptr1 = allocate(256);
    void* ptr2 = allocate(512);
    void* ptr3 = allocate(128);
    
    printf("After allocation:\n");
    printMemory();
    
    deallocate(ptr2);
    
    printf("After deallocation:\n");
    printMemory();
    
    return 0;
}
