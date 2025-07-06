#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

// Structure for key-value pair
typedef struct {
    char key[50];
    int value;
} HashEntry;

HashEntry hashTable[TABLE_SIZE];

// Simple hash function
int hash(char *key) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

// Insert key-value pair
void insert(char *key, int value) {
    int index = hash(key);
    strcpy(hashTable[index].key, key);
    hashTable[index].value = value;
}

// Retrieve value by key
int get(char *key) {
    int index = hash(key);
    if (strcmp(hashTable[index].key, key) == 0)
        return hashTable[index].value;
    return -1; // Not found
}

int main() {
    insert("apple", 100);
    insert("banana", 200);
    
    printf("apple: %d\n", get("apple"));
    printf("banana: %d\n", get("banana"));
    printf("grape: %d\n", get("grape")); // Not found
    
    return 0;
}
