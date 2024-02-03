#include <stdio.h>

int main() {
    int a[50], i, j, n, l, r, mild, ele;
    
    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    printf("Enter the elements in the array:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("The array is:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    
    printf("\nEnter the element to be searched:\n");
    scanf("%d", &ele);

    // Initialize the search range indices
    l = 0;
    r = n - 1;

    while (l <= r) {
        mild = l + (r - l) / 2;

        if (a[mild] == ele) {
            printf("The element %d is present at index %d\n", ele, mild);
            break;
        } else if (ele < a[mild]) {
            r = mild - 1;
        } else {
            l = mild + 1;
        }
    }

    // If l > r, the element was not found
    if (l > r) {
        printf("The element %d is not present in the array\n", ele);
    }

    return 0;
}

