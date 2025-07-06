//write a program to read the details of 5 students using array of structures the details are name, rno ,and final marks display the student with highest marks
#include<stdio.h>
#include<string.h>
struct stu{
	char name[20];
	int rno;
	float marks;
}s[5];

int main(){
	int i;
	for(i=0;i<5;i++){
		printf("details of student %d\n",i+1);
		printf("enter name\n");
		scanf(" %[^\n]",&s[i].name);
		
		printf("\nenter rno\n");
		scanf("%d",&s[i].rno);
		printf("\n enter marks\n");
		scanf("%f",&s[i].marks);
		
		
		
		
		
	}
	float t=s[0].marks;
	
	
	for(i=1;i<5;i++){
		
			if(t<=s[i].marks){
				t=s[i].marks;
			}
		
	}
	printf("\n%f\n",t);
	
	//print_student(t);
	for(i=0;i<5;i++){
		if(t==s[i].marks){
			printf("name is\n");
			puts(s[i].name);
			printf(" \marks is %f\n",s[i].marks);
			printf("\n rno is %d",s[i].rno);
			//break;
		}
	}
	
	return 0;
	
}
