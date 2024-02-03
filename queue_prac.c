#include <stdio.h>
#include <stdlib.h>

#define size 20
int front = -1;
int rear = -1;
int queue[size];

void insert();
int delete();
void display();

int main() {
    int option, value;

    do {
        printf("***Queue Menu***\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                insert();
                break;
            case 2:
                value = delete();
                if (value != -1) {
                    printf("Deleted value: %d\n", value);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Process ended.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again!\n");
        }
    } while (option != 4);

    return 0;
}

void insert() {
    int value;

    if (rear == (size - 1)) {
        printf("Queue overflow.\n");
    } else {
        printf("Enter the value to insert: ");
        scanf("%d", &value);

        if (rear == -1 && front == -1) {
            rear = front = 0;
        } else {
            rear = rear + 1;
        }

        queue[rear] = value;
    }
    
}

int delete() {
    int temp;

    if (front == -1 || front > rear) {
        printf("Queue underflow.\n");
        return -1; // Return a sentinel value to indicate an error
    } else {
        temp = queue[front];
        front = front + 1;

        if (front > rear) {
            front = rear = -1;
        }

        return temp;
    }
}

void display() {
    int i;

    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements:\n");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

