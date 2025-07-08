#include <stdio.h>

int main() {
    int arr[10];
    double *ptr = arr;

    printf("Size of arr: %zu\n", sizeof(arr));
    printf("Size of ptr: %zu\n", sizeof(ptr));
    return 0;
}
