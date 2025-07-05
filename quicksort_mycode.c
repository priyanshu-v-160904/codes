#include<stdio.h>
int partition(int arr[],int low,int high){
    int i,j;
    j=high;
    i=low+1;
    int pivot=arr[low];//we  cannot change pivot value
    do{
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<j){
            int t;
            t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
        }

    }while(i<j);
    int x;
    x=arr[j];
    arr[j]=arr[low];//change low value not pivot value
    arr[low]=x;
    return j;

}
void quickSort(int arr[],int low,int high){
    int part;
    if(high>low){
        part=partition(arr,low,high);
        quickSort(arr,low,part-1);
        quickSort(arr,part+1,high);
    
    }
}
int main(){
    int arr[]={5,23,16,74,22,56};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);

    }
    quickSort(arr,0,6);
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);

    }
}