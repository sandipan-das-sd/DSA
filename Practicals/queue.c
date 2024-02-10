#include <stdio.h>
#include <stdlib.h>

#define N 5

int front = -1;
int rear = -1;
int queue[N];

void enqueue() {
    int value;
    printf("\nEnter the data to insert: ");
    scanf("%d", &value);
    if (rear == N - 1) {
        printf("Queue is Overflow\n");
    } else {
        if (front == -1 )
            front = 0;
        rear++;
        queue[rear] = value;
        printf("%d value inserted\n", queue[rear]);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is underflow\n");
    } else {
        printf("The dequeued element is %d\n", queue[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}

void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is underflow\n");
    } else {
        printf("The peeked element is: %d\n", queue[front]);
    }
}

void display() {
    printf("The queue elements are: ");
    if (front == -1 || front > rear) {
        printf("Queue is underflow. No data to display\n");
    } else {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int option;
    do {
        printf("\n*QUEUE MENU*\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice:- ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (option != 5);
    return 0;
}