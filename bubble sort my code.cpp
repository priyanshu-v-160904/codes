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
	for(i=0;i<n-1;i++){// no of passes
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int t;
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
				
			}
			
		
		}
	}
	printf("\narray array sorting \n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
}
}
