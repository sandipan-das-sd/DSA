#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;

}
int partition(int arr[],int lb,int ub)
{
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    while (start<end)
    {
        /* code */
       while (arr[start]<pivot)

       {
        /* code */
        start++;
       }
       while (arr[end]>pivot)
       {
        /* code */
        end--;
       }
       if (start<end)
       {
        /* code */
        swap(&arr[start],&arr[end]);
       }
       
    swap(&arr[lb], &arr[end]);
    return end;
       
    }
    

}    

int main()
{

}