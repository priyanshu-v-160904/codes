#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* createNode(int x)
{
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}
Node* merge(Node* a,Node* b)
{
    Node* result=NULL;
    if(a==NULL)
    {
        return b;
    }
    else if(b==NULL)
    {
        return a;
    }
    
    if(a->data<=b->data)
    {
        result=a;
        result->next=merge(a->next,b);
    }
    else
    {
        result=b;
        result->next=merge(a,b->next);
    }
    return result;
}
int main()
{
    Node* a=createNode(1);
    a->next=createNode(3);
    a->next->next=createNode(5);
    a->next->next->next=createNode(7);
    a->next->next->next->next=createNode(9);
    
    Node* b=createNode(0);
    b->next=createNode(2);
    b->next->next=createNode(4);
    b->next->next->next=createNode(6);
    b->next->next->next->next=createNode(8);
    
    Node* z=merge(a,b);
    Node* temp=z;
    printf("merged linked list is:\n");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}

