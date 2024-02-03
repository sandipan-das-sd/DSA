#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void insertFirst(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head; 
        head = newNode;
    }
}

void insertLast(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

void insertAtPosition(int data, int position) {
	int i;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (position == 1) {
        insertFirst(data);
    } else {
        struct Node* temp = head;
        for (i = 1; i < position - 1; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteFirst() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            temp->next = head->next;
            free(head);
            head = temp->next;
        }
    }
}

void deleteLast() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = head;
        struct Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == head) { //applicable for one node
            free(temp);
            head = NULL;
        } else {
            prev->next = head;
            free(temp);
        }
    }
}

void deleteAtPosition(int position) {
	int i;
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = head;
        struct Node* prev = NULL;
        for ( i = 1; i < position; ++i) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == head) {
            deleteFirst();
        } else {
            prev->next = temp->next;
            free(temp);
        }
    }
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
    } else {
        struct Node* temp = head;
        do {
            printf("%d -> ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf(" (head)\n");
    }
}

int main() {
    int choice, data, position;
    while (1) {
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete at Specific Position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertFirst(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertLast(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                deleteFirst();
                break;
            case 5:
                deleteLast();
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 7:
                display();
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}

