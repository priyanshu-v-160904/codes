#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TrieNode {
    struct TrieNode *children[26];
    bool isEnd;
};

struct TrieNode *newNode() {
    return (struct TrieNode *)calloc(1, sizeof(struct TrieNode));
}

void insert(struct TrieNode *root, const char *word) {
    while (*word) {
        int i = *word - 'a';
        if (!root->children[i]) root->children[i] = newNode();
        root = root->children[i];
        word++;
    }
    root->isEnd = true;
}

bool search(struct TrieNode *root, const char *word) {
    while (*word) {
        int i = *word - 'a';
        if (!root->children[i]) return false;
        root = root->children[i];
        word++;
    }
    return root->isEnd;
}

int main() {
    struct TrieNode *root = newNode();
    insert(root, "cat");
    insert(root, "dog");
    printf("%s\n", search(root, "cat") ? "Found" : "Not Found");
    printf("%s\n", search(root, "dog") ? "Found" : "Not Found");
    printf("%s\n", search(root, "rat") ? "Found" : "Not Found");
    return 0;
}
