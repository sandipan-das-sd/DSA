#include <stdio.h>

int add(int, int); // Function prototype declaration

int main() {
    /* Adding 2 numbers */
    int a, b;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    int sum = add(a, b); // Function calling with arguments
    printf("The summation is: %d\n", sum);
    return 0;
}

int add(int a, int b) {
    int c;
    c = a + b;
    return c; // Return the sum
}
