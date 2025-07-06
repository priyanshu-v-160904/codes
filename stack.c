#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

int isFull() {
    return top == MAX_SIZE - 1;
}

int isEmpty() {
    return top == -1;
}

void push(int data) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = data;
    printf("%d pushed to stack\n", data);
}

int pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1; // Or any error value
    }
    int data = stack[top];
    top--;
    return data;
}

void show() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");int i;
    for ( i=top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Show\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                if (data != -1) {
                    printf("%d popped from stack\n", data);
                }
                break;
            case 3:
                show();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
