#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct Node{
    int a;
    struct Node* next;
}

struct LL{
    struct Node* head;
    int sz;
}

void init(struct LL* list){
    struct Node* head = NULL;
    list->sz = 0;
}

void ib(struct LL* list, int x){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->a = x; 
    if(list->sz != 0){
        newnode->next = list->head;
    }
    list->head = newnode;
}

void ie(struct LL* list, int x){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->a = x;
    newnode->next = NULL;
    if(list->sz != 0){
        struct Node* tempnode = list->head;
        while(tempnode->next != NULL){
            tempnode = tempnode->next; 
        }
        tempnode->next = newnode;
    }
    else{
        list->head = newnode;
    }
    return;
}

void is(struct LL*list, int k, int x){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->a = x;
    if(list->sz != 0){
        struct Node* tempnode = list->head;
        while(tempnode != NULL && tempnode->a != k){
            tempnode = tempnode -> next;
        }
        if(tempnode == k){
            tempnode->next = newnode
        }
    }
}


int main(){
     
}
