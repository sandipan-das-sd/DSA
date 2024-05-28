#include <stdio.h>
//merge sort

// Function to divide the array
int i;
void divide(int arr[], int si, int ei);

// Function to conquer and merge the divided arrays
void conquer(int arr[], int si, int mild, int ei);

int main() {
    int a[100];
    int n, i;

    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++) {
        printf("Enter the a[%d]th element: ", i);
        scanf("%d", &a[i]);
    }

    printf("The original array is: [");
    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
        // Print a comma after each element except the last one
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("]\n");

    // Call the divide function to start the merge sort
    divide(a, 0, n - 1);

    // Print the sorted array
    printf("The sorted array is: [");
    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
        // Print a comma after each element except the last one
        if (i < n - 1) {
            printf(",");
        }
    }
    printf("]\n");

    return 0;
}

void divide(int arr[], int si, int ei) {
    int mild;

    if (si >= ei) {
        return;
    }

    mild = (si + ei) / 2;

    // Divide the array by calling the divide function for the 1st half of the array
    divide(arr, si, mild);
    // Divide the array by calling the divide function for the 2nd half of the array
    divide(arr, mild + 1, ei);

    // Call the conquer function to merge the divided arrays
    conquer(arr, si, mild, ei);
}

void conquer(int arr[], int si, int mild, int ei) {
    int merged[ei - si + 1];
    int idx1 = si;
    int idx2 = mild + 1;
    int x = 0;

    // Compare elements of the divided arrays and merge
    while (idx1 <= mild && idx2 <= ei) {
        if (arr[idx1] <= arr[idx2]) {
            merged[x] = arr[idx1];
            x++;
            idx1++;
        } else {
            merged[x] = arr[idx2];
            x++;
            idx2++;
        }
    }

    // Check for any remaining elements in the 1st part of the array
    while (idx1 <= mild) {
        merged[x] = arr[idx1];
        x++;
        idx1++;
    }

    // Check for any remaining elements in the 2nd part of the array
    while (idx2 <= ei) {
        merged[x] = arr[idx2];
        x++;
        idx2++;
    }

    // Copy the merged array back to the original array
    for ( i = 0; i < x; i++) {
        arr[si + i] = merged[i];
    }
}

#in python it will be



# Function to divide the array
def divide(arr, si, ei):
    if si >= ei:
        return

    mild = (si + ei) // 2

    # Divide the array by calling the divide function for the 1st half of the array
    divide(arr, si, mild)
    # Divide the array by calling the divide function for the 2nd half of the array
    divide(arr, mild + 1, ei)

    # Call the conquer function to merge the divided arrays
    conquer(arr, si, mild, ei)

# Function to conquer and merge the divided arrays
def conquer(arr, si, mild, ei):
    merged = [0] * (ei - si + 1)
    idx1 = si
    idx2 = mild + 1
    x = 0

    # Compare elements of the divided arrays and merge
    while idx1 <= mild and idx2 <= ei:
        if arr[idx1] <= arr[idx2]:
            merged[x] = arr[idx1]
            x += 1
            idx1 += 1
        else:
            merged[x] = arr[idx2]
            x += 1
            idx2 += 1

    # Check for any remaining elements in the 1st part of the array
    while idx1 <= mild:
        merged[x] = arr[idx1]
        x += 1
        idx1 += 1

    # Check for any remaining elements in the 2nd part of the array
    while idx2 <= ei:
        merged[x] = arr[idx2]
        x += 1
        idx2 += 1

    # Copy the merged array back to the original array
    for i in range(x):
        arr[si + i] = merged[i]

# Main function
if __name__ == "__main__":
    a = []

    # Input size of the array
    n = int(input("Enter the size of the array: "))

    # Input elements of the array
    print("Enter the elements of the array:")
    for i in range(n):
        a.append(int(input("Enter the a[{}]th element: ".format(i))))

    print("The original array is:", a)

    # Call the divide function to start the merge sort
    divide(a, 0, n - 1)

    # Print the sorted array
    print("The sorted array is:", a)

