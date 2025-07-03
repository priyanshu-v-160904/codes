#include<stdio.h>
int main(){
	int i;
	int j;
	int n=10;
	for(i=0;i<10;i++){
		for(j=0;j<n-i-1;j++){
			printf(" ");
		}
		for(j=0;j<=2*i+1;j++){
			if(j==0||j==2*i+1){
				printf("*");
			}
			else{
				printf(" ");
			}
		}
		printf("\n");
		
		
	}
	int z=n;
	for(i=0;i<10;i++){
		for(j=0;j<i;j++){
			printf(" ");
			
		}
		for(j=0;j<=2*z-1;j++){
			if(j==0||j==2*z-1){
				printf("*");
			}
			else{
				printf(" ");
			}
			
		}
		printf("\n");
		z--;
	}
}
