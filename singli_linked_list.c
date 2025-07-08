#include <stdio.h>
#include<stdlib.h>
struct node
{
     
    int data;
    struct node* next;
    struct node* prev;

};
struct node *head=NULL;



void create_node(int a){
    struct node *new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=a;
    new_node->prev=NULL;
    new_node->next=NULL;
   
    struct node *curr;
    if(head==NULL){
    head=new_node;
   
}
else{
curr=head;
while(curr->next!=NULL){
curr=curr->next;

}
curr->next=new_node;
new_node->prev=curr;

}


}
void traverse(){
struct node *ptr=head;
while(ptr->next!=NULL){
printf("%d\n",ptr->data);
ptr=ptr->next;
}
printf("%d",ptr->data);
free(ptr);
}
void insert_first(int x){
struct node *first=(struct node *)malloc(sizeof(struct node));
first->next=head;
first->data=x;
first->prev=NULL;
head->prev=first;
head=first;

}

 
int main(){
int n;


int i=0;
printf("enter the no of node you want to create\n");
scanf("%d",&n);

int x;
for(int i=0;i<n;i++){

printf("enter the data %d \n",i+1);
scanf("%d",&x);
create_node(x);

}
printf("\nlinked list is\n");
traverse();
int f;
printf("enter the element\n");
scanf("%d",&f);
insert_first(f);
traverse();
printf("enter the element\n");
scanf("%d",&f);
printf("");


}
