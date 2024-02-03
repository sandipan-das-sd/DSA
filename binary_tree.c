#include <stdio.h>
#include <stdlib.h>

// Structure definition for a binary tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node with user input for data
struct node *createNode() {
    int data;
    printf("Enter data for the node: ");
    scanf("%d", &data);

    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        // Handle memory allocation error
        printf("Memory allocation failed!");
        return NULL;
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int main() {
    // Constructing the root node and two child nodes using user input
    struct node *n = createNode();
    struct node *n1 = createNode();
    struct node *n2 = createNode();
    
    // Linking the root node with the child nodes
    n->left = n1;
    n->right = n2;

    // Displaying the nodes (just the memory addresses)
    printf("Root Node: %d\n", n->data);
    printf("Left Child Node: %d\n", n->left->data);
    printf("Right Child Node: %d\n", n->right->data);

    // Don't forget to free the allocated memory for nodes when done
    free(n);
    free(n1);
    free(n2);

    return 0;
}

