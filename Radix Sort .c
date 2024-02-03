#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int size, int place) {
    int max = 10;
    int output[size + 1];
    int count[max + 1];
    int i,place;

    for (i = 0; i < max; ++i)
        count[i] = 0;

    for (i = 0; i < size; ++i)
        count[(arr[i] / place) % 10]++;

    for (i = 1; i < max; ++i)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; --i) {
        output[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (i = 0; i < size; ++i)
        arr[i] = output[i];
}

void radixSort(int arr[], int size) {
    int isNegative = 0;
    int min = 0;
    int max = 0;
    int i;

    for (i = 0; i < size; ++i) {
        if (arr[i] < 0) {
            isNegative = 1;
            break;
        }
    }

    if (isNegative) {
        min = arr[0];
        for (i = 1; i < size; ++i) {
            if (arr[i] < min)
                min = arr[i];
        }

        for (i = 0; i < size; ++i)
            arr[i] -= min;
    }

    max = arr[0];
    for (i = 1; i < size; ++i) {
        if (arr[i] > max)
            max = arr[i];
    }

    for (place = 1; max / place > 0; place *= 10)
        countingSort(arr, size, place);

    for (i = 0; i < size; ++i)
        arr[i] += min;
}

int main() {
    int arr[] = {170, 45, 75, -90, -802, 24, 2, 66};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;

    radixSort(arr, size);

    printf("Sorted array: ");
    for (i = 0; i < size; ++i)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

