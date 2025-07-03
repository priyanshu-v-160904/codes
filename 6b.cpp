#include<stdio.h>
int main(){
	int arr[]={1,2,3,4,5,6,7,8,9};
	int n=sizeof(arr)/sizeof(arr[1]);
	int i=0;
	printf("\n odd pos element product \n");
	for(i=0;i<n-1;i=i+2){
		int product=1;
		product=arr[i]*arr[i+2];
		printf("%d ",product);
		
	}
	
	printf("\nfor product\n");
	for(i=1;i<n-2;i=i+2){
		int sum=0;
		sum=arr[i]+arr[i+2];
		printf("%d ",sum);
	}
	return 0;
}
