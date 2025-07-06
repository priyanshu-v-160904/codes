#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26

struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode* createNode() {
    struct TrieNode* node = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void insert(struct TrieNode* root, char* word) {
    struct TrieNode* current = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!current->children[index]) {
            current->children[index] = createNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
}

int countWords(struct TrieNode* root) {
    int count = 0;
    if (root->isEndOfWord) {
        count++;
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            count += countWords(root->children[i]);
        }
    }
    return count;
}

int main() {
    struct TrieNode* root = createNode();
    insert(root, "hello");
    insert(root, "world");
    insert(root, "trie");
    insert(root, "data");
    insert(root, "structure");
    printf("Number of words in Trie: %d\n", countWords(root));
    return 0;
}