#include<stdio.h>
#include<stdlib.h>

//structure creation
struct node{
    struct node* left;
    int data;
    struct node* right;
};
struct node* createnode(int x){
    struct node* n=(struct node*)malloc(sizeof(struct node));//this was my mistake
    
    n->data=x;
    n->left=NULL;
    n->right=NULL;
    return n;

}
void preorder(struct  node* x){
    if(x!=NULL){
        printf("%d ", x->data);
        preorder(x->left);
        preorder(x->right);
    }
}
void postorder(struct node* x){
    if(x!=NULL){
        postorder(x->left);
        postorder(x->right);
        printf("%d ",x->data);
    }
}
void inorder(struct  node* x){
    if(x!=NULL){
        inorder(x->left);
        printf("%d ", x->data);
        inorder(x->right);
    }
}

int main(){
    struct node* root;
    root = (struct node*)malloc(sizeof(struct node));
    
    root->data=10;
    
    /*struct node* p1=(struct node*)malloc(sizeof(struct node));
    struct node* p2=(struct node*)malloc(sizeof(struct node));
    struct node* p3=(struct node*)malloc(sizeof(struct node));
    struct node* p4=(struct node*)malloc(sizeof(struct node));
    p1->left=p3;
    p1->data=11;
    p1->right=p4;
    p2->left=NULL;
    p2->data=4;
    p2->right=NULL;
    p3->data=11;
    p4->data=13;
*/
    struct node* p1=createnode(1);
    
    struct node* p2=createnode(2);
    
    struct node* p3=createnode(11);
    struct node* p4=createnode(12);
    root->right=p2;
    root->left=p1;
    p1->left=p3;
    p1->right=p4;
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    inorder(root);
    





}