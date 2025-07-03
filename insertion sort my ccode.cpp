#include <stdio.h>
int main(){
	int n;
	printf("enter no of elements in the array \n");
	scanf("%d",&n);
	int i,j;
	
	int arr[n];
	for(i=0;i<n;i++){
		printf("\nenter element %d\n",i+1);
		scanf("%d",&arr[i]);
		
	}
	printf("\narray before sorting \n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
		
	}
	for(i=1;i<n;i++){
		int key=arr[i]; // the element we want to insert in the left side of the stick iykyk
		j=i-1;
		while(j>=0&&arr[j]>key){
			arr[j+1]=arr[j];
			j--; //j-- and j-1 are differrent
		}
		arr[j+1]=key;
	}
	printf("\narray array sorting \n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
