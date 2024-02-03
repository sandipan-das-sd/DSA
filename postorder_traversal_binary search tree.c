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

// Postorder traversal of the tree
void PostOrder(struct node* root) {
    if (root != NULL) {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
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

    printf("The Postorder is:\n");
    PostOrder(root);

    // Free memory (not included in the original code)
    // You should implement a function to deallocate the tree nodes

    return 0;
}

