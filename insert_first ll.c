#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* head = NULL;

int main()
{
    int choice, n;
    struct node *ptr, *new_node;
    
    while(1)
    {
        printf("*******Linked list menu*******\n");
        printf("1. Insert at the beginning\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                new_node = (struct node*)malloc(sizeof(struct node));
                if(new_node == NULL)
                {
                    printf("Memory allocation failed\n");
                    exit(1);
                }

                printf("Enter data to insert: ");
                scanf("%d", &n);
                new_node->data = n;
                new_node->next = NULL;

                if(head == NULL)
                {
                    head = new_node;
                }
                else
                {
                    ptr = head;
                    while(ptr->next != NULL)
                    {
                        ptr = ptr->next;
                    }
                    ptr->next = new_node;
                }
                break;
            case 2:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

