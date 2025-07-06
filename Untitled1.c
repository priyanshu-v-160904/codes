//write a program to swap the value of two variables using pointers in a function
//write a program to read the details of 5 students using array of structures the details are name, rno ,and final marks display the student with highest marks
// write a program to find the sum of the elements of the array using pointers
#include<stdio.h>
void swap(int *,int *);
int main(){
	
	printf("\nEOP\n");
	return 0;
}
void swap(int *x,int *y){
	int t;
	t=*x;
	*(x)=*(y);
}
