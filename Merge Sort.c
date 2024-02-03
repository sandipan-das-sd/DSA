#include <stdio.h>

void Merge(int a[], int lb, int mild, int ub);
void MergeSort(int a[], int lb, int ub);

int main()
{
    int n, i, ele;
    
    // Get the size of the array
    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    // Declare an array of size n
    int a[n];

    // Get the total number of elements, make sure it is less than or equal to n
    printf("Enter the total number of elements (up to %d):\n", n);
    scanf("%d", &ele);

    if (ele > n) {
        printf("Error: Number of elements exceeds the array size.\n");
        return 1; // Exit the program with an error code
    }

    // Input array elements
    for (i = 0; i < ele; i++)
    {
        printf("Insert the value at position %d\n", i);
        scanf("%d", &a[i]);
    }

    // Display the unsorted array elements
    printf("The unsorted array elements are:\n");
    for (i = 0; i < ele; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Perform Merge Sort
    MergeSort(a, 0, ele - 1);

    // Display the sorted array
    printf("The sorted array using Merge sort:\n");
    for (i = 0; i < ele; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}

// Merge function to merge two halves of the array
void Merge(int a[], int lb, int mild, int ub)
{
    int i, j, k;
    int b[ub + 1]; // Temporary array to store merged result

    i = lb;        // Initial index of the first subarray
    j = mild + 1;  // Initial index of the second subarray
    k = lb;        // Initial index of the merged subarray

    while (i <= mild && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left subarray, if any
    while (i <= mild)
    {
        b[k] = a[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right subarray, if any
    while (j <= ub)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    // Copy the merged elements back to the original array
    for (k = lb; k <= ub; k++)
    {
        a[k] = b[k];
    }
}

// MergeSort function to sort the array using Merge Sort
void MergeSort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int mild = (lb + ub) / 2; // Calculate the middle index

        // Recursively sort the first and second halves
        MergeSort(a, lb, mild);
        MergeSort(a, mild + 1, ub);

        // Merge the sorted halves
        Merge(a, lb, mild, ub);
    }
}

