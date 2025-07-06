#include<stdio.h>
void printarray(int arr[],int n){
	int i;
	for(i=0;i<n;i++)
	printf("%d ",arr[i]);
	printf("\n");
}

int partition(int arr[],int low,int high){
	int pivot = arr[low];
	int i = low+1;
	int j= high;
	do{
	while(arr[i]<=pivot){
		i++;
	}
	while(arr[j]>pivot){
		j--;
	}
	
	if(i<=j){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		}
	}while(i<j);
	int temp =arr[j];
	arr[j] = arr[low];
	arr[low] = temp;
	return j;
}

void quicksort(int arr[],int low,int high){
	int partition_index;
	if(low<high){
		partition_index = partition(arr,low,high);
		quicksort(arr,low,partition_index-1);
	
		quicksort(arr,partition_index+1,high);
	
	}	
}





int main(){
	int arr[]={5,6,1,2,4,3,78};
	int n = 7;
	printarray(arr,n);
	quicksort(arr,0,n-1);
	printarray(arr,n);
}
