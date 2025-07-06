#include<stdio.h>
int main(){
	int arr[] = {5,32,2,45,34,23,64};
	int n = sizeof(arr)/sizeof(arr[0]);
	int i,j;
	for(i=0;i<n;i++){
		int next=-1;
		for(j=i+1;j<n;j++){
			if(arr[i]<arr[j]){
				next = arr[j];
				break;
			}
			
		}
		printf("%d->%d ",arr[i],next);
	}
}

