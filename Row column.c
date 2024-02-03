//Write a program in C to input a 2D array and represent it in Row and Column Major order/
#include<stdio.h>
#define ROW 3
#define COL 3
int main()
{
	int arr[ROW][COL],i,j;
	printf("Enter the elements in the 2D array\n");
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\nThe 2D array in ROW MAJOR order is\n");
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	printf("\nThe 2D array in COLUMN MAJOR order is\n");
	for(i=0;i<ROW;i++)
	{
		for(j=0;j<COL;j++)
		{
			printf("%d ",arr[j][i]);
		}
		printf("\n");
	}
	return 0;
}
