#include <stdio.h>
#include <math.h>

int main() {
    double num;
    
    printf("Enter your Original number: ");
    scanf("%lf", &num);

    double roundedUp = ceil(num);

    printf("Rounded up: %lf\n", roundedUp);

    return 0;
}

