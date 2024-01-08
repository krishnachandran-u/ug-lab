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

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

Node* minValueNode(Node* node) {
    Node* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

Node* deleteNode(Node* root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void deleteBST(Node* root) {
    if (root == NULL) {
        return;
    }

    deleteBST(root->left);
    deleteBST(root->right);
    free(root);
}

void displayInorder(Node* root) {
    if (root == NULL) {
        return;
    }

    displayInorder(root->left);
    printf("%d ", root->data);
    displayInorder(root->right);
}

int main() {
    BST bst;
    init(&bst);

    int choice, data;

    printf("\nBinary Search Tree Operations:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to be inserted: ");
                scanf("%d", &data);
                bst.root = insertNode(bst.root, data);
                break;
            case 2:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                bst.root = deleteNode(bst.root, data);
                break;
            case 3:
                printf("Binary Search Tree: ");
                displayInorder(bst.root);
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    deleteBST(bst.root);

    return 0;
}
