#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>
#define MAX 20  
  
char stk[20];  
int top = -1;  
int isEmpty()  
{  
    return top == -1;  
}  
int isFull()  
{  
    return top == MAX - 1;  
}  

char pop()  
{  
    if(isEmpty())  
        return -1;  
  
    char ch = stk[top];  
    top--;  
    return(ch);  
}  
  
void push(char oper)  
{  
    if(isFull())  
        printf("Stack Full!!!!");  
     
    else{  
        top++;  
        stk[top] = oper;  
    }  
}  
  
int isop(char symbol)   
{   
    if(symbol=='+'||symbol=='-'||symbol=='*'||symbol=='/')
    {
        return 1;
    }
    return 0;
}   
  
int evaluate(char *exp)
{
    int i=0;
    char symbol=exp[i];
    int operand1,operand2,result;
    while (symbol!='\0')
    {
        if(symbol>='0'&& symbol<='9')
        {
            int num=symbol-'0';
            push(num);
        }
        else if (isop(symbol))
        {
            operand2=pop();
            operand1=pop();
            switch(symbol)
            {
                case '+':
                result=operand1+operand2;
                break;
                case '-':
                result=operand1-operand2;
                break;
                case '*':
                result=operand1*operand2;
                break;
                case '/':
                result=operand1/operand2;
                break;
            }
            push(result);
        }
        i++;
        symbol=exp[i];
    }
    result=pop();
    return result;
}
  
int main()  
{  
	char exp[]="56 7+*8-"; 
	int result=evaluate(exp);
	printf("result=%d\n",result);
    return 0;   
}   

