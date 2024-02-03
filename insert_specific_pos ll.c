#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
	int pos,data,i;
	
	
		
	
   
    struct node *head = NULL;
    struct node *ptr, *new_node;

    new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the data: ");
    scanf("%d", &data);

    new_node->data = data;
    new_node->link = NULL;

    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        new_node->link = head;
        head = new_node;
    } else {
        ptr = head;
        for ( i = 1; i < pos - 1 && ptr != NULL; i++) {
            ptr = ptr->link;
        }

        if (ptr == NULL) {
            printf("Invalid position\n");
            free(new_node);
            return 1;
        }

        new_node->link = ptr->link;
        ptr->link = new_node;
    }

    printf("Linked list after insertion: ");
    ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }

    // Free allocated memory
    ptr = head;
    while (ptr != NULL) {
        struct node *temp = ptr;
        ptr = ptr->link;
        free(temp);
    }

    return 0;

}

