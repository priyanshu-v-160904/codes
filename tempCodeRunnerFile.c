#include <stdio.h>
#include <stdlib.h>
//insert at last 
//insert at begining
//insert at point
//delete all three
//traverse and traverse back

struct node{
    int data;
    struct node* next;

};

struct node* head=NULL;
struct node* create(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
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
        


        

    }




}


void traverse(){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");

    
}
void insertfirst(int data){
    struct node* newnode=create(data);
    newnode->next=head;
    head=newnode;
}
int search(int x){
    struct node* ptr=head;
    while(ptr->next!=NULL){
        if(ptr->data==x){
            return 1;
        }
        ptr=ptr->next;
    }
    if(ptr->data==x){
        return 1;
    }
    else{
        return 0;
    }
}
void insertatpoint(int value,int dat){
    struct node* newnode=create(dat);
    struct node* ptr=head;
    if(search(value)){
        while(ptr->data!=value){
        ptr=ptr->next;
        }
        newnode->next=ptr->next;
        ptr->next=newnode;



    }
    else{
        printf("no such element no insertion can be done");
        
    }


}

int main(){
    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertLast(40);
    traverse();
    insertfirst(5);
    traverse();
    insertatpoint(10,3);
    traverse();
    
    printf("\nEOP\n");
}