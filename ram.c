#include<stdio.h>
int main()
{
	int i;
	func1(1);
	return 0;
}
void func1(int n)
{
 //Base Condition or Stop Condition	
		printf("%d\n ",n);
		func1(n+1); //Recursive Condition
}
/*void func1(int n)
{
	printf("%d ",n);
	func2(2);
}
void func2(int n)
{
	printf("%d ",n);
	func3(3);
}
void func3(int n)
{
	printf("%d ",n);
	func4(4);
}
void func4(int n)
{
	printf("%d ",n);
	func5(5);
}
void func5(int n)
{
	printf("%d ",n);
}*/
