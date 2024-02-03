#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb;
    int end = ub;

    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(&a[start], &a[end]);
        }
    }
    swap(&a[lb], &a[end]);
    return end;
}

void quickSort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(a, lb, ub);
        quickSort(a, lb, loc - 1);
        quickSort(a, loc + 1, ub);
    }
}

int main()
{
    int n, i, l, ele;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    int a[n];

    printf("Enter the total number of elements:\n");
    scanf("%d", &ele);

    for (i = 0; i < ele; i++)
    {
        printf("Insert the value at position %d\n", i);
        scanf("%d", &a[i]);
    }

    printf("The unsorted array elements are:\n");
    for (i = 0; i < ele; i++)
    {
        printf("%d ", a[i]);
    }
    
    quickSort(a, 0, ele - 1);

    printf("\nThe sorted array after quick sort is:\n");
    for (l = 0; l < ele; l++)
    {
        printf("%d ", a[l]);
    }

    return 0;
}

