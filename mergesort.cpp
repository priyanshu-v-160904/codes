#include<stdio.h>

void printarray(int arr[],int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

void merge(int arr[],int low,int mid,int high){
	int i,j,k,b[100];
	
	i = low;
	j= mid+1;
	k= low;
	while(i<=mid && j<=high){
		if(arr[i]<arr[j]){
			b[k]=arr[i];
			i++;k++;
		}
		else{
			b[k]=arr[j];
			j++;k++;
		}
	}
	while(i<=mid){
		b[k]=arr[i];
		i++;k++;
	}
	while(j<=high){
		b[k]=arr[j];
		k++;j++;
	}
	int l;
	for(l=0;l<=high;l++)
		arr[l]=b[l];

}



void mergesort(int arr[],int low,int high){
	int mid = (low+high)/2;
	if(high>low){
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
	
}

int main(){
	int arr[]={5,8,10,4,1,9,7,45};
	int n = 8;
	printarray(arr,n);
	mergesort(arr,0,n-1);
	printf("\n");
	printarray(arr,n);
}
