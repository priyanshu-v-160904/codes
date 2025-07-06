#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

int *stack, *minStack;  
int top = -1;
int capacity;  

void initStack(int size) {
    capacity = size;
    stack = (int *)malloc(capacity * sizeof(int));

    if (stack == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Stack initialized with capacity %d\n", capacity);
}


void push(int val) {
    if (top >= capacity - 1) {
        printf("Stack Overflow! Cannot push %d\n", val);
        return;
    }
    stack[++top] = val;
    printf("Pushed %d onto stack.\n", val);
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }
    int poppedValue = stack[top--];
    printf("Popped %d from stack.\n", poppedValue);
}

int getTop() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return INT_MIN;
    }
    return stack[top];
}
int getMin(){
	if(top==-1){
		printf("Stack is Empty\n");
		return -1;
	}
	int min = stack[0];
	int i;
	for(i=1;i<=top;i++){
		if (min>stack[i]){
			min = stack[i];
		}
	}
	return min;
}
void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void freeStack() {
    free(stack);
}
int main() {
    int size, choice, value;
    printf("Enter the stack size: ");
    scanf("%d", &size);
    
    initStack(size);

    while (1) {
        printf("\n1. Push\n2. Pop\n3. Get Top\n4. Get Min\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("Top element: %d\n", getTop());
                break;
            case 4:
                printf("Minimum element: %d\n", getMin());
                break;
            case 5:
                display();
                break;
            case 6:
                freeStack();
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

