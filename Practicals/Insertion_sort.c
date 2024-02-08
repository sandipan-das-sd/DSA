// // C program for insertion sort
// #include <math.h>
// #include <stdio.h>

// /* Function to sort an array 
// using insertion sort*/
// void insertionSort(int arr[], int n)
// {
// 	int i, key, j;
// 	for (i = 1; i < n; i++) 
// 	{
// 		key = arr[i];
// 		j = i - 1;

// 		/* Move elements of arr[0..i-1], 
// 		that are greater than key, 
// 		to one position ahead of 
// 		their current position */
// 		while (j >= 0 && arr[j] > key) 
// 		{
// 			arr[j + 1] = arr[j];
// 			j = j - 1;
// 		}
// 		arr[j + 1] = key;
// 	}
// }

// // A utility function to print 
// // an array of size n
// void printArray(int arr[], int n)
// {
// 	int i;
// 	for (i = 0; i < n; i++)
// 		printf("%d ", arr[i]);
// 	printf("\n");
// }

// // Driver code
// int main()
// {
// 	int arr[] = {12, 11, 13, 5, 6};
// 	int n = sizeof(arr) / sizeof(arr[0]);

// 	insertionSort(arr, n);
// 	printArray(arr, n);

// 	return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void InsertionSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] >= key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void Printarray(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]); // Added space after %d to separate elements
    }
    printf("\n"); // Added newline to separate output
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    InsertionSort(arr, n);
    Printarray(arr, n);
    return 0; // Added return statement
}
