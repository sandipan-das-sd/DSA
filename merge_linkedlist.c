#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int data;
    struct node* next;
};

// Function to perform bubble sort on a linked list
void bubbleSort(struct node* start);

// Function to swap data of two nodes
void swap(struct node* a, struct node* b);

// Function to merge two sorted linked lists
struct node* mergeSortedLists(struct node* list1, struct node* list2);

// Function to print the elements of a linked list
void printList(struct node* node);

int main() {
    int n, i;

    // Create the first linked list
    struct node* head1 = NULL; // Head node for the first linked list
    printf("Enter the total number of elements in the first node: ");
    scanf("%d", &n);

    // Create nodes for the first linked list
    struct node* temp1 = head1; // Temporary pointer for the first linked list
    for (i = 0; i < n; i++) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &(new_node->data));
        new_node->next = NULL;

        // Insert the new node into the first linked list
        if (head1 == NULL) {
            head1 = new_node;
            temp1 = head1;
        } else {
            temp1->next = new_node;
            temp1 = temp1->next;
        }
    }

    // Sort the first linked list using bubble sort algorithm
    bubbleSort(head1);

    // Print the sorted first linked list
    printf("Sorted List 1: ");
    printList(head1);

    // Create the second linked list
    struct node* head2 = NULL;
    printf("Enter the total number of elements in the second node: ");
    scanf("%d", &n);

    // Create nodes for the second linked list
    struct node* temp2 = head2; // Temporary pointer for the second linked list
    for (i = 0; i < n; i++) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &(new_node->data));
        new_node->next = NULL;

        // Insert the new node into the second linked list
        if (head2 == NULL) {
            head2 = new_node;
            temp2 = head2;
        } else {
            temp2->next = new_node;
            temp2 = temp2->next;
        }
    }

    // Sort the second linked list using bubble sort algorithm
    bubbleSort(head2);

    // Merge and sort the two linked lists
    struct node* mergedList = mergeSortedLists(head1, head2);

    // Print the final merged and sorted list
    printf("Merged and Sorted List: ");
    printList(mergedList);

    // Free allocated memory for the linked lists (not shown in this example).

    return 0;
}

// Bubble sort implementation for sorting the linked list
void bubbleSort(struct node* start) {
    int swapped;
    struct node* ptr1;
    struct node* lptr = NULL;

    // Checking for empty list
    if (start == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Function to swap data of two nodes
void swap(struct node* a, struct node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

// Function to merge two sorted linked lists
struct node* mergeSortedLists(struct node* list1, struct node* list2) {
    struct node* mergedList = NULL;
    struct node* temp = mergedList;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            struct node* new_node = (struct node*)malloc(sizeof(struct node));
            new_node->data = list1->data;
            new_node->next = NULL;
            if (mergedList == NULL) {
                mergedList = new_node;
                temp = mergedList;
            } else {
                temp->next = new_node;
                temp = temp->next;
            }
            list1 = list1->next;
        } else {
            struct node* new_node = (struct node*)malloc(sizeof(struct node));
            new_node->data = list2->data;
            new_node->next = NULL;
            if (mergedList == NULL) {
                mergedList = new_node;
                temp = mergedList;
            } else {
                temp->next = new_node;
                temp = temp->next;
            }
            list2 = list2->next;
        }
    }

    if (list1 != NULL) {
        temp->next = list1;
    }
    if (list2 != NULL) {
        temp->next = list2;
    }

    return mergedList;
}

// Function to print the elements of a linked list
void printList(struct node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

