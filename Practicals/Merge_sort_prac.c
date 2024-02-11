#include<stdio.h>
#include<stdlib.h>

void conquer(int arr[], int start, int mild, int end) {
    int size = end - start + 1;
    int* merged = (int*)malloc(size * sizeof(int));

    if (merged == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    int idx1 = start;
    int idx2 = mild + 1;

    int x = 0;

    while (idx1 <= mild && idx2 <= end) {
        if (arr[idx1] <= arr[idx2]) {
            merged[x] = arr[idx1];
            idx1++;
        } else {
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

    for (int i = 0; i < x; i++) {
        arr[start + i] = merged[i];
    }

    free(merged);
}

void divide(int arr[], int start, int end) {
    if (start >= end) {
        return;
    } else {
        int mild = (start + end) / 2;
        divide(arr, start, mild);
        divide(arr, mild + 1, end);
        conquer(arr, start, mild, end);
    }
}

int main() {
    int i, n;

    printf("Enter the number of elements you want to insert:\n");
    scanf("%d", &n);
    
    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("The elements are:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    divide(arr, 0, n - 1);

    printf("The sorted array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("\n");

    return 0;
}
