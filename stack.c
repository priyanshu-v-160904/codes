#include<stdio.h>

#define max 100
int top=-1;
int is_empty(){
    if(top==-1){
        return 1;
    }
    else{
        return 0;
    }

}
int is_full(){
    if(top==max-1){
        return 1;

    }
    else{
        return 0;
    }
}
void push(int *arr){
    if(is_full()){
        printf("stack_overflow");
        return;
    }
    else{
        printf("enter the element\n");
        int c;
        scanf("%d",&c);
        top++;
        arr[top]=c;
        return;
    }

}
void pop(int *arr){
    if(is_empty()){
        printf("stack_underflow\n");

    }
    else{
        int x;
        printf("poppd item is %d\n",arr[top]);
        top--;
        return;
    }
}
void traverse(int *arr){
    printf("elements of stack are \n");
    for(int i=0;i<=top;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int main(){
    int arr[max];
    
    
   if(is_empty()){
    printf("stack is empty\n");
   } 
   else{
    printf("stack is not empty\n");

   }
   if(is_full()){
    printf("stack is full\n");
    
   }
   else{
    printf("not full\n");
   }
   while(1){
    printf("Enter the choice\n1.push\n2.pop\n3.traverse\n4.break\n");
    int x;
    scanf("%d",&x);
    switch (x)
    {

    
    case 1:
    push(arr);
    break;
    case 2:
    pop(arr);
    break;
    case 3:
    traverse(arr);
    
    break;
    case 4:
    return 0;

    

    }
    

}

    

    
}