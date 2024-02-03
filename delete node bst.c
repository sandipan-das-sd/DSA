#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node *newNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Function to insert data into the BST
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return newNode(key);
    }
    else
    {
        if (key < node->data)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = insert(node->right, key);
        }
    }
    return node;
}

// Function for inorder traversal of the BST (displaying the tree)
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to find the minimum value node in a BST
struct node *minValueNode(struct node *node)
{
    struct node *current = node;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

// Function to delete a node with the given key from the BST
struct node *deleteNode(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    struct node *root = NULL;
    int data;
    char ch = 'y';

    // Allowing user to input nodes
    while (ch == 'y' || ch == 'Y')
    {
        printf("Enter data to be inserted: ");
        scanf("%d", &data);
        root = insert(root, data);

        printf("Do you want to insert more nodes? (y/n): ");
        scanf(" %c", &ch);
    }

    printf("BST in inorder (sorted) order: \n");
    inorder(root);
    printf("\n");

    int deleteData;
    printf("Enter the node to delete: ");
    scanf("%d", &deleteData);

    // Delete the specified node
    root = deleteNode(root, deleteData);

    printf("BST after deleting %d: \n", deleteData);
    inorder(root);
    printf("\n");

    return 0;
}

