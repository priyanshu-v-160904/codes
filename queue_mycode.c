#include<stdio.h>
#define max 100
int rear,front;
int rear=0;
int front=0;
int arr[max];
int isfull(){
    if(rear==max-1){
        printf("queue is full\n");
        return 1;

    }
    else{
        return 0;
    }
}
int isempty(){
    if(rear==front){
        printf("queue is empty");
        return 1;

    }
    else{
        return 0;
    }
}
void enque(int x){
    if(isfull()){
        printf("\ncannot insert queue is full\n");
    }
    else{
        arr[rear]=x;
        rear++;
    }
}
void deque(){
    if(isempty()){
        return;
    }
    else{
        printf("\ndequeued element is %d\n",arr[front]);
        front++;
    }
}

void traverse(){
    for(int i=front;i<rear;i++){
        printf("%d ",arr[i]);

    }

}
void search(int x){
    int count=front;
    int j=1;
    while(count<rear){
        

        if(arr[count]==x){
            printf("element present at pos %d \n",j);
            return;
        }
        j++;
        count++;


    }
    printf("\n not present");
    return;
}



int main(){
    
    enque(5);
    enque(6);
    traverse();
    deque();
    search(6);
   
   


}