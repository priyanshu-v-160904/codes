#include<stdio.h>
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
	
	for(i=0;i<n-1;i++){
		int min=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
			int t;
			t=arr[i];
			arr[i]=arr[min];
			arr[min]=t;
		}
		
	}
	printf("\narray array sorting \n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}

		
}

