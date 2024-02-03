#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *create(int item) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = item;
    node->left = node->right = NULL;
    return node;
}

void inorder(struct Node *root) {
    if (root == NULL) {
        return;
    } else {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct Node *findMinimum(struct Node *cur) {
    while (cur->left != NULL) {
        cur = cur->left;
    }
    return cur;
}

struct Node *insertion(struct Node *root, int item) {
    if (root == NULL) {
        return create(item);
    }
    if (item < root->data) {
        root->left = insertion(root->left, item);
    } else if (item > root->data) {
        root->right = insertion(root->right, item);
    }
    return root;
}

void search(struct Node *cur, int item, struct Node *parent) {
    while (cur != NULL && cur->data != item) {
        parent = cur;
        if (item < cur->data) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
}

void deletion(struct Node *root, int item) {
    struct Node *parent = NULL;
    struct Node *cur = root;
    search(cur, item, parent);
    if (cur == NULL) {
        return;
    }
    if (cur->left == NULL && cur->right == NULL) {
        if (cur != root) {
            if (parent->left == cur) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        } else {
            root = NULL;
        }
        free(cur);
    } else if (cur->left && cur->right) {
        struct Node *succ = findMinimum(cur->right);
        int val = succ->data;
        deletion(root, succ->data);
        cur->data = val;
    } else {
        struct Node *child = (cur->left) ? cur->left : cur->right;
        if (cur != root) {
            if (cur == parent->left) {
                parent->left = child;
            } else {
                parent->right = child;
            }
        } else {
            root = child;
            free(cur);
        }
    }
}

int main() {
    struct Node *root = NULL;
    int keys[8];
    int i;
    
    for (i = 0; i < 8; i++) {
        printf("Enter value to insert: ");
        scanf("%d", &keys[i]);
        root = insertion(root, keys[i]);
    }
    
    printf("Inorder traversal before deletion: ");
    inorder(root);
    printf("\n");

    int keyToDelete;
    printf("Enter value to delete: ");
    scanf("%d", &keyToDelete);
    deletion(root, keyToDelete);

    printf("Inorder traversal after deletion: ");
    inorder(root);

    return 0;
}

