#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    char data[MAX_SIZE];
    int top;
};

void initialize(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, char value) {
    if (isFull(s)) {
        printf("Stack overflow\n");
        exit(1);
    }
    s->data[++(s->top)] = value;
}

char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        exit(1);
    }
    return s->data[(s->top)--];
}

char peek(struct Stack *s) {
    if (isEmpty(s)) {
        return '\0'; // Return a sentinel value for an empty stack
    }
    return s->data[s->top];
}
int getPrecedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '^')
        return 3;
    return 0; // Return 0 for non-operators (operands)
}
void infixToPrefix(char *infix, char *prefix) {
    struct Stack operatorStack;
    initialize(&operatorStack);

    int infixLen = strlen(infix);
    int prefixIndex = 0;

    // Reverse the infix expression
    int i;
    for ( i = infixLen - 1; i >= 0; i--) {
        char ch = infix[i];

        if (ch == ' ')
            continue;

        if (ch >= 'a' && ch <= 'z') { // Operand
            prefix[prefixIndex++] = ch;
        } else if (ch == ')') {
            push(&operatorStack, ch);
        } else if (ch == '(') {
            while (!isEmpty(&operatorStack) && peek(&operatorStack) != ')') {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            pop(&operatorStack); // Pop the '(' from stack
        } else { // Operator
            while (!isEmpty(&operatorStack) && getPrecedence(ch) <= getPrecedence(peek(&operatorStack))) {
                prefix[prefixIndex++] = pop(&operatorStack);
            }
            push(&operatorStack, ch);
        }
    }

    // Pop remaining operators from the stack
    while (!isEmpty(&operatorStack)) {
        prefix[prefixIndex++] = pop(&operatorStack);
    }

    prefix[prefixIndex] = '\0'; // Null-terminate the prefix expression
}

int main() {
    char infix[MAX_SIZE];
    char prefix[MAX_SIZE];

    printf("Enter infix expression: ");
    gets(infix);

    infixToPrefix(infix, prefix);

    // Reverse the prefix expression to get the correct order
    strrev(prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}

