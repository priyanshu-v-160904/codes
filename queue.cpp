#include<stdio.h>
#include<stdlib.h>
int front = -1;
int rear = -1;
#define max 10
int arr[max];
void enqueue(int value){
	if(rear == max-1){
		printf("Queue overflow...\n");
	}
	else if (front==-1){
		++front;
		++rear;
		arr[front] = value;	
	}
	else{
		++rear;
		arr[rear] = value;
	}
}
int dequeue(){
	if(front == -1 ||front>rear){
		printf("Empty queue..\n");
	}
	else {
		return arr[front];
		front++;
	}
}
void search(int tar){
	int i,flag = 0;
	for(i=front;i<=rear;i++){
		if(arr[i]==tar){
			flag = 1;
			break;
		}
	}
	if (flag == 1){
		printf("Element found at %d \n",i+1);
	}
	else 
	printf("Invalid number...\n");
}
void traverse(){
	int i;
	for(i=front;i<=rear;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
int main(){
	int ch;	
	while(1){
		printf("Enter your choice:\n1 Enqueue\n2 Dequeue\n3 Search\n4 Traverse\n5 Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				{
				int a;
				printf("Enter your element:\n");
				scanf("%d",&a);
				enqueue(a);}
				break;
			case 2:
				printf("Deleted element %d\n",dequeue());
				break;
			case 3:
				{
				int c;
				printf("Enter element you wanna to search:\n");
				scanf("%d",&c);
				search(c);}
				break;
			case 4:
				{
				printf("Elements are:\n");
				traverse();}
				break; 
			case 5:
				exit(1);
				break;
	    }
	}
}
