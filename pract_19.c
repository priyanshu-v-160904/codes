#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

struct HashEntry {
    int key;
    int value;
};

struct HashEntry *hashTable[TABLE_SIZE];

int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

void insert(int key, int value) {
    int index = hash(key);
    hashTable[index] = (struct HashEntry *)malloc(sizeof(struct HashEntry));
    hashTable[index]->key = key;
    hashTable[index]->value = value;
}

int get(int key) {
    int index = hash(key);
    if (hashTable[index] && hashTable[index]->key == key)
        return hashTable[index]->value;
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int index = get(complement);
        if (index != -1) {
            result[0] = index;
            result[1] = i;
            return result;
        }
        insert(nums[i], i);
    }
    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* result = twoSum(nums, 4, target, &returnSize);
    if (returnSize) {
        printf("Indices: %d, %d\n", result[0], result[1]);
    } else {
        printf("No two sum solution found.\n");
    }
    free(result);
    return 0;
}
