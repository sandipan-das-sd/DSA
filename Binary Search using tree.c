#include <stdio.h>
#include <stdlib.h>

// Defining node structure
struct node {
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function to insert nodes in the correct position
struct node* insert(struct node* node, int data) {
    if (node == NULL) {
        return newNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    return node;
}

// Function to search for a node with a specific key
struct node* search(struct node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    // If the key is smaller, search in the left subtree
    if (key < root->data) {
        return search(root->left, key);
    }

    // If the key is larger, search in the right subtree
    return search(root->right, key);
}

int main() {
    struct node* root = NULL;
    root = insert(root, 9);
    insert(root, 7);
    insert(root, 5);
    insert(root, 8);
    insert(root, 14);
    insert(root, 11);
    insert(root, 16);

    int key ;
    printf("Enter the number to search:-\n");
    scanf("%d",&key);
    struct node* result = search(root, key);

    if (result != NULL) {
        printf("Node with key %d found in the tree.\n", key);
    } else {
        printf("Node with key %d not found in the tree.\n", key);
    }

    // Don't forget to free the allocated memory for nodes when done
    // Implementing freeing of memory is left as an exercise for the user

    return 0;
}

