#include<stdio.h>
#include<stdlib.h>

#define N 10

int stack[N];
int top = -1;

void push(int x) {
    if (top == N - 1) {
        printf("Stack overflow!\n");
    } else {
        top++;
        stack[top] = x;
    }
}

int pop() {
    if (top == -1) {
        printf("Stack underflow! No element to delete\n");
        return -1;
    } else {
        int temp = stack[top];
        top--;
        return temp;
    }
}

int peek() {
    if (top == -1) {
        printf("Stack underflow! No element to delete\n");
        return -1;
    } else {
        return stack[top];
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } else {
        printf("The elements are: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int option, value, temp;
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
                push(value);
                break;
            case 2:
                temp = pop();
                if (temp != -1) {
                    printf("The popped element is: %d\n", temp);
                }
                break;
            case 3:
                temp = peek();
                if (temp != -1) {
                    printf("The peek element is: %d\n", temp);
                }
                break;
            case 4:
                display();
                break;
        }
    } while (option != 5);
    return 0;
}
