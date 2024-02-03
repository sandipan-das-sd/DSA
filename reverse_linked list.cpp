#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to reverse the linked list
void reverseLinkedList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next; // Store the next node
        current->next = prev; // Change the direction of the pointer
        prev = current;
        current = next;
    }

    *head = prev; // Update the head to point to the new first node
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Creating a linked list with predetermined values
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 2);
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 4);

    printf("Original Linked List: ");
    printLinkedList(head);

    reverseLinkedList(&head);

    printf("Reversed Linked List: ");
    printLinkedList(head);

    return 0;
}

