#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

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

void init(Tree* tr, int x) {
    tr->root = (Node*)malloc(sizeof(Node));
    tr->root->left = NULL;
    tr->root->data = x;
    tr->root->right = NULL;
}

void insertNode(Node* node, int k, int x) { //uses inorderTraversal
    if(node == NULL) {
        return;
    }
    insertNode(node->left, k, x);

    if(node->data == k) {
        if(node->left == NULL || node->right == NULL){
            Node* newnode = (Node*)malloc(sizeof(Node));
            newnode->left = NULL;
            newnode->data = x;
            newnode->right = NULL;
            if(node->left == NULL) {
                node->left = newnode;
            }
            else if(node->right == NULL) {
                node->right = newnode;
            }
        }
        return;
    }

    insertNode(node->right, k, x);
}

void deleteNode(Node* node, Node* parent, int x) {
    if(node == NULL) {
        return;
    }
    deleteNode(node->left, node, x);
    if(node->data == x && node->left == NULL && node->right == NULL) {
        if(node == parent->left) {
            parent->left = NULL;
        }
        else if(node == parent->right) {
            parent->right = NULL;
        }
        free(node);
    }
    deleteNode(node->right, node, x);
}

void inorder(Node* node) {
    if(node == NULL) {
        return;
    }
    inorder(node->left);
    printf("%d\t", node->data);
    inorder(node->right);
}

void preorder(Node* node) {
    if(node == NULL) {
        return;
    }
    printf("%d\t", node->data);
    preorder(node->left);
    preorder(node->right);
}

void postorder(Node* node) {
    if(node == NULL) {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    printf("%d\t", node->data);
}

int main() {
    Tree* tr = (Tree*)malloc(sizeof(Tree));
    printf("1.setRoot(x)\n2.insertNode(k, x)\n3.deleteNode(x)\n4.inorder()\n5.preorder()\n6.postorder()\n7.return\n");
    int k, x;
    while(true) {
        int ch;
        scanf("%d", &ch);
        switch(ch) {
            case 1: scanf("%d", &x); init(tr, x); break; 
            case 2: scanf("%d%d", &k, &x); insertNode(tr->root, k, x); break;
            case 3: scanf("%d", &x); deleteNode(tr->root, NULL,x); break;
            case 4: inorder(tr->root); printf("\n"); break;
            case 5: preorder(tr->root); printf("\n"); break;
            case 6: postorder(tr->root); printf("\n"); break;
            case 7: return 0; break;
        }
    }
}