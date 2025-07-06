#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void printLeftBoundary(struct Node* root) {
    if (root == NULL) return;
    
    if (root->left) {
        printf("%d ", root->data);
        printLeftBoundary(root->left);
    }
}

void printLeafNodes(struct Node* root) {
    if (root == NULL) return;

    printLeafNodes(root->left);
    
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
    }

    printLeafNodes(root->right);
}

void printRightBoundary(struct Node* root) {
    if (root == NULL) return;
    
    if (root->right) {
        printRightBoundary(root->right);
        printf("%d ", root->data);
    } 
}

void boundaryTraversal(struct Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);

    printLeftBoundary(root->left);

    printLeafNodes(root);

   printRightBoundary(root->right);
}

struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return createNode(key);

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

int main() {
    struct Node* root = NULL;


    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);
    root = insert(root, 2);
    root = insert(root, 7); 
    root = insert(root, 12);
    root = insert(root, 17);

    printf("Boundary Traversal of BST: ");
    boundaryTraversal(root);
    printf("\n");

    return 0;
}

