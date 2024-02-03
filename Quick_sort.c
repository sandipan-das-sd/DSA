#include<stdio.h>

// Function to partition the array and return the pivot index
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            // Swap elements
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap the pivot element to its correct position
    i++;
    int temp = arr[i];
    arr[i] = pivot;
    arr[high] = temp;

    return i; // Pivot index
}

// Function to perform Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Get the pivot index
        int pivotIdx = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quickSort(arr, low, pivotIdx - 1);
        quickSort(arr, pivotIdx + 1, high);
    }
}

int main() {
    int n;

    // Input array size
    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        printf("Enter the arr[%d] element: ", i);
        scanf("%d", &arr[i]);
    }

    // Display original array
    printf("The original array is: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("]\n");

    // Call Quick Sort function
    quickSort(arr, 0, n - 1);

    // Display sorted array
    printf("The sorted array is: [");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("]\n");

    return 0;
}

