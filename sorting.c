#include<stdio.h>
void bubblesort(int arr[],int n){
    int i,j;
    
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int t;
                t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
}void insertionsort(int arr[],int n){
    int i;
    for(i=1;i<n;i++){
        int key=arr[i];
        
        int j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;

            
        }
        arr[j+1]=key;
    }
}
void selectionsort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int index=i;
        int j=i+1;

        while(j<n){
            if(arr[j]<arr[index]){
                index=j;
                
            }
            j++;


        }
        int t;
        t=arr[i];
        arr[i]=arr[index];
        arr[index]=t;
    }
}

int main(){
    int arr[10]={1,7,22,4,55,65,3,66,30,55};
    //We cannot fint size of something using its address
    int n=sizeof(arr)/sizeof(arr[0]);
    selectionsort(arr,n);
    printf("\n sorted array is\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}