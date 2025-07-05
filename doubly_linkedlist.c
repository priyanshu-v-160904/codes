#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node* prev;


};
struct node* head;
struct node* create(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;

    return newnode;
}
void insertLast(int data){
    struct node* newnode=create(data);
    if(head==NULL){
        head=newnode;
    }
    else{
        struct node* ptr;
        ptr=head;
        while(ptr->next!=NULL){
            ptr=ptr->next;


        }
        ptr->next=newnode;  
        newnode->prev=ptr;


    }
}
void insertfirst(int data){
    struct node* newnode=create(data);
    newnode->next=head;
    
    head->prev=newnode;
    head=newnode;


}
void traverse(){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");

    
}
int search(int x){
    struct node* ptr=head;
    while(ptr!=NULL){
        if(ptr->data==x){
            return 1;
        }
        ptr=ptr->next;
    }
    return 0;
}
void insertatpoint(int value,int dat){
    struct node* newnode=create(dat);
    struct node* ptr=head;
    if(search(value)){
        while(ptr->data!=value){
        ptr=ptr->next;
        }
        newnode->next=ptr->next;
        ptr->next->prev=newnode;//imp line
        ptr->next=newnode;
        newnode->prev=ptr;
        




    }
    else{
        printf("no such element no insertion can be done");
        
    }


}
void revtrav(){
    struct node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;

    }
    printf("\n rev trav\n");
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->prev;

    }

}


int main(){
    insertLast(10);
    insertLast(20);
    traverse();
    insertfirst(5);
    traverse();
    insertatpoint(10,15);
    traverse();
    revtrav();



}