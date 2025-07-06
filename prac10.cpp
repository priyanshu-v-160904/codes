#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

bool isBST(struct Node* root, int min, int max) {
    if (!root) return true;
    if (root->data <= min || root->data >= max) return false;
    return isBST(root->left, min, root->data) && isBST(root->right, root->data, max);
}

bool isValidBST(struct Node* root) {
    return isBST(root, INT_MIN, INT_MAX);
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    struct Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(20);
    root->right->left = createNode(9);
    root->right->right = createNode(25);

    printf("%s\n", isValidBST(root) ? "Valid BST" : "Invalid BST");
    return 0;
}
