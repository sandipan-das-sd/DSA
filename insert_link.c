#include <stdio.h>
#include <stdlib.h>

// Define the node structure
typedef struct node {
    int data;
    struct node* link;
} node;

node* head = NULL; // Initialize the head pointer to NULL

// Function to insert a new node at the beginning of the linked list
void insert_first(int x) {
    // Create a new node
    node* temp = (node*)malloc(sizeof(node));

    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Set the data and link for the new node
    temp->data = x;
    temp->link = head;

    // Update the head to point to the new node
    head = temp;
}

int main() {
    int x;
    char choice;

    do {
        printf("Enter the value to insert: ");
        scanf("%d", &x);
        insert_first(x);

        printf("Do you want to insert another value? (y/n): ");
        scanf(" %c", &choice); // Note the space before %c to consume any previous newline character

    } while (choice == 'y' || choice == 'Y');

    // Print the elements of the linked list
    node* current = head;
    printf("Linked List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->link;
    }
    
    // Free allocated memory for nodes
    current = head;
    while (current != NULL) {
        node* temp = current;
        current = current->link;
        free(temp);
    }

    return 0;
}

