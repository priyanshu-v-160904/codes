#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node *prev;
    int data;
    struct node* next;
    
};
int main(){
    struct node* head=(struct node*)malloc(sizeof(struct node));
    struct node* second=(struct node*)malloc(sizeof(struct node));
    struct node* third=(struct node*)malloc(sizeof(struct node));
    head->next=second;
    second->prev=head;
    head->prev=NULL;
    second->next=NULL;
    head->data=1;
    second->data=2;
    
    printf("%d %d",head->data,second->data);
    struct node* ptr;
    ptr=second;
    ptr->prev->next=NULL;
    free(ptr);
    printf(" %d \n",head->data);
}