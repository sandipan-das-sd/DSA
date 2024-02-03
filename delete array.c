//Write a program to delete an element from the array
#include<stdio.h>
void read_array(int [], int);
void delete_array(int [], int, int); //array, size, position
int main()
{
	int a[30],n, pos;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	printf("In the main address of a is %x\n",a);
	read_array(a,n);
	printf("Enter the position in which you want to delete: ");
	scanf("%d",&pos);
	delete_array(a,n,pos);
	return 0;
}
void read_array(int p[30], int n)
{
	int i;
	printf("Enter the numbers in to the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	printf("In the read_array address of p is %x\n",p);
}
void delete_array(int x[30], int n, int pos)
{
	int i;
	for(i=pos;i<n-1;i++)
		x[i]=x[i+1];
	n=n-1;
	printf("The array after deleting will be\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",x[i]);
	}
	printf("In the delete_array address of x is %x\n",x);
}
