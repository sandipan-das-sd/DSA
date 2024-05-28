//#include<stdio.h>
//int main()
//{
//	printf("My name is Sandipan Das")
//	return 0;
//}
//#include <stdio.h>
//
//int main() {
//    int number;

    // Input from the user
//    printf("Enter a number: ");
//    scanf("%d", &number);
//
//    // Displaying the memory address of the number
//    printf("Memory address of the number %d is: %p\n", number, (void *)&number);
//
//    return 0;
//}
#include <stdio.h>

int main() {
    // Value declaration
    float a;
    float b;
    float c;
    
    // Value assignment
  	printf("Enter your first number:-");
  	scanf("%f",&a);
  	printf("Enter your Second number:-");
  	scanf("%f",&b);
  	
    
    // Operation
    c = a + b;
    
    // Print the result
    printf(" %f", c);
    
    return 0;
}

