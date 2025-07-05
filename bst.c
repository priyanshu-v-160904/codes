#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* left;
    int data;
    struct node* right;

};
struct node* createnode(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->left=NULL;
    newnode->data=data;
    newnode->right=NULL;
    return newnode;
}
void preorder(struct  node* x){
    if(x!=NULL){
        printf("%d ", x->data);
        preorder(x->left);
        preorder(x->right);
    }
}
void insert(struct node* ptr,int x){
    struct node* prev;
    struct node* newnode=createnode(x);
    while(ptr!=NULL){
        prev=ptr;
        if(ptr->data==x){
            printf("value  %d already present\n",x);
            return;
        }
        else if(ptr->data>x){
            ptr=ptr->left;
        }
        else{
            ptr=ptr->right;
        }
    }
    //from here we got pos of node where to insert it is in prev node
    if(prev->data>x){
        prev->left=newnode;

    }
    else{
        prev->right=newnode;
    }
}

int main(){
    struct node* root=createnode(10);
    insert(root,2);
    insert(root,11);
    insert(root,3);
    insert(root,3);
    
    preorder(root);



}