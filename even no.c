/*printing even  number  up to 100 */
#include<stdio.h>
int main()
{
int n,i;
printf("Enter up to which number you waant to find even no:-\n");
scanf("%d",&n);
printf("The even no is:-\n");
for(i=0;i<=n;i++)
{
	
if(i%2==0)
{
	printf(" %d\n",i);
}	
}
	
}
