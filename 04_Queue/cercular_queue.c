#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = 0, rear = -1, size = 0;  // front = 0 initially

// Check if queue is full
int isFull() {
    return size == MAX_SIZE;
}

// Check if queue is empty
int isEmpty() {
    return size == 0;
}

// Enqueue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    rear = (rear + 1) % MAX_SIZE;  // circular increment
    queue[rear] = value;
    size++;
    printf("%d enqueued to queue\n", value);
}

// Dequeue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("%d dequeued from queue\n", queue[front]);
    front = (front + 1) % MAX_SIZE;  // circular increment
    size--;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", queue[(front + i) % MAX_SIZE]);
    }
    printf("\n");
}

// Menu-driven main
int main() {
    int choice, value;

    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
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
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}