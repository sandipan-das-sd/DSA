#include <stdio.h>
#define n 10

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Return the index if found
        }
    }
    return -1;  // Return -1 if not found
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

    int result = linear_search(arr, size, ele); // Pass ele instead of target
    if (result != -1) {
        printf("Element %d found at index %d.\n", ele, result); // Print ele instead of target
    } else {
        printf("Element %d not found in the array.\n", ele); // Print ele instead of target
    }

    return 0;
}
