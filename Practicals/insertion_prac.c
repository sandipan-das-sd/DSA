#include <stdio.h>
#include <stdlib.h>
void insertion_sort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = key - 1;
        while (key < arr[j] && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void swap(int *a, int *b)
{
    int *temp = *a;
    *a = *b;
    *b = *temp;
}
void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int key = i;
        for (int j = i + 1; j < n; j++)

        {
            if (arr[j] < arr[key])
            {
                key = j;
            }
        }
        swap(&arr[key], &arr[i]);
    }
}
void bubblesort(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void concure(int arr[], int start, int end, int mild)
{
    int size = end - start + 1;
    int *merged = (int *)malloc(size * sizeof(int *));
    if (merged == NULL)
    {
        printf("Memory Allocation failed\n");
        exit(EXIT_FAILURE);
    }
    int idx1 = start;
    int idx2 = mild + 1;
    int x=0;
    while(idx1<=mild &&idx2<=end)
    {
        if (arr[idx1]<=arr[idx2])
        {
            merged[x]=arr[idx1];
            idx1++;
            
        }
        else
        {
             merged[x] = arr[idx2];
            idx2++;
        }
       x++;

        
    }
     while (idx1 <= mild) {
        merged[x] = arr[idx1];
        idx1++;
        x++;
    }

    while (idx2 <= end) {
        merged[x] = arr[idx2];
        idx2++;
        x++;
    }
}
int main()
{
}