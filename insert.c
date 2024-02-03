#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *link;
} node;

node *head = NULL;

void insert_first(int x) 
{
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

void insert_last(int x) 
{
    node *new_node = (node *)malloc(sizeof(node));
    if (new_node == NULL) 
	{
        printf("Memory allocation failed!!!");
        return;
    }
    new_node->data = x;
    new_node->link = NULL;

    if (head == NULL) 
	{
        // If the list is empty, set the new node as the head
        head = new_node;
    } 
	else 
	{
        // Traverse to the last node and add the new node at the end
        node *current = head;
        while (current->link != NULL) {
            current = current->link;
        }
        current->link = new_node;
    }
}

int main() 
{
    char ch;
    do 
	{
        int x;
        printf("Enter the element to insert: ");
        scanf("%d", &x);
        insert_last(x); // Call the insert_last function to insert at the last position
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &ch); // Note the space before %c to consume any previous newline character
    } while (ch == 'y' || ch == 'Y');

    printf("Linked list is:\n");
    // Printing the list
    node *new_node = head;
    while (new_node != NULL) 
	{
        printf("%d ", new_node->data);
        new_node = new_node->link;
    }
}

