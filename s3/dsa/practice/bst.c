//check if node is leaf
        //else check if node only has left subtree and if yes reconnect the parent to left child of node
        //else check if node only has right subtree and if yes reconnect the parent to right child of node
        //find inorder successor
        //if inorder successor is a leaf then swap and delete it
        //if inorder successor is not a leaf (ie the right child of node doesnt have a left child) reconnect the connect the left subtree of node as left subtree of its right child and reconnect it to its parent
        

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Node {
    struct Node* left;
    int x;
    struct Node* right;
};

typedef struct Node Node;

Node* getNode();
void insert(Node* node, Node* parent, int x);
void delete(Node* node, Node* parent, int x);
void deleteUsingInorderSuccessor(Node* node, Node* parent, int x);
void visit(Node* node);
void inorder(Node* node);

Node* ROOT = NULL;

int main() {
    insert(ROOT, NULL, 1);
    insert(ROOT, NULL, 2);
    insert(ROOT, NULL, 0);
    insert(ROOT, NULL, 3);
    insert(ROOT, NULL, 0);
    insert(ROOT, NULL, 9);
    insert(ROOT, NULL, 5);
    insert(ROOT, NULL, 7);
    insert(ROOT, NULL, 1);
    insert(ROOT, NULL, 14);

    inorder(ROOT); printf("\n");

    delete(ROOT, NULL, 9);
    delete(ROOT, NULL, 5);
    delete(ROOT, NULL, 1);

    inorder(ROOT); printf("\n");

    insert(ROOT, NULL, 9);
    insert(ROOT, NULL, 35);
    insert(ROOT, NULL, 1);

    inorder(ROOT); printf("\n");
    
    return 0;
}

Node* getNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(Node* node, Node* parent, int x) {
    if(node == NULL) {
        Node* newnode = getNode();
        newnode->x = x;
        if(parent != NULL) {
            if(x < parent->x) parent->left = newnode;
            else parent->right = newnode;
        }
        else ROOT = newnode;
    }
    else if(x == node->x) {
        printf("value exists\n");
    }
    else if(x < node->x) {
        insert(node->left , node, x);
    }
    else {
        insert(node->right, node, x);
    }
    return;
}

void delete(Node* node, Node* parent, int x) {
    if(node == NULL) {
        printf("value not found\n");
        return;
    }
    else if(x == node->x) {
        if(node->left == NULL && node->right == NULL) {
            if(parent != NULL) {
                if(x < parent->x) parent->left = NULL;
                else parent->right = NULL;
            }
            else {
                free(ROOT);
                ROOT = NULL;
            }
        }
        else if(node->right == NULL) {
            if(parent != NULL) {
                if(x < parent->x) parent->left = node->left;
                else parent->right = node->left;
                free(node);
            }
            else {
                Node* delNode = ROOT;
                ROOT = ROOT->left;
                free(delNode);
            }
            return;
        }
        else if(node->left == NULL) {
            if(parent != NULL) {
                if(x < parent->x) parent->left = node->right;
                else parent->right = node->right;
                free(node);
            }
            else {
                Node* delNode = ROOT;
                ROOT = ROOT->right;
                free(delNode);
            }
        }
        else deleteUsingInorderSuccessor(node, parent, x);
    }
    else if(x < node->x) delete(node->left, node, x);
    else delete(node->right, node, x);
    return;
}

void deleteUsingInorderSuccessor(Node* node, Node* parent, int x) {
    Node* rover = node;
    Node* roverParent = parent;

    rover = rover->right;
    while(rover->left != NULL) {
        roverParent = rover;
        rover = rover->left;
    }
    rover->left = node->left;
    if(parent != NULL) { 
        if(x < parent->x) parent->left = node->right;
        else parent->right = node->right;
        free(node);
    }
    else {
        Node* delNode = ROOT;
        ROOT = ROOT->right;
        free(delNode);
    }
    return;
}

void inorder(Node* node) {
    if(node == NULL) return;

    inorder(node->left);
    visit(node);
    inorder(node->right);
    return;
}

void visit(Node* node) {
    printf("%d  ", node->x);
    return;
}
