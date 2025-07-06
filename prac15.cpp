#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}


Node* LCA(Node* root, Node* n1, Node* n2) {
    if (root == NULL)
        return NULL;

    if (root->data > n1->data && root->data > n2->data)
        return LCA(root->left, n1, n2);

    if (root->data < n1->data && root->data < n2->data)
        return LCA(root->right, n1, n2);

    return root;
}

int main() {
    // Representation of input BST:
    //            20
    //           /  \
    //          8    22
    //        /   \     
    //       4    12   
    //           /   \   
    //         10    14  
    Node* root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    Node* n1 = root->left->left; // Node 4
    Node* n2 = root->left; // Node 8
  
    Node* res = LCA(root, n1, n2);
    printf("%d", res->data);

    return 0;
}


