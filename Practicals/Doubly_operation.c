#include <stdio.h>
#include <stdlib.h>

// Doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node after a given element
void insertAfter(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    if (prevNode->next != NULL) {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
    newNode->prev = prevNode;
}

// Function to insert a node after a given position
void insertAfterPosition(struct Node** head, int position, int data) {
    if (position < 0) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 0) {
        insertAfter(*head, data);
        return;
    }
    struct Node* current = *head;
    for (int i = 0; current != NULL && i < position - 1; ++i) {
        current = current->next;
    }
    if (current == NULL) {
        printf("Position is out of range.\n");
        return;
    }
    insertAfter(current, data);
}

// Function to delete the first node
void deleteFirst(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
}

// Function to delete the last node
void deleteLast(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }
    free(temp);
}

// Function to count the number of nodes in the list
int countNodes(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        ++count;
        head = head->next;
    }
    return count;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Driver code
int main() {
    struct Node* head = NULL;
    int num_elements, data;

    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    printf("Enter the elements:\n");
    for (int i = 0; i < num_elements; ++i) {
        scanf("%d", &data);
        insertAfter(&head, data);
    }

    printf("List after insertions: ");
    printList(head);
    
    int pos;
    printf("Enter the position to insert: ");
    scanf("%d", &pos);
    printf("Enter the element to insert: ");
    scanf("%d", &data);
    insertAfterPosition(&head, pos, data);
    printf("List after insertion at position %d: ", pos);
    printList(head);
    
    printf("Number of nodes in the list: %d\n", countNodes(head));
    
    deleteFirst(&head);
    printf("List after deleting the first node: ");
    printList(head);
    
    deleteLast(&head);
    printf("List after deleting the last node: ");
    printList(head);
    
    return 0;
}
