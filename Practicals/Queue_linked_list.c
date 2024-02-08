#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed. Unable to enqueue.\n");
        return;
    }

    new_node->data = data;
    new_node->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    printf("Element enqueued in queue\n");
}

void dequeue() {
    if (front == NULL) {
        printf("No element to dequeue in queue\n");
    } else {
        struct node *temp = front;
        front = front->next;
        free(temp);
        if (front == NULL) {
            rear = NULL; // Reset rear if the queue becomes empty
        }
        printf("Dequeued the element\n");
    }
}

void display() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct node *ptr = front;
        printf("Queue elements: ");
        while (ptr != NULL) {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void peek() {
    if (front == NULL) {
        printf("No element to peek\n");
    } else {
        printf("Peeked element is: %d\n", front->data);
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("\n********* Queue using Linked List **********\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                printf("Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
