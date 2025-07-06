#include<stdio.h>
void binarySearch(int arr[],int n, int key) {
    int low =0;
    int flag = 0;
    int high = n;
	while (low <= high) {
        int mid = (low +high) / 2; 
        if (arr[mid] == key){
            printf("\nBinary Search: Element found at %d\n",mid+1);
            flag =1;
            break;
        }
        else if (arr[mid] < key){
		    low = mid + 1;
		    }
		else
		    high = mid - 1;
		    }
		if(flag ==0)
		        printf("Element Not found");
		    }
void interpolation(int arr[],int n,int key,int low,int high){
	int pos;
	int flag = 0;
		while (high>=low){
		pos = low+((key-arr[low])*(high-low))/(arr[high]-arr[low]);
		if(arr[pos]==key){
			printf("\nInterpolation Search: Element found at %d\n",pos+1);
            flag =1;
            break;}
		if(arr[pos]>key)
			high = pos-1;
		else
			low = pos+1;
	}
	if(flag ==0)
		printf("Element Not found");
}

		 
int main(){
    int n,key;
    printf("Enter The lenght of Array:\n");
    scanf("%d",&n);
    int arr[n];
    int i;
    for(i=0;i<n;i++){
        printf("Enter your number %d:\n",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the element you want to Search:\n");
    scanf("%d",&key);
    binarySearch(arr,n,key);
    interpolation(arr,n,key,0,n-1);
}

