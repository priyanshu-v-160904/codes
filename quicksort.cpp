#include<stdio.h>
void printarray(int arr[],int n){
	int i;
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
}

int partion(int arr[],int low,int high){
	int pivot= arr[low];
	int i=low+1;
	int j=high-1;
	do{
	
	while(arr[i]<=pivot){
		i++;
	}
	while(arr[j]>pivot){
		j--;
	}
	if(i<j){
		int temp = arr[i];
		arr[i]=arr[j];
		arr[j] = temp;
		} 
	}while(i<j);
	
	int temp = arr[low];
		arr[low]=arr[j];
		arr[j] = temp;
	return j;
	
}

void quicksort(int arr[],int low,int high){
	int partionindex;
	
	if(high>low){
	
	partionindex = partion(arr,low,high);
	quicksort(arr,low,partionindex-1);
	quicksort(arr,partionindex+1,high);
	}
}

int main(){
	int arr[] ={5,6,1,2,4,3,78};
	printarray(arr,7);
	quicksort(arr,0,7);
	printf("\n");
	printarray(arr,7);	
}
