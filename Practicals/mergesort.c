#include<stdio.h>
#include<stdlib.h>

void conquer(int arr[], int start, int mid, int end) {
    int size = end - start + 1;
    int idx1 = start;
    int idx2 = mid + 1;
    int x = 0;
    int* merged = (int*)malloc(size * sizeof(int));

    while (idx1 <= mid && idx2 <= end) {
        if (arr[idx1] <= arr[idx2]) {
            merged[x] = arr[idx1];
            idx1++;
        } else {
            merged[x] = arr[idx2];
            idx2++;
        }
        x++;
    }

    while (idx1 <= mid) {
        merged[x] = arr[idx1];
        idx1++;
        x++;
    }

    while (idx2 <= end) {
        merged[x] = arr[idx2];
        idx2++;
        x++;
    }

    for (int i = 0; i < size; i++) {
        arr[start + i] = merged[i];
    }
    free(merged);
}

void divide(int arr[], int start, int end) {
    if (start >= end) {
        return;
    } else {
        int mid = (start + end) / 2;
        divide(arr, start, mid);
        divide(arr, mid + 1, end);
        conquer(arr, start, mid, end);
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
