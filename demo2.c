#include<stdio.h>
#include<stdlib.h>
//creation of linked list
struct node{
    int data;
    struct node* next;
};
struct node* head;
void insertlast(int x){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    

    if(head==NULL){
        head=newnode;
    }
    else{
        struct node* temp;
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;

    

    }


}
void insertfirst(int x){
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data=x;
    ptr->next=head;
    head=ptr;

    
}
void insertatindex(int n,int x){
    struct node* ptr;
    int i;
    struct node* temp;

    for(i=0;i<n;i++){
        temp=ptr;
        ptr=ptr->next;
        

    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=temp->next;
    temp->next=newnode;


}
void insertafterkey(int key,int x){
    struct node* ptr=head;
    while(ptr->data!=key){
        ptr=ptr->next;
    }
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=ptr->next;
    ptr->next=newnode;
}

void deletefirst(){
   if(head==NULL){
    printf("empty linked list");

   }
   else if(head->next==NULL){
    free(head);
    head=NULL;
   }
   else{ 
    struct node* ptr=head;
    head=head->next;
    free(ptr);
   }

}
void deleteatlast(){
	if(head == NULL){
		printf("Empty list\n");
	}
	else if(head->next==NULL){
		
		free(head);
        head=NULL;
	}
	else{
		struct node* ptr = head;
		struct node* prev;
		while(ptr->next !=NULL){
			prev = ptr;
			ptr =ptr->next;
	}
	prev->next = NULL;
	free(ptr);
	}
}
void deleteatindex(int n){
    struct node* ptr;
    struct node* prev;
    
    int i;
    for(i=0;i<n;i++){
        prev=ptr;
        ptr=ptr->next;
        
    }
    prev->next=ptr->next;
    free(ptr);
    
}
//same concept delete at key ka. hoga bs function me arguments 1 hoga key fir while se key tak jao aur uda do prev aur ptr ke help se/

void traverse(){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
        
    }
}
int main(){
    insertlast(10);
    traverse();
    

    
}
