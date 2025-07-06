#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}; 
int height(struct Node* root) {
    if (root == NULL)
        return -1;

    int lHeight = height(root->left);
    int rHeight = height(root->right);

    return (lHeight > rHeight ? lHeight : rHeight) + 1;
}

struct Node* createNode(int val) {
    struct Node* node 
      		= (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int main() {

    struct Node* root = createNode(12);
    root->left = createNode(8);
    root->right = createNode(18);
    root->left->left = createNode(5);
    root->left->right = createNode(11);
    
    printf("%d", height(root));
    
    return 0;
}


