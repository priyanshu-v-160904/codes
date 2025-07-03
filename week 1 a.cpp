#include <stdio.h>
#include<stdlib.h>

int main(){
	printf("enter the size of the array\n");
	int n;
	scanf("%d",&n);
	int *a;
	a=(int *)malloc(sizeof(int)*n);
	int i;
	for(i=0;i<n;i++){
		printf("\nenter element\n");
		scanf("%d",&a[i]);
	}
	int nsize;
	printf("enter new size");
	scanf("%d",&nsize);
	if(n>nsize){
		printf("\nnew array is\n");
		for(i=0;i<nsize;i++){
		printf("%d ",a[i]);
		
		}
	
	
	}
	
	else{
		a=(int *)realloc(a,sizeof(int)*nsize);
		for(n;n<nsize;n++){
			printf("\enter elements \n");
			scanf("%d",&a[n]);
		}
		printf("\n final array is\n");
		for(i=0;i<nsize;i++){
		printf("%d ",a[i]);
	
		}
	}

	
	printf("\nEOP\n");
	return 0;
	
}
