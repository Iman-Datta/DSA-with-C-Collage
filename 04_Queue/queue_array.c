#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5   // a. Maximum size of queue

int queue[MAX_SIZE];

int front = -1, rear = -1;


int isEmpty() { // Empty
    return (front == -1);
}

int isFull() { // Over Flow
    return (rear == MAX_SIZE - 1);
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot insert %d\n", value);
    } else {
        if (front == -1) {  // first element
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("%d inserted into queue\n", value);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("%d removed from queue\n", queue[front]);
        if (front == rear) { // For the last element
            front = rear = -1;
        } else {
            front++;
        }
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n=== Queue Menu ===\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Check if Empty\n");
        printf("5. Check if Full\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
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
                if (isEmpty())
                    printf("Queue is Empty.\n");
                else
                    printf("Queue is NOT Empty.\n");
                break;

            case 5:
                if (isFull())
                    printf("Queue is Full.\n");
                else
                    printf("Queue is NOT Full.\n");
                break;

            case 6:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}