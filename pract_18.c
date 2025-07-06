#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int key;
    struct Node* next;
};

struct Node* hashTable[SIZE] = {NULL};

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    struct Node** head = &hashTable[hash(key)];
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->next = *head;
    *head = newNode;
}

int search(int key) {
    struct Node* temp = hashTable[hash(key)];
    while (temp) {
        if (temp->key == key) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void delete(int key) {
    struct Node** temp = &hashTable[hash(key)];
    while (*temp) {
        if ((*temp)->key == key) {
            struct Node* toFree = *temp;
            *temp = (*temp)->next;
            free(toFree);
            return;
        }
        temp = &(*temp)->next;
    }
}

int main() {
    insert(10);
    insert(20);
    insert(30);
    if (search(20)) {
        printf("Search 20: Found\n");
    } else {
        printf("Search 20: Not Found\n");
    }
    delete(20);
    if (search(20)) {
        printf("Search 20 after deletion: Found\n");
    } else {
        printf("Search 20 after deletion: Not Found\n");
    }
    return 0;
}