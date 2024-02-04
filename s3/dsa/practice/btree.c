#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node {
    struct Node* lt;
    struct Node* rt;
    int x;
};

typedef struct Node Node;

struct BTree {
    struct Node* root;
};

typedef struct BTree BTree;

Node* getNode();
BTree* getBTree();
void setRoot(BTree* btree, int x);
void insert(Node* node, int k, int x);
void delete(Node* node, Node* parent, int x);
void visit(Node* node);
void inorder(Node* node);
void preorder(Node* node);
void postorder(Node* node);

int main() {
    BTree* btree = getBTree();
    setRoot(btree, 1);
    insert(btree->root, 1, 2);
    insert(btree->root, 1, 3);
    insert(btree->root, 2, 4);
    insert(btree->root, 2, 5);
    insert(btree->root, 5, 7);
    insert(btree->root, 3, 6);
    printf("inorder");
    inorder(btree->root);
    printf("\n");
    printf("preorder");
    preorder(btree->root);
    printf("\n");
    printf("postorder");
    postorder(btree->root);
    printf("\n");
    return 0;
}

Node* getNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->lt = NULL;
    node->rt = NULL;
    return node;
}

BTree* getBTree() {
    BTree* btree = (BTree*)malloc(sizeof(BTree));
    btree->root = NULL;
    return btree;
}

void setRoot(BTree* btree, int x) {
    Node* node = getNode();
    node->x = x;
    btree->root = node;
}
    
void insert(Node* node, int k, int x) {
    if(node == NULL) {
        return;
    }
    insert(node->lt, k, x);
    if(node->x == k) {
        if(node->lt == NULL) {
            Node* newnode = getNode();
            newnode->x = x;
            node->lt = newnode;
        }
        else if(node->rt == NULL) {
            Node* newnode = getNode();
            newnode->x = x;
            node->rt = newnode;
        }
        return;
    }
    insert(node->rt, k, x);
    return;
}

void delete(Node* node, Node* parent, int x) {
    if(node == NULL) {
        return;
    }
    delete(node->lt, node, x);
    if(node->x == x && node->lt == NULL && node->rt == NULL) {
        if(parent->lt == node) {
            parent->lt = NULL;
        }
        else if(parent->rt == node) {
            parent->rt = NULL;
        }
        free(node);
    }
    delete(node->rt, node, x);
    return;
}

void visit(Node *node) {
    printf("%d  ", node->x);
    return;
}

void inorder(Node* node) {
    if(node == NULL) {
        return;
    }
    inorder(node->lt);
    visit(node);
    inorder(node->rt);
    return;
}

void preorder(Node* node) {
    if(node == NULL) {
        return;
    }
    visit(node);
    preorder(node->lt);
    preorder(node->rt);
    return;
}

void postorder(Node* node) {
    if(node == NULL) {
        return;
    }
    postorder(node->lt);
    postorder(node->rt);
    visit(node);
    return;
}
