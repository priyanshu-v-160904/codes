#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createnode(int x)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}

void printls(struct Node* head)
{
    struct Node* current=head;
    while(current!=NULL)
    {
        printf("%d ",current->data);
        current=current->next;
    }
    printf("\n");
}

void swapnode(struct Node* head)
{
    if(head==NULL||head->next==NULL)
    {
        return;
    }
    int temp=head->data;
    head->data=head->next->data;
    head->next->data=temp;
    
    swapnode(head->next->next);
}

int main()
{
    struct Node* head=createnode(1);
    head->next=createnode(2);
    head->next->next=createnode(3);
    head->next->next->next=createnode(4);
    head->next->next->next->next=createnode(5);
	printls(head);
	swapnode(head);
    printls(head);
    return 0;
}

