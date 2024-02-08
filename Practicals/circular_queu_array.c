#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 30
int front=-1;
int rear=-1;
int cq[N];
void enqueue() {
    int value;
    printf("Enter the value to insert:\n");
    scanf("%d", &value);
    if (front == -1 && rear == -1) {
        front = rear = 0;
        cq[rear] = value;
    }
    else if (((rear + 1) % N) == front) {
        printf("Queue is full\n");
        // This condition checks if rear+1 modulo N is equal to front.
        // It indicates that the circular queue is full.
         // because the new element will be added after rear and the next available space is at the position indicated by front
    }
    else {
        rear = (rear + 1) % N;
        cq[rear] = value;
        printf("%d value inserted\n", cq[rear]);
    }
}
void dequeue() {
    // Check if the queue is empty
    if (front == -1 && rear == -1) {
        printf("Queue is empty\nNo element to dequeue\n");
    }
    // If there is only one element in the queue
    else if (front == rear) {
        printf("Dequeued element is: %d\n", cq[front]);
        front = rear = -1;
    }
    else {
        // Print the dequeued element
        printf("Dequeued element is: %d\n", cq[front]);
        // Move the front pointer to the next element in the circular queue
        front = (front + 1) % N;
    }
}
void peek() {
    // Check if the queue is empty
    if (front == -1 && rear == -1) {
        printf("Queue is empty. No element to peek.\n");
    }
    else {
        // Print the element at the front of the queue
        printf("Peeked element is: %d\n", cq[front]);
    }
}

void display() {
    // Check if the queue is empty
    if (front == -1 && rear == -1) {
        printf("No elements in the queue to display.\n");
    }
    else {
        int i = front; // Start from the front of the queue
        printf("Elements in the circular queue are:\n");
        // Loop through the circular queue until the rear
        while (i != rear) {
            printf("%d\n", cq[i]);
            i = (i + 1) % N; // Move to the next element in the circular queue
        }
        // Print the last element in the circular queue
        printf("%d\n", cq[rear]);
    }
}

int main(){
	int option;
	while(1){
	printf("\n************Queue Operation ******************\n");
	printf("1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
	printf("Enter your choice:-\n");
	scanf("%d",&option);
	switch (option)
	{
	case 1:
		/* code */
		// int value;
		printf("Enter the data to insert in the queue:-\n");
		enqueue();
		break;
		case 2:
		dequeue();
		break;
			case 3:
			printf("The peek elements are:-\n");
			peek();
			break;
				case 4:
				printf("The queue elemnts are:_\n");
				display();
				break;
                    case 5:
                    printf("The process end...\n");
                    exit(0);
	default:
	printf("Invalid Choice!!!!\n");
		break;
	}
}
}