// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//     int value;
//     struct node *next;
// };

// struct node *head = NULL;

// void push() {
//     struct node *new_node = (struct node *)malloc(sizeof(struct node));
//     if (new_node == NULL) {
//         printf("Not able to push to the memory");
//     } else {
//         int data;
//         printf("Enter the data of the new node: ");
//         scanf("%d", &data);
//         new_node->value = data;
//         new_node->next = head;
//         head = new_node;
//         printf("Value inserted into node\n");
//     }
// }

// void pop() {
//     int item;
//     struct node *ptr;

//     if (head == NULL) {
//         printf("Underflow\n");
//     } else {
//         // store the current first value to the item
//         item = head->value;
//         // store the head to ptr
//         ptr = head;
//         // move the head to the next node
//         head = head->next;
//         // free the ptr
//         free(ptr);
//         printf("Item popped %d\n",ptr->value);
//     }
// }

// void display() {
//     struct node *temp = head;

//     if (temp == NULL) {
//         printf("Stack is empty\n");
//         return;
//     }

//     printf("Printing stack elements:\n");
//     while (temp != NULL) {
//         printf("%d\n", temp->value);
//         temp = temp->next;
//     }
// }

// int main() {
//     int choice;

//     while (1) {
//         printf("\n******Stack using Linked list*********\n");
//         printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);
//         switch (choice) {
//             case 1:
//                 push();
//                 break;
//             case 2:
//                 pop();
//                 break;
//             case 3:
//                 display();
//                 break;
//             case 4:
//                 printf("Exit...! Thank you!!\n");
//                 exit(0);
//             default:
//                 printf("Invalid choice\n");
//                 break;
//         }
//     }
//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct node* head=NULL;
void push(){
struct node *new_node;
int value;
new_node=(struct node*) malloc(sizeof(struct node));
if(new_node==NULL)
{
    printf("Failed to push the element:-\n");
}
else
{
    printf("Enter the value to insertt in to the stack:-");
    scanf("%d",&value);
    new_node->data=value;
    new_node->next=head; // Link the new node to the current top of the stack.
    // Update the head to point to the new node, which is the new top of the stack.
    head=new_node;
    if(head=new_node){
        printf("Value inserted to the stack.");
    }
}
}
void pop(){
    struct node *ptr;
    int item;
    if (head==NULL){
        printf("Overflow");
    }
    else
    {
    item=head->data;
    ptr=head;
    head=head->next;
    free(ptr);
    printf("Node deleted from the stack");
}
}
void display()
{
    int i;
    struct node *temp=head;
    if (temp==NULL)
    {
        printf("No element to display in the stack");
    }
    while (temp!=NULL)
    {
        /* code */
        printf("The stack element are:-\n");
        printf("%d",temp->data);
        temp=temp->next;
    }
    
}

int main()
{
    
    int choice;
    while (choice!=4)
    {
        
    
    
    printf("**************Stack Menu*******************\n");
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    printf("Enter your choice:-");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        push();
        break;
    case 2:
    pop();
    break;
    case 3:
    display();
    break;
    case 4:
    printf("Thank You!\n");
    exit(0);
    break;
    default:
        printf("Invalid choice!\n");
    }

}
}
