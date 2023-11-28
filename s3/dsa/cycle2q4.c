#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct Node{
    int d;
    struct Node* next;
};

typedef struct Node Node;

struct LL{
    int sz;
    Node* head;
};

typedef struct LL LL;

void init(LL* ll){
    ll->sz = 0;
    ll->head = NULL; 
}

void display(LL *ll){
    Node* tempnode = ll->head;
    for(int i = 0; i < ll->sz; i++){
        printf("%d  ", tempnode->d);
        tempnode = tempnode->next;
    }
    printf("\n"); 

    return;
}

void insertEnd(LL *ll, int x){
    if(ll->sz == 0){
        ll->head = (Node*)malloc(sizeof(Node));
        ll->head->d = x;
        ll->head->next = NULL; 
    }
    else{
        Node* tempnode = ll->head;
        for(int i = 0; i < ll->sz - 1; i++){
            tempnode = tempnode->next;
        }
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->d = x;
        newnode->next = NULL;
        tempnode->next = newnode;
    }

    ll->sz++;

    return;
}

void deleteBegin(LL *ll){
    if(ll->sz == 0){
        printf("empty cannot delete\n");
    }
    else{
        Node* delnode = ll->head;
        ll->head = ll->head->next;
        free(delnode);

        ll->sz--;
    }

    return;
}

int main(){
    LL *ll = (LL*)malloc(sizeof(LL));
    init(ll);
    int x, k, ch;
    printf("1.enqueue(ll, x)\n2.dequeue(ll)\n3.display(ll)\n4.exit()\n");
    while(true){
        printf("ch: "); scanf("%d", &ch);
        switch(ch){
            case 1: scanf("%d", &x); insertEnd(ll, x); break; 
            case 2: deleteBegin(ll); break;
            case 3: display(ll); break;
            case 4: exit(0);
        }
    }
}


