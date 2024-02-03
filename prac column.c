#include<stdio.h>
#define ROW 3
#define COL 3

int main()
{
int arr[ROW][COL];
int i,j;
printf("Enter the array elemenets:-\n");
for(i=0;i<ROW;i++)
{
for(j=0;j<COL;j++)
{
	scanf("%d\n",&arr[i][j]);
}	
	
}
printf("The given array is:-\n");
    for(i=0;i<ROW;i++)
    {
	for(j=0;j<COL;j++)
	{
		printf("%d ",arr[i][j]);
	}
	
	
	printf("\n");
    }
printf("The ROW MAJOR array is:-\n");
for(i=0;i<ROW;i++)
{
	for(j=0;j<COL;j++)
	{
	printf("%d ",arr[j][i]);	
	}
}
printf("\n");
}
