#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};

bool areMirrors(struct Node* root1, 
                  struct Node* root2) {

    if (root1 == NULL && root2 == NULL)
        return true;

    if (root1 == NULL || root2 == NULL)
        return false;

    return (root1->data == root2->data) &&
           areMirrors(root1->left, root2->right) &&
           areMirrors(root1->right, root2->left);
}

struct Node* createNode(int val) {
    struct Node *newNode 
      = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
  
    struct Node *root1 = createNode(1);
    root1->left = createNode(3);
    root1->right = createNode(2);
    root1->right->left = createNode(5);
    root1->right->right = createNode(4);

    struct Node *root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);
    root2->left->left = createNode(4);
    root2->left->right = createNode(5);

    if (areMirrors(root1, root2))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}

