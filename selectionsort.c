#include <stdio.h>
#define n 20

void selection_dec_asc_sort(int arr[], int size) {
    int i, j, temp, max_index;
    for (i = 0; i < size - 1; i++) {
        max_index = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = temp;
    }
}

void selection_asc_dec_sort(int arr[], int size) {
    int i, j, temp, min_index;
    for (i = 0; i < size - 1; i++) {
        min_index = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
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

    selection_dec_asc_sort(arr, size);
    printf("\nThe array after sorting {Descending to Ascending}:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    selection_asc_dec_sort(arr, size);
    printf("\nThe array after sorting {Ascending to Descending}:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
