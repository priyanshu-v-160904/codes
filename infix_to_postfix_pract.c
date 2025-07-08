#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
char stack[MAX_SIZE];
int top = -1;
int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == MAX_SIZE - 1;
}
void push(char op)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    stack[++top] = op;
}
char pop()
{
    if (isEmpty())
    {
        return -1; // Error handling
    }
    return stack[top--];
}
int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
void infixToPostfix(char infix[], char postfix[])
{
    int i, j;
    j = 0;
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (isOperand(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push('(');
        }
        else if (infix[i] == ')')
        {
            while (!isEmpty() && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            if (!isEmpty() && stack[top] != '(')
            {
                printf("Invalid Expression\n");
                exit(1);
            }
            else
            {
                pop(); // Remove '('
            }
        }
        else if (isOperator(infix[i]))
        {
            while (!isEmpty() && precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j++] = pop();
            }
            push(infix[i]);
        }
    }
    while (!isEmpty())
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}
int main()
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
