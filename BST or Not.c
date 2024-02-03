#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Structure definition for a binary tree node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a new node with user input for data
struct node *createNode(int data) {
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

// is BST function
int isBstUtil(struct node* root, int min, int max) {
    if (root == NULL) {
        return 1;
    }

    if (root->data < min || root->data > max) {
        return 0;
    }

    return isBstUtil(root->left, min, root->data - 1) && isBstUtil(root->right, root->data + 1, max);
}

int isBst(struct node* root) {
    return isBstUtil(root, INT_MIN, INT_MAX);
}

int main() {
    int no_nodes, i, data;
    struct node *root = NULL;
    
    // Asking user for the number of nodes
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &no_nodes);

    // Creating the binary tree based on user input
    for (i = 0; i < no_nodes; ++i) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        if (i == 0) {
            root = createNode(data); // First node is the root
        } else {
            // Inserting subsequent nodes into the binary tree
            struct node *current = root;
            while (1) {
                if (data < current->data) {
                    if (current->left == NULL) {
                        current->left = createNode(data);
                        break;
                    } else {
                        current = current->left;
                    }
                } else if (data > current->data) {
                    if (current->right == NULL) {
                        current->right = createNode(data);
                        break;
                    } else {
                        current = current->right;
                    }
                } else {
                    // Handle duplicate nodes if necessary
                    // For this example, skipping duplicates
                    break;
                }
            }
        }
    }

    // Check if the tree is a Binary Search Tree (BST)
    if (isBst(root)) {
        printf("The binary tree is a Binary Search Tree (BST).\n");
    } else {
        printf("The binary tree is not a Binary Search Tree (BST).\n");
    }

    // TODO: Implement a function to free the allocated memory for nodes if needed

    return 0;
}

