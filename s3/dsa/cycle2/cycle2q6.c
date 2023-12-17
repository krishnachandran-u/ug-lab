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

void insert(BST* bst, int x) {
    if(bst->root == NULL) {
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->data = x;
        newnode->left = NULL;
        newnode->right = NULL;
        bst->root = newnode;
    }
    else {
        insertNode(bst->root, NULL, x);
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

void deleteNode(Node* node, Node* parent, int x) {
    if(node == NULL) {
        printf("not found node\n");
        return;
    }
    
    if(node->data == x) {
        if(node->left == NULL && node->right == NULL) {
            if(x < parent->data) {
                free(node);
                parent->left = NULL;
            }
            else {
                free(node);
                parent->right = NULL;
            }
        }
        else if(node->left != NULL) {
            node->data= node->left->data;
            free(node->left);
            node->left = NULL;
        }
        else {
            Node* tempnode = node;
            Node* prevnode = NULL;
            if(tempnode->right != NULL) {
                prevnode = tempnode;
                tempnode = tempnode->right;
                while(tempnode->left != NULL) {
                    prevnode = tempnode;
                    tempnode = tempnode->left;
                }
            }
            node->data = tempnode->data;
            if(tempnode->data < prevnode->data) {
                free(tempnode);
                prevnode->left = NULL;
            }
            else {
                free(tempnode);
                prevnode->right = NULL;
            }
        }

    }
    else if(x < node->data) {
        deleteNode(node->left, node, x);
    }
    else {
        deleteNode(node->right, node, x);
    }  
}

void delete(BST* bst, int x) {
    if(bst->root != NULL && bst->root->data == x) {
        if(bst->root->left == NULL && bst->root->right == NULL) {
            Node* delnode = bst->root;
            bst->root == NULL; 
            free(delnode);
        }
        else if (bst->root->left != NULL){
            bst->root->data = bst->root->left->data;
            free(bst->root->left);
            bst->root->left = NULL;
        }
        else {
            Node* tempnode = bst->root;
            Node* prevnode = NULL;
            if(tempnode->right != NULL) {
                prevnode = tempnode;
                tempnode = tempnode->right;
                while(tempnode->left != NULL) {
                    prevnode = tempnode;
                    tempnode = tempnode->left;
                }
            }
            bst->root->data = tempnode->data;
            if(tempnode->data < prevnode->data) {
                free(tempnode);
                prevnode->left = NULL;
            }
            else {
                free(tempnode);
                prevnode->right = NULL;
            }
        }
    }
    else {
        deleteNode(bst->root, NULL, x);
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
            case 1: scanf("%d", &x); insert(bst, x); break;
            case 2: scanf("%d", &x); delete(bst, x); break;
            case 3: scanf("%d", &x); search(bst->root, x); break;
            case 4: inorder(bst->root); printf("\n"); break;
            case 5: preorder(bst->root); printf("\n"); break;
            case 6: postorder(bst->root); printf("\n"); break;
            case 7: return 0;
        }
    }
}