#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int x)
{
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}

void printls(struct Node* node)
{
    while(node!=NULL)
    {
        printf("%d",node->data);
        node=node->next;
    }
    printf("\n");
}

struct Node *getmergepoint(struct Node* head1, struct Node* head2) 
{
    struct Node *temp;
    while (head2 != NULL) 
    {
        temp = head1;
        while (temp != NULL)
        {
            if (temp == head2)
            {
                return head2;
            }
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return NULL;
}
int main()
{
  
    struct Node* head1 = createNode(9);
    head1->next = createNode(11);
    head1->next->next = createNode(40);

    struct Node* head2 = createNode(3);
    head2->next = createNode(7);
    head2->next->next = createNode(8);
    head2->next->next->next = head1->next; 

    struct Node* mergepoint= getmergepoint(head1, head2);

    if (mergepoint == NULL)
    {
        printf("No merge Point\n");
    }
    else
    {
        printf("Merge Point: %d\n",mergepoint->data);
    }
    return 0;
}


