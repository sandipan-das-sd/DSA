#include <stdio.h>
#define n 20

void insertion_dec_asc_sort(int arr[], int size) {
    int i, j, temp, key;
    //as we have assign key to the second element of the arary for thgis we need to start the for  loop from 1 
    for (i = 1; i < size ; i++) {
       key=arr[i];
       j=i-1;
        while (key<arr[j]&& j>=0)
        {
           arr[j+1]=arr[j];
           j--;
        }
        arr[j+1]=key;
        
       
    }
}

void insertion_asc_dec_sort(int arr[], int size) {
    int i, j, temp, key;
    for (i = 1; i < size ; i++) {
       key=arr[i];
       j=i-1;
        while (key>arr[j]&& j>=0)
        {
           arr[j+1]=arr[j];
           j--;
        }
        arr[j+1]=key;
        
       
    }
}

int main() {
    int arr[n], size, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);
   
    for (i = 0; i < size; i++) {
        printf("Enter the %d-th element of the array: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("The array before sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    insertion_dec_asc_sort(arr, size);
    printf("\nThe array after sorting {Descending to Ascending}:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    insertion_asc_dec_sort(arr, size);
    printf("\nThe array after sorting {Ascending to Descending}:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
