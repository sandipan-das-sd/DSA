#include<stdio.h>
int max1,min1;
int a[100];
void max_min(int i,int j)
{
    int max,min;
    if(i==j)
    {
        max=min=a[i];
    }
    if(i==j-1)
    {
        if(a[i]<a[j])
        {
            max=a[j];
            min=a[i];
        }
        else
        {
           max=a[i];
            min=a[j]; 
        }
    }
 int mild=(i+j)/2;
 max_min(i,mild);
 max_min(mild+1,j);
if(max<max1)
{
    max=max1;


}
if(min>min1)
{
    min=min1;
}

}
int main()
{
int i, num;
 printf ("\nEnter the total number of numbers : ");
 scanf ("%d",&num);
 printf ("Enter the numbers : \n");
 for (i=1;i<=num;i++)
  scanf ("%d",&a[i]);
}