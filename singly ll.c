#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *head = NULL;
    struct node *ptr, *new_node;
    int option, data, pos, i;

    while(1)
    {
        printf("******Linked List*******\n");
        printf("1. INSERT FIRST\n2. INSERT LAST\n3. INSERT AT SPECIFIC POSITION\n4. EXIT\n5. Display\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Enter the data to INSERT at First: ");
                scanf("%d", &data);
                new_node = (struct node*)malloc(sizeof(struct node));
                new_node->data = data;
                new_node->link = head;
                head = new_node;
                printf("Node inserted at the first\n");
                break;

            case 2:
                printf("Enter the data to insert at end: ");
                scanf("%d", &data);
                new_node = (struct node*)malloc(sizeof(struct node));
                new_node->data = data;
                new_node->link = NULL;
                if (head == NULL) {
                    head = new_node;
                } else {
                    ptr = head;
                    while (ptr->link != NULL) {
                        ptr = ptr->link;
                    }
                    ptr->link = new_node;
                }
                printf("Node inserted at the last\n");
                break;

            case 3:
                printf("Enter the position to insert at the specific position: ");
                scanf("%d", &pos);
                printf("Enter the data: ");
                scanf("%d", &data);
                new_node = (struct node*)malloc(sizeof(struct node));
                new_node->data = data;
                new_node->link = NULL;

                if (pos == 1) {
                    new_node->link = head;
                    head = new_node;
                } else {
                    ptr = head;
                    for (i = 1; i < pos - 1 && ptr != NULL; i++) {
                        ptr = ptr->link;
                    }

                    if (ptr == NULL) {
                        printf("Invalid position\n");
                        free(new_node);
                        continue;
                    }

                    new_node->link = ptr->link;
                    ptr->link = new_node;
                }
                printf("Linked list is inserted at specific position...\n");
                break;

            case 4:
                printf("Process End...\n");

                // Free allocated memory
                ptr = head;
                while (ptr != NULL) {
                    struct node *temp = ptr;
                    ptr = ptr->link;
                    free(temp);
                }

                exit(0);
                break;

            case 5:
                printf("The linked list is: ");
                ptr = head;
                while (ptr != NULL) {
                    printf("%d ", ptr->data);
                    ptr = ptr->link;
                }
                printf("\n");
                break;

            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

