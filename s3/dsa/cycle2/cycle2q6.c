#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

struct Node {
    struct Node* left;
    int data;
    struct Node* right;
};

struct BST {
    struct Node* root;
};

typedef struct Node Node;
typedef struct BST BST;

void init(BST* bst) {
    bst->root = NULL;
}

void insertNode(Node* node, Node* parent, int x) {
    if(node == NULL) {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->left = NULL;
        newnode->data = x;
        newnode->right = NULL;
        if(parent != NULL) {
            if(x < parent->data) {
                parent->left = newnode;
            }
            else {
                parent->right = newnode;
            }
        }
        else {
            node = newnode; 
        }
        return;
    }
    else if(x < node->data) {
        insertNode(node->left, node, x);
    }
    else {
        insertNode(node->right, node, x);
    }
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

void search(Node* node, int x) {
    if(node == NULL) {
        printf("not found\n");
        return;
    }
    else if(node->data == x) {
        printf("found\n");
    }
    else if(x < node->data) {
        search(node->left, x);
    }
    else {
        search(node->right, x);
    }
}

void delete(Node* node, Node* parent, int x) {
    if(node == NULL) {
        printf("not found node\n");
        return;
    }
    
    else if(node->data == x) {
        if(parent == NULL) {
            Node* delnode = node;
            free(delnode);
            node = NULL;
        }
        else if (x < parent->data) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }
        free(node);
    }
    else if(x < node->data) {
        delete(node->left, node, x);
    }
    else {
        delete(node->right, node, x);
    }  
}

int main() {
    BST* bst = (BST*)malloc(sizeof(BST));
    init(bst);
    int ch, x; 
    printf("1.insert(x)\n2.delete(x)\n3.search(x)\n4.inorder\n5.preorder\n6.postorder\n7.return\n");
    while(true) {
        scanf("%d", &ch);
        switch(ch) {
            case 1: scanf("%d", &x); insertNode(bst->root, NULL, x); printf("%d\n", bst->root->data); break;
            case 2: scanf("%d", &x); delete(bst->root, NULL, x); break;
            case 3: scanf("%d", &x); search(bst->root, x); break;
            case 4: inorder(bst->root); printf("\n"); break;
            case 5: preorder(bst->root); printf("\n"); break;
            case 6: postorder(bst->root); printf("\n"); break;
            case 7: return 0;
        }
    }
}