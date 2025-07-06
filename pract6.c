#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); // Sort in descending order
}

int maxProductThree(int arr[], int n) {
    qsort(arr, n, sizeof(int), cmp);
    
    int count = 0, product = 1, prev = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != prev) {
            product *= arr[i];
            prev = arr[i];
            count++;
            if (count == 3) return product;
        }
    }
    return -1; // Not enough distinct elements
}

int main() {
    int arr[] = {10, 20, 20, 5, 30, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = maxProductThree(arr, n);
    if (result == -1)
        printf("Not enough distinct elements!\n");
    else
        printf("Max product of three distinct elements: %d\n", result);
    
    return 0;
}
