#include<stdio.h>
#include<stdlib.h>
int step,j;
void selectionSort(int arr[],int n)
{
    for(step=0;step<n-1;step++)
    {
       int  min_idx=step;
       for(j=step+1;j<n;j++)
       {
        if(arr[j]<arr[min_idx])
        {
            min_idx=j;

        }
        int temp=arr[min_idx];
        arr[min_idx]=arr[step];
        arr[step]=temp;
       }
    }
}
void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
    }
}
int main()
{
    int arr[]={12,9,4,3,7};
    int n=sizeof(arr)/sizeof(arr[0]);
     selectionSort(arr,n);
    
    
    printf("Sorted array in Ascending Order:\n");
    printArray(arr, n);
}
