#include<stdio.h>
int main(){
	int arr[]={1,5,22,24,28,78};
	int size=sizeof(arr)/sizeof(arr[0]);
	printf("\n%d\n",size);
	int low=0;
	int high=size-1;
	
	int element=28;
	while(low<=high)
	{
		int mid=(low+high)/2;//remember to put this line inside the loop
		
		if(arr[mid]==element){
		printf("\nelement at pos %d\n",mid+1);
		return 0;

		}
		if(arr[mid]<element){
		low=mid+1;
		}
		
		else{
		high=mid-1;
		}
		
		
	
	
	}
	printf("\nelement not found\n");
	
	return 0;
}
