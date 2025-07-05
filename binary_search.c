#include<stdio.h>
//take sorted array
int main(){
    int n;
    int arr[10]={1,12,14,55,67,89,91,96,111,121};
    int low,mid,high;
    low=0;
    n=sizeof(arr)/sizeof(arr[0]);
    high=n-1;
    int x;
    printf("\nelements to search in array\n");
    scanf("%d",&x);
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==x){
            printf("element found at pos %d",mid+1);
            return 0;

        }
        else if(x<arr[mid]){
            high=mid-1;

        }
        else{
            low=mid+1;
        }
        
    }
    printf("not found");
}