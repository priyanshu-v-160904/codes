
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int maxLevel = 0;

void leftViewUtil(struct Node* root, int level) {
    if (root == NULL) return;
    if (maxLevel < level) {
        printf("%d ", root->data);
        maxLevel = level;
    }
    leftViewUtil(root->left, level + 1);
    leftViewUtil(root->right, level + 1);
}

void leftView(struct Node* root) {
    leftViewUtil(root, 1);
}

int main() {
    struct Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->left->right = newNode(50);
    root->right->right = newNode(60);
    root->left->right->left = newNode(70);

    printf("Left view of the tree: ");
    leftView(root);

    return 0;
}