//Infix to Postfix Converstion Using Stack
#include<stdio.h>
#include<stdlib.h> //for exit(1)
#include<string.h> //for strcat()
#include<ctype.h>//for isdigit() and isalpha()
#define SIZE 100
char stack[SIZE];
int top=-1;
void push(char item) //Algorithm of PUSH
{
	if(top==SIZE-1)
		printf("\nStack Overflow\n");
	else
	{
		top=top+1;
		stack[top]=item;
	}
}
char pop() // Algorithm of pop
{
	char item;
	if(top==-1)
	{
		printf("\nStack Underflow\n");
		exit(1);
	}
	else
	{
		item=stack[top];
		top=top-1;
		return item;
	}
}
//check if a character is operator or not
int is_operator(char symbol)
{
	if(symbol=='^'||symbol=='*'||symbol=='/'||symbol=='+'||symbol=='-')
		return 1; //True and it is a operator
	else
		return 0; //False and it is not a operator
}
int priority(char symbol) //Set the priority
{
	if(symbol=='^')
		return 3; //High Priority
	else if(symbol=='*'||symbol=='/')
		return 2;
	else if(symbol=='+'||symbol=='-')
		return 1;
	else
		return 0;
}
void infix_to_postfix(char infix_expression[], char postfix_expression[])
{
	int i,j;
	char item;
	char x;
	push('('); //add ( at the start of the expression
	strcat(infix_expression,")"); //add ) at the end of the expression
	i=0;
	j=0;
	item=infix_expression[i]; //item can be operand or digit or operator or ) or (
	while(item!='\0') //traverse the full expression
	{
		if(item=='(')
			push(item); //insert in to stack
		else if(isdigit(item)||isalpha(item)) //item is an operand
		{
			postfix_expression[j]=item; //directly insert in to postfix
			j++;
		}
		else if(is_operator(item)==1)
		{
			x=pop();
			while(is_operator(x)==1 && priority(x)>=priority(item))
			{
				postfix_expression[j]=x; //pop all higher priority operator
				j++;
				x=pop(); //add them in to postfix expression
			}
			push(x);
			push(item);
		}
		else if(item==')') //if current symbol is )
		{
			x=pop();
			while(x!='(') //pop and keep popping until ( is encountered
			{
				postfix_expression[j]=x;
				j++;
				x=pop();
			}
		}
		else
		{
			//if current symbol is neither operand nor ( nor ) nor operator
			printf("\nInvalid Expression\n");
			getchar();
			exit(1);
		}
		i++;
		item=infix_expression[i]; //go to the next symbol of infix expression
	}
	if(top>0)
	{
		printf("\nInvalid Expression\n");
		getchar();
		exit(1);
	}
	postfix_expression[j]='\0';
}
int main()
{
	char infix_expression[SIZE], postfix_expression[SIZE];
	printf("\nEnter an infix expression: \n");
	gets(infix_expression);
	infix_to_postfix(infix_expression,postfix_expression);
	printf("Postfix expression is: ");
	puts(postfix_expression);
	return 0;
}
