#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

node *head = NULL;

void insert_first(int x) {
    node *temp = (node *)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Memory allocation failed!!!");
        return;
    } else {
        temp->data = x;
        temp->link = head;
        head = temp;
    }
}

int main() {
    char ch;
    do {
        int x;
        printf("Enter the element to insert: ");
        scanf("%d", &x);
        insert_first(x);
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &ch); // Note the space before %c to consume any previous newline character
    } while (ch == 'y' || ch == 'Y');

    printf("Linked list is:\n");
    // Printing the list
    node *new_node = head;
    while (new_node != NULL) {
        printf("%d ", new_node->data);
        new_node = new_node->link; // Fixed missing semicolon
    }

    /*// Free allocated memory for nodes
    new_node = head;
    while (new_node != NULL) {
        node *temp = new_node;
        new_node = new_node->link;
        free(temp);
    }*/

    return 0;
}

