#include<stdio.h>
int main()
{
	//variable creation
	int marks;
	//value assign
	printf("Enter your marks:-\n");
	scanf("%d",&marks);
	//condition for vote
	//if else
	if(marks<=50){
		printf("Arts");
		
	}
	else if(marks<=60){
		printf("Commerce");
	}
	else if(marks<=90)
	{
		printf("Science");
	}
	else
	{
		printf("Sorry!! u are not elgible forany subject");
	}
	return 0;
}
