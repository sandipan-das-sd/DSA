//Queue Operations using Array
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int queue[SIZE], front=-1, rear=-1;
void insert();
int del();
void display();
int main()
{
	int temp, option;
	do
	{
		printf("\n**QUEUE MENU**");
		printf("\n 1. INSERT");
		printf("\n 2. DELETE");
		printf("\n 3. DISPLAY");
		printf("\n 4. EXIT");
		printf("\n Enter your choice: ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
					insert();
					break;
			case 2:
					temp=del();
					if(temp!=-1)
						printf("\nThe deleted element is %d ",temp);
					break;
			case 3:
					display();
					break;
		}
	}while(option!=4);
	return 0;
}
void insert()
{
	int value;
	printf("\n Enter an element to insert: ");
	scanf("%d",&value);
	if(rear==SIZE-1)
		printf("\nQUEUE OVERFLOW");
	else if(front==-1 && rear==-1)
		front=rear=0;
	else
		rear=rear+1;
	queue[rear]=value;
}
int del()
{
	int temp;
	if(front==-1 || front>rear)
	{
		printf("\n QUEUE UNDERFLOW");
		return -1;
	}
	else
	{
		temp=queue[front];
		front=front+1;
		if(front>rear) //queue empty or (front==rear+1)
			front=rear=-1;
		return temp;
	}
}

void display()
{
	int i;
	if(front==-1 || front>rear)
	{
		printf("\n QUEUE IS EMPTY");
	}
	else
	{
		printf("\nQUEUE IS: \n");
		for(i=front;i<=rear;i++)
		{
			printf("%d\t", queue[i]);
		}
	}
	
}
