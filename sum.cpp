// write a program to find the sum of the elements of the array using pointers
#include<stdio.h>
int sum_array(int *p,int x){
	int i;
	int sum=0;
	for(i=0;i<x;i++){
		sum=sum+*(p+i);
		
	}
	return sum;
}
int main(){
	int n;
	printf("enter size of array\n");
	scanf("%d",&n);
	int arr[n];
	int i;
	for(i=0;i<n;i++){
		printf("\nenter element %d\n",i+1);
		scanf("%d",&arr[i]);
	}
	int sum=sum_array(arr,n);
	printf("\nsum is %d\n",sum);
	return 0;
}
