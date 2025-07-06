#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    char substr[100];
    struct Node* next;
};

void insert(struct Node** head, char* str) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->substr, str);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        if (strcmp(temp->substr, str) == 0) {
            free(newNode);
            return;
        }
        temp = temp->next;
    }
    if (strcmp(temp->substr, str) == 0) {
        free(newNode);
        return;
    }
    temp->next = newNode;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%s\n", node->substr);
        node = node->next;
    }
}

void findDistinctSubstrings(char* str) {
    int n = strlen(str);
    struct Node* head = NULL;

    for (int len = 1; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            char temp[100] = {0};
            strncpy(temp, str + i, len);
            insert(&head, temp);
        }
    }

    printList(head);
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Distinct substrings:\n");
    findDistinctSubstrings(str);
    return 0;
}