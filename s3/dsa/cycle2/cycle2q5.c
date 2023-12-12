#include <stdio.h>

struct Node {
    struct Node* left;
    int data;
    struct Node* right;
};

struct Tree {
    struct Node* root;
};

typedef struct Node Node;
typedef struct Tree Tree;

void setRoot(Tree* tr, int x) {
    tr->root->left = NULL;
    tr->root->data = x;
    tr->root->right = NULL;
}

Node* searchBST(Node* node, int k) {

}

void insBT(Node* node, int k, int x) {
    if(node == NULL) {
        return;
    }
    if(node->data == k && (node->left != NULL || node->right != NULL)) {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->data = x;
        newnode->left = NULL;
        newnode->right = NULL;
        if(node->left == NULL) {
            node->left = newnode;
        }
        else {
            node->right = newnode;
        }
        return;
    }
    else{
        insBT(node->left, k, x);
        insBT(node->right, k, x);
    }
}

void inorder(Tree* tr, int x) {

}




int main() {
}