#include<stdio.h>

#define n 10

int bst(int arr[], int size, int ele) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == ele) {
            return mid;
        }
        else if (arr[mid] < ele) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return -1; // Element not found
}

int main() {
    int arr[n];
    int size;
    int i;
  
    printf("Enter how many numbers you want to enter in the array: ");
    scanf("%d", &size);
    
    printf("Enter the numbers:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("The array is:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int ele;
    printf("Enter the element you want to find: ");
    scanf("%d", &ele);

    int result = bst(arr, size, ele);
    if (result != -1) {
        printf("%d found at index %d in the array.\n", ele, result);
    } else {
        printf("%d not found in the array.\n", ele);
    }

    return 0;
}
