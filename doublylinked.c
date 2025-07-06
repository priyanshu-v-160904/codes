#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node* prev;
	int data;
	struct Node* next;
};
struct Node* head = NULL;
void insertatbegin(int value){
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data=value;
	newnode->next = NULL;
	newnode->prev = NULL;
	if(head == NULL){
		head = newnode;
	}
	else{
		newnode->next=head;
		head->prev = newnode;
		head = newnode;	
	}	
}
void insertatend(int value){
	struct Node* newnode = (struct Node* )malloc(sizeof(struct Node));
	newnode->data=value;
	newnode->next = NULL;
	newnode->prev = NULL;
		if(head == NULL){
		head = newnode;
	}
	else{
	struct Node * temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
		}
		newnode->prev = temp;
		temp->next = newnode;
	}
}
void insertafterkey(int value,int key){
	struct Node* newnode = (struct Node* )malloc(sizeof(struct Node));
	newnode->data=value;
	newnode->next = NULL;
	newnode->prev = NULL;
	if(head == NULL){
		printf("No key exist:\n");
	}
	else{
	struct Node * temp = head;
	while(temp->data!=key){
		temp = temp->next;
		}
		newnode->prev = temp;
		newnode->next = temp->next;
		temp->next = newnode;
		newnode->next->prev = newnode;
	}
}
void traverse(){
	struct Node * temp = head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	
}
void traverseback(){
	struct Node * temp = head;
	struct Node *back ;
	while(temp!=NULL){
		//printf("%d ",temp->data);
		back = temp;
		temp = temp->next;
	}
	while(back!=NULL){
		printf("%d ",back->data);
		back = back->prev;
	}	
}
void deletionatfirst(){
	if(head==NULL){
		printf("Linkedlist is Empty...\n");
	}
	else if(head->next == NULL){
		free(head);
	}
	else{
	head = head->next;
	free(head->prev);
	head->prev = NULL;
	}
}
void deletionatlast(){
	if (head==NULL){
		printf("Linkedlist is Empty...\n");
	}
	else{
		struct Node * temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
		}
		temp->prev->next = NULL;
		free(temp);
	}
}
void deletionatkey(int key){
	struct Node * temp = head;
	while(temp->data!=key){
		temp = temp->next;
		}
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);	
}
int main(){
	insertatbegin(10);
	insertatbegin(20);
	insertatbegin(30);
	insertatbegin(40);
	insertatend(50);
	insertatend(45);
	insertafterkey(60,30);
	deletionatfirst();
	deletionatlast();
	deletionatkey(20);
	traverse();
	printf("\n");
	traverseback();
	return 0;
}

