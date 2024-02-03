#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct Stack {
    int items[SIZE];
    int top;
};

typedef struct Stack Stack;

void push(Stack*, int);
int pop(Stack*);
int peek(Stack*);
void display(Stack*);

int main() {
    Stack stack;
    stack.top = -1;
    int value, option, temp;
    
    do {
        printf("\n**STACK MENU**");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. EXIT");
        printf("\n Enter your choice: ");
        scanf("%d", &option);
        
        switch (option) {
            case 1:
                printf("Enter an element to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                temp = pop(&stack);
                if (temp != -1)
                    printf("\nThe deleted element is %d ", temp);
                break;
            case 3:
                temp = peek(&stack);
                if (temp != -1)
                    printf("\nThe top most element is %d ", temp);
                break;
            case 4:
                display(&stack);
                break;
        }
    } while (option != 5);
    
    return 0;
}

void push(Stack* stack, int value) {
    if (stack->top == SIZE - 1)
        printf("\nSTACK OVERFLOW");
    else {
        stack->top++;
        stack->items[stack->top] = value;
    }
}

int pop(Stack* stack) {
    int temp;
    if (stack->top == -1) {
        printf("\n STACK UNDERFLOW");
        return -1;
    } else {
        temp = stack->items[stack->top];
        stack->top--;
        return temp;
    }
}

int peek(Stack* stack) {
    int temp;
    if (stack->top == -1) {
        printf("\n No elements are present in the stack\n");
        return -1;
    } else {
        temp = stack->items[stack->top];
        return temp;
    }
}

void display(Stack* stack) {
    int i;
    if (stack->top == -1)
        printf("\n STACK IS EMPTY");
    else {
        printf("\nThe stack is: ");
        printf("\n");
        for (i = stack->top; i >= 0; i--)
            printf("%d\t", stack->items[i]);
    }
}

