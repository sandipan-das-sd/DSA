//Write a program to insert an element in to the array
#include<stdio.h>
void read_array(int [], int); //array, size
void insert_array(int [], int, int, int); //array, size, position, value
int main()
{
	int a[30],n,value, pos;
	printf("Enter the size of the array: ");
	scanf("%d",&n);
	read_array(a,n); //call by address
	printf("Enter the position in which you want to insert a new value: ");
	scanf("%d",&pos);
	printf("Enter the new value: ");
	scanf("%d",&value);
	insert_array(a,n,pos,value);
	return 0;
}
void read_array(int a[10], int n)
{
	int i;
	printf("Enter the numbers in to the array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void insert_array(int a[10], int n, int pos, int value)
{
	int i;
	for(i=n-1;i>=pos;i--)
		a[i+1]=a[i];
	a[pos]=value;
	n=n+1;
	printf("The array after inserting will be\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
}
