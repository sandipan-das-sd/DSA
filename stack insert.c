//Stack Operations Using Array
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int stack[SIZE], top=-1; //global variables
void push(int[], int);
int pop(int[]); //return the top most element
int peek(int[]);//return the top most element
void display(int[]);
int main()
{
	int value, option,temp;
	do
	{
		printf("\n**STACK MENU**");
		printf("\n 1. PUSH");
		printf("\n 2. POP");
		printf("\n 3. PEEK");
		printf("\n 4. DISPLAY");
		printf("\n 5. EXIT");
		printf("\n Enter your choice: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
					printf("Enter an element to push: ");
					scanf("%d",&value);
					push(stack,value);
					break;
			case 2:
					temp=pop(stack); //returns the top most element of the stack
					if(temp!=-1)
						printf("\nThe deleted element is %d ",temp);
					break;
			case 3: 
					temp=peek(stack); //returns the top most element of the stack
					if(temp!=-1)
						printf("\nThe top most element is %d ",temp);
					break;
			case 4:
					display(stack);
					break;
		}
	}while(option!=5);
	return 0;
}
void push(int stack[], int value)
{
	if(top==SIZE-1)
		printf("\nSTACK OVERFLOW");
	else
	{
		top=top+1;
		stack[top]=value;
	}
}
int pop(int stack[])
{
	int temp;
	if(top==-1)
	{
		printf("\n STACK UNDERFLOW");
		return -1;
	}
	else
	{
		temp=stack[top]; //we store the top most element to temp variable
		top=top-1;
		return temp;
	}
}
int peek(int stack[])
{
	int temp;
	if(top==-1)
	{
		printf("\n No elements are present in the stack\n");
		return -1;
	}
	else
	{
		temp=stack[top]; //we store the top most element to temp variable
		return temp;
	}
}
void display(int stack[])
{
	int i;
	if(top==-1)
		printf("\n STACK IS EMPTY");
	else
	{
		printf("\nThe stack is: ");
		printf("\n");
		for(i=top;i>=0;i--)
			printf("%d\t",stack[i]);
	}
}
