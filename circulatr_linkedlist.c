#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the beginning of the circular linked list
struct Node* insertAtBeginning(struct Node* last, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (last == NULL) {
        new_node->next = new_node;
        last = new_node;
    } else {
        new_node->next = last->next;
        last->next = new_node;
    }
    return last;
}
struct Node* insertAtEnd(struct Node* last, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    if (last == NULL) {
        // If the list is empty, make the new node as the last node and point to itself
        new_node->next = new_node;
        last = new_node;
    } else {
        // Insert the new node after the last node and update pointers
        new_node->next = last->next;
        last->next = new_node;
        last = new_node; // Update the last pointer to the new node
    }
    return last;
}
struct Node* insertAtPosition(struct Node* last, int data, int position) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;

    if (last == NULL) {
        // If the list is empty, make the new node as the last node and point to itself
        new_node->next = new_node;
        last = new_node;
    } else {
        struct Node* temp = last->next;
        int i = 1;
        // Traverse the list to the specified position or end of the list
        while (i < position - 1 && temp->next != last->next) {
            temp = temp->next;
            i++;
        }
        // Insert the new node after the temp node and update pointers
        new_node->next = temp->next;
        temp->next = new_node;
        // If the position is the last node, update last pointer to the new node
        if (temp == last) {
            last = new_node;
        }
    }
    return last;
}
// Function to traverse and print the circular linked list
void traverseCircularLinkedList(struct Node* last) {
    if (last == NULL) {
        printf("Circular linked list is empty.\n");
        return;
    }

    struct Node* temp = last->next; // Start from the first node
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next); // Continue until we reach the first node again
    printf("\n");
}

int main() {
    struct Node* last = NULL; // Initialize the last pointer to NULL for an empty list

    // Insert nodes at the beginning of the circular linked list
    last = insertAtBeginning(last, 1);
    last = insertAtBeginning(last, 2);
    last = insertAtBeginning(last, 3);
    last = insertAtBeginning(last, 4);

    // Traverse and print the circular linked list
    printf("Circular Linked List: ");
    traverseCircularLinkedList(last);

    return 0;
}

