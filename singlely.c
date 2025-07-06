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
	if(head==NULL)
	head = newnode;
	else{
		newnode->next = head;
		head = newnode;
	}
}
void insertatlast(int value){	
	struct node* val= (struct node*)malloc(sizeof(struct node));
	val->data = value;
	val->next = NULL;
	struct node* temp=head; 
	if(head==NULL){
		val=head;
	}	
	else{	
		while(temp->next!=NULL){
		//printf("%d ",temp->data);
		temp = temp->next;	
	}
	temp-> next= val;
	}
}
void insertatkey(int key,int value){
	struct node* val= (struct node*)malloc(sizeof(struct node));
	val->data = value;
	val->next = NULL;
	struct node* temp=head;
	while(temp->data!= key){
		temp=temp->next;
	}
	val-> next=temp->next;
	temp->next = val;
}
void insertatposition(int pos, int value){
	struct node* val= (struct node*)malloc(sizeof(struct node));
	val->data = value;
	val->next = NULL;
	int i;
	struct node* temp=head;
	for( i=1; i<=pos ;i++){
	temp=temp->next;
	}
	val-> next=temp->next;
	temp->next = val;
}
void deleteatbegin(){
	if(head==NULL){
		printf("Empty List.");
	}
	else if(head->next==NULL){
		free(head);
		head=NULL;
	}
	else{
		struct node * ptr = head;
		head=head->next;
		free(ptr);
		}
}
void deletionatlast(){
	struct node* ptr;
	struct node* temp = head;
	if(head==NULL){
		printf("Empty List.");
	}
	else if(head->next==NULL){
		free(head);
		head=NULL;
	}
	else{
		while(temp->next!=NULL){
		ptr=temp;
		temp = temp->next;
	}
	free(temp);
	ptr->next= NULL;
		
	}
}
void traverse(){
	struct node* temp = head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
int main(){
	
	insertatbegin(20);
	insertatbegin(30);
	insertatbegin(40);
	insertatlast(50);
	insertatkey(30,10);
	insertatposition(3,60);
	deleteatbegin();
	deletionatlast();
	traverse();
}
