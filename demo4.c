#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
struct node * head = NULL;
void insertatbegin(int value){
	struct node* newnode = (struct node*) malloc(sizeof(struct node));
	newnode->data = value;
	newnode->next = NULL;
	if(head==NULL){
	
	head = newnode;
	newnode->next=head;}
	else{
		struct node*temp = head;
		while(temp->next!=head)
		{
			temp = temp->next;
		}
		newnode->next = temp->next;
		temp->next=newnode;
		head=newnode;
	}
}
void traverse(){
	struct node* temp = head;
	while(temp->next!=head){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("%d ",temp->data);
}
int main(){
	insertatbegin(20);
	insertatbegin(30);
//	insertatbegin(40);
	traverse();
	}
