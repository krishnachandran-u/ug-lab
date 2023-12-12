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

void insertBegin(LL *ll, int x){
    if(ll->sz == 0){
        ll->head = (Node*)malloc(sizeof(Node));
        ll->head->d = x;
        ll->head->next = NULL; 
    }
    else{
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->d = x;
        newnode->next = ll->head;
        ll->head = newnode;
    }

    ll->sz++;

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

void insertAtPos(LL *ll, int x, int k){
    if(ll->sz == 0){
        printf("key not found\n");
        return;
    }
    else{
        Node* tempnode = ll->head; 
        for(int i = 0; i < ll->sz; i++){
            if(tempnode->d == k){
                break;
            }
            tempnode = tempnode->next;
        }
        if(tempnode == NULL){
            printf("key not found\n");
        }
        else{
            Node* newnode = (Node*)malloc(sizeof(Node));
            newnode->d = x;
            newnode->next = tempnode->next;
            tempnode->next = newnode;

            ll->sz++;
        }
    }
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

void deleteEnd(LL *ll){
    if(ll->sz == 0){
        printf("empty cannot delete\n");
    }
    else if(ll->sz == 1){
        Node* delnode = ll->head;
        ll->head = ll->head->next;
        free(delnode);
        ll->sz--;
    }
    else{
        Node* tempnode = ll->head;
        for(int i = 0; i < ll->sz; i++){
            tempnode = tempnode->next;
        }       
        Node* delnode = tempnode->next;
        free(delnode);
        tempnode->next = NULL;

        ll->sz--;
    }

    return;
}

void deleteAtPos(LL *ll, int k){
    if(ll->sz == 0){
        printf("empty cannot delete\n");
    }
    else if(ll->sz == 1){
        if(ll->head->d == k){
            Node* delnode = ll->head;
            ll->head = ll->head->next;
            free(delnode);
            ll->sz--;
        }
        else{
            printf("key not found\n");
        }
    }
    else{
        Node* prevnode = NULL;
        Node* tempnode = ll->head;
        for(int i = 0; i < ll->sz; i++){
            if(tempnode->d == k){
                break;
            }
            prevnode = tempnode;
            tempnode = tempnode->next;
        }
        if(tempnode == NULL){
            printf("key not found\n");
        }
        else{
            prevnode->next = prevnode->next->next;
            free(tempnode);
            ll->sz--;
        }
        return;
    }
}

int main(){
    LL *ll = (LL*)malloc(sizeof(LL));
    init(ll);
    int x, k, ch;
    printf("1.insertBegin(ll, x)\n2.insertEnd(ll, x)\n3.insertAtPos(ll, x, k)\n4.deleteBegin(ll)\n5.deleteEnd(ll)\n6.deleteAtPos(ll, k)\n7.display(ll)\n8.exit()\n");
    while(true){
        printf("ch: "); scanf("%d", &ch);
        switch(ch){
            case 1: scanf("%d", &x); insertBegin(ll, x); break;
            case 2: scanf("%d", &x); insertEnd(ll, x); break; 
            case 3: scanf("%d%d", &x, &k); insertAtPos(ll, x, k); break;
            case 4: deleteBegin(ll); break;
            case 5: deleteEnd(ll); break;
            case 6: scanf("%d", &k); deleteAtPos(ll, k); break;
            case 7: display(ll); break;
            case 8: exit(0);
        }
    }
}

