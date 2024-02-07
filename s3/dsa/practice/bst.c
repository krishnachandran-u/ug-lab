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

Node* ROOT = NULL; //root of tree (global)

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
    Node* node = (Node*)malloc(sizeof(Node)); //allocate memory
    node->left = NULL; //initialize left
    node->right = NULL; //initialize right
    return node; //return node
}

void insert(Node* node, Node* parent, int x) {
    if(node == NULL) { //not found
        Node* newnode = getNode();
        newnode->x = x;
        if(parent != NULL) {
            if(x < parent->x) parent->left = newnode;
            else parent->right = newnode;
        }
        else ROOT = newnode;
    }
    else if(x == node->x) { //found
        printf("%d already exists\n", x);
    }
    else if(x < node->x) { //search left
        insert(node->left , node, x);
    }
    else { //search right
        insert(node->right, node, x);
    }
    return;
}

void delete(Node* node, Node* parent, int x) {
    if(node == NULL) { //not found
        printf("value not found\n");
        return;
    }
    else if(x == node->x) { //found
        if(node->left == NULL && node->right == NULL) { //no child
            if(parent != NULL) { //node is not root
                if(x < parent->x) parent->left = NULL;
                else parent->right = NULL;
            }
            else { //node is root
                free(ROOT); //free root
                ROOT = NULL; //set root to NULL
            }
        }
        else if(node->right == NULL) { //only left subtree
            if(parent != NULL) { //node is not root
                if(x < parent->x) parent->left = node->left; //connect left of parent to left of node
                else parent->right = node->left; //connect right of parent to left of node
                free(node);
            }
            else { //node is root
                Node* delNode = ROOT;
                ROOT = ROOT->left; //connect root to left of node
                free(delNode); //free root
            }
            return;
        }
        else if(node->left == NULL) { //only right subtree
            if(parent != NULL) { //node is not root
                if(x < parent->x) parent->left = node->right; //connect left of parent to right of node
                else parent->right = node->right; //connect right of parent to right of node
                free(node);
            }
            else { //node is root
                Node* delNode = ROOT;
                ROOT = ROOT->right; //connect root to right of node
                free(delNode); //free root
            }
        }
        else deleteUsingInorderSuccessor(node, parent, x); //has both subtrees
    }
    else if(x < node->x) delete(node->left, node, x); //search left
    else delete(node->right, node, x); //search right
    return;
}

void deleteUsingInorderSuccessor(Node* node, Node* parent, int x) {
    Node* rover = node; //inorder successor
    Node* roverParent = parent; //parent of inorder successor

    rover = rover->right;
    while(rover->left != NULL) { //find inorder successor
        roverParent = rover;
        rover = rover->left;
    }

    rover->left = node->left; //connect left subtree of node to left of inorder successor
                              //
    if(parent != NULL) {//node is not root 
        if(x < parent->x) parent->left = node->right; //connect left of parent to right of node
        else parent->right = node->right; //connect right of parent to right of node
        free(node);
    }
    else { //node is root
        Node* delNode = ROOT;
        ROOT = ROOT->right; //connect root to right of node
        free(delNode); //free root
    }

    return;
}

void inorder(Node* node) {
    if(node == NULL) return;

    inorder(node->left); //search left
    visit(node); //visit
    inorder(node->right); //search right
    return;
}

void visit(Node* node) { //print node
    printf("%d  ", node->x);
    return;
}
