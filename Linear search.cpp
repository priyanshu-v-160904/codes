#include<stdio.h>
int main(){
	int arr[]={1,7,88,57,14,78};
	int x;
	printf("\n enter element \n");
	scanf("%d",&x);
	int n=sizeof(arr)/sizeof(arr[0]);
	int i;
	for(i=0;i<n;i++){
		if(arr[i]==x){
			printf("elemtnt %d found at in pos %d",x,i+1);
			return 0;
		}
	}
	printf("element not found");
	
	return 0;
	
}
