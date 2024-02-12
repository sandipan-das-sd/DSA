#include <stdio.h>
#define N 20

void countArray(int arr[], int n) {
    int count[N] = {0}; // Array to store the count of elements
    int k = 0; // Variable to hold the maximum element in the array

    // Finding the maximum element in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] > k) {
            k = arr[i];
        }
    }

    // Counting the total number of elements in the array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++; // Increment the count for the current element
    }

    // Calculating the cumulative count of elements up to each index
    for (int i = 1; i <= k; i++) {
        count[i] = count[i] + count[i - 1];
    }

    // Creating a temporary array to store the sorted array
    int b[N];

    // Sorting the array using counting sort
    for (int i = n - 1; i >= 0; i--) {
        b[count[arr[i]] - 1] = arr[i]; // Placing the element at its correct position
        count[arr[i]]--; // Decreasing the count of the element after placing it
    } 

    printf("The Sorted elements in the array are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]); // Print each element of the sorted array
    }
    printf("\n");
}

void printArray(int arr[], int n) {
    printf("Enter how many elements you want to insert in the array: ");
    scanf("%d", &n); // Accept the number of elements from the user
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Accept each element of the array from the user
    }
    printf("The elements in the array are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Print each element of the array
    }
    printf("\n");

    countArray(arr, n); // Call the function to perform counting sort
}

int main() {
    int n;
    int arr[N];
    printArray(arr, n); // Call the function to input and print array elements
    return 0;
}
