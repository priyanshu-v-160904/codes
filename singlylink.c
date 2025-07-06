#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
struct Node* create(int value){
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;

	
}
struct Node* head=NULL;
void insertlast(int value){
	struct Node* newNode=create(value);
	if(head == NULL){
		head=newNode;
	}
	else {
		struct Node* temp = head;
		while (temp->next!=NULL){
			temp = temp->next;
		}
		temp->next =newNode ;
		
	}
}
void insertatpoint(int value,int point){
	struct Node* newNode=create(value);
	struct Node* temp = head;
	int i =0;
	for(i=0;i<point-2;i++){
		temp = temp->next;
		if(temp==NULL){
			printf("Invalid input..\n");
		}
	}
	newNode->next = temp->next;
	temp->next= newNode;
}
void insertafterkey(int value,int key){
	struct Node* newNode=create(value);
	struct Node* temp = head;
	while (temp->data!= key){
		
		temp = temp->next;
	}	
	newNode->next = temp->next;
	temp->next = newNode;
}
void insertbegin(int value){
	struct Node* newNode=create(value);
		if(head == NULL){
		head=newNode;
	}
	else {
	
	newNode->next = head;
	head = newNode;}
}
void deleteatbegin(){
	if(head == NULL){
		printf("Empty Linked list::\n");
	}
	else if(head->next==NULL){
		free(head);
		head = NULL;
	}
	else{
		struct Node* ptr = head;
		head = head->next;
		free(ptr);	
	}
}
void deleteatlast(){
	if(head == NULL){
		printf("Empty list\n");
	}
	else if(head->next==NULL){
		struct Node* ptr = head;
		head = head->next;
		free(ptr);
	}
	else{
		struct Node* temp = head;
		struct Node* prev;
		while(temp->next !=NULL){
			prev = temp;
			temp = temp->next;
	}
	prev->next = NULL;
	free(temp);
	}
}
void deleteatpoint(int point){
	int i=0;
	struct Node* temp = head;
	struct Node* prev;
	for(i=0;i<point-1;i++){
		prev = temp;
		temp = temp->next;
		if(temp == NULL){
			printf("Invalid input\n");
		}
	}
	prev->next = temp->next;
	free(temp);
}
void traverse(){
	struct Node* temp = head;
	while (temp!=NULL){
			printf("%d ",temp->data);
			temp = temp->next;
		}
}
int main(){
	insertlast(10);
	insertlast(20);
	insertbegin(50);
	insertlast(30);
	insertafterkey(40,10);
	insertatpoint(89,3);
	deleteatbegin();
	deleteatpoint(2);
	deleteatlast();
	traverse();
	}

