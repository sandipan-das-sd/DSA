#include<stdio.h>
#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node *next;
}
struct node *head=NULL;
int main()
{
	while(1)
	{
		
	
	int choice,n;
	switch(choice)
	{
		
	
	printf("********Linkd list menu:-***********");
	printf("1.Insert_last\n2.Exit");
	printf("Enter your choice:-\n");
	scanf("%d",&choice);
	case 1:
	struct *ptr,*new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
    	printf("Memory allocation failed...!!\n");
	}
	else
	{
		*head=ptr
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
			ptr->next=new_node->next;
			
		}
	}
}
}
}
