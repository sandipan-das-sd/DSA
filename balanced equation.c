#include<stdio.h>
#include<string.h>
#define MAX 10
int stack[MAX], top=-1;
void push(char);
char pop();
int main()
{
	char exp[MAX],temp,icount=0,dcount=0;
	int i, flag=1;
	printf("Enter an expression: ");// (({}))
	gets(exp);
	for(i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
		{
			push(exp[i]);
			icount++;
		}
		if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
			if(top==-1) //stack empty
				flag=0; 
			else
			{
				temp=pop();
				dcount++;
				if(exp[i]==')' && (temp=='{' || temp=='['))
					flag=0;
				if(exp[i]=='}' && (temp=='(' || temp=='['))
					flag=0;
				if(exp[i]==']' && (temp=='(' || temp=='{'))
					flag=0;
			}
	}
	if(top>0)
		flag=0;
	if(flag==1 && (icount==dcount))
		printf("\nBalanced Expression\n");
	else
		printf("\nUnbalanced Expression\n");
}

void push(char c)
{
	if(top==(MAX-1))
		printf("\nStack Overflow\n");
	else
		{
			top=top+1;
			stack[top]=c;
		}
}
char pop()
{
	if(top==-1)
		printf("\nStack Underflow\n");
	else
		return (stack[top--]);
}
