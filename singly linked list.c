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
    struct node *ptr, *new_node,*current,*prev;
    int option, data, pos, i;

    while(1)
    {
        printf("          ********************Singly Linked List*********************\n");
        printf(" 1. INSERT FIRST\n 2. INSERT LAST\n 3. INSERT AT SPECIFIC POSITION\n 4. EXIT\n 5. Display\n 6.Delete First\n 7.Delete Last\n 8.Delete at specific position\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                printf("Enter the data to INSERT at First: ");
                scanf("%d", &data);
                new_node = (struct node*)malloc(sizeof(struct node));
                new_node->data = data;
                //logic
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
                //logic
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
                        ptr = ptr->link; //traversal
                    }

                    if (ptr == NULL) {
                        printf("Invalid position\n");
                        free(new_node);
                        continue;
                    }

                    new_node->link = ptr->link;// ptr moves to pos+1
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
                	case 6:
                		//delete at first
                		// Assuming new_node is the first node
					if (head != NULL) 
					{
    				struct node *temp = head;
    				head = head->link; // Move head to the second node
    				free(temp); // Free the memory occupied by the first node
    				printf("First Node deleted\n");
					}
					else 
					{
    				printf("List is empty. Cannot delete from an empty list.\n");
					}
					break;
				case 7:
					//delete at last 
				      temp = head;
                       while(temp->link != NULL) {
    				        if(temp->link == new_node) {
        					 struct node *prev = temp->link;
        						temp->link = prev->link;
        						free(prev);
       					printf("Node deleted successfully at the end");
        				break; // exit the loop after deleting the node
    					}
    					current = current->link;
						}
						case 8:
							//delete at specific position
							// delete at specific position
								current = head;
								struct node *temp = NULL;
								printf("Enter the position to delete:-\n");
								scanf("%d", &pos);

								if (pos == 1 && current != NULL) {
    							head = current->link;
    							free(current);
    							printf("Node deleted successfully at position %d", pos);
								} else {
    							int count = 1;
    							while (count < pos - 1 && current != NULL && current->link != NULL) {
        							current = current->link;
        							count++;
    								}

    							if (current == NULL || current->link == NULL) {
        						printf("Invalid position");
    							} else {
       							temp = current->link;
        						current->link = temp->link;
        						free(temp);
        						printf("Node deleted successfully at position %d", pos);
    							}
								}

							break;

					
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

