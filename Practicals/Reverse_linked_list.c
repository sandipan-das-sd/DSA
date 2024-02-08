#include <stdio.h>
#include <stdlib.h>

/* Link list node */
struct Node {
    int data;
    struct Node* next;
};

/* Function to reverse the linked list */
static void reverse(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head = prev;
}

/* Function to push a node at the end */
void append(struct Node** head, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = NULL;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    // Traverse the list to find the last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Append the new element after the last node
    temp->next = new_node;
}

/* Function to print linked list */
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

/* Driver code */
int main() {
    struct Node* head = NULL;
    int num_elements, data;

    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    printf("Enter the elements:\n");
    for (int i = 0; i < num_elements; ++i) {
        scanf("%d", &data);
        append(&head, data); // Append elements to the end
    }

    printf("Given linked list\n");
    printList(head);
    reverse(&head);
    printf("\nReversed linked list\n");
    printList(head);

    return 0;
}
