#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 100

// Define stack structure
struct Stack {
    int top;
    int items[MAX_SIZE];
};

// Stack operations
void push(struct Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = value;
}

int pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

// Function to evaluate postfix expression
int evaluatePostfix(char* exp) {
    struct Stack stack;
    stack.top = -1;

    for (int i = 0; exp[i] != '\0'; ++i) {
        if (isdigit(exp[i])) {
            push(&stack, exp[i] - '0'); // Convert char to int
        } else {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);

            switch (exp[i]) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Division by zero\n");
                        exit(1);
                    }
                    push(&stack, operand1 / operand2);
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
        }
    }
    return pop(&stack);
}

int main() {
    char exp[MAX_SIZE];
    printf("Enter a postfix expression: ");
    fgets(exp, MAX_SIZE, stdin);

    int result = evaluatePostfix(exp);
    printf("Result: %d\n", result);

    return 0;
}
