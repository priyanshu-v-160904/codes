#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	int value;
	struct Node* left;
	struct Node* right;
}Node;

Node* create_node(int value){
	Node* newnode = (Node*)malloc(sizeof(Node));
	newnode->value=value;
	newnode->left=newnode->right=NULL;
}


typedef struct Bst{
	Node* root;
} Bst;

void insertnode(Node* node,int value){
	if(value<node->value){
		if(node->left){
			insertnode(node->left,value);
		}
		else
		node->left= create_node(value);
	}
	else{
		if(node->right){
			insertnode(node->right,value);
		}
		else
		node->right= create_node(value);
	}
	
}


void insert(Bst* bst,int value){
	if(!bst->root){
		bst->root= create_node(value);
	}
	else{
		insertnode(bst->root,value);
	}
}

void _inorder(Node* node){
	if(node){
		_inorder(node->left);
		printf("%d ",node->value);
		_inorder(node->right);
	}
}

void inorder(Bst* bst){
	_inorder(bst->root);
}



int main(){
	Bst bst;
	bst.root=NULL;
	
	insert(&bst,15);
	insert(&bst,10);
	insert(&bst,12);
	insert(&bst,4);
	insert(&bst,65);
	insert(&bst,76);
	insert(&bst,5);
	inorder(&bst);
}
