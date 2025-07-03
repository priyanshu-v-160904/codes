#include<stdio.h>
#define pi 3.14
#define area(r) (r*r)*pi
#define sum(x,y) x+y




int main(){


	int r=5;
	float a=area(r);
	printf("%f",a);
	int x,b;
	x=1;
	b=5;
	int s=sum(x,b);
	printf("\n%d",s);


	
	printf("\nEOP\n");
	
	return 0;
	
	
	
}

