# include <stdio.h>
# include <stdlib.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct Node{
    int data;
    struct Node *next;
} node;

node *front = NULL;
node *rear = NULL;

bool isEmpty(){
    if (front == NULL){
        return true;
    }
    return false;
}

void enqueue(int val){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;

    if (! newNode){
        printf("Queue overflow");
        return;
    }
    else if(rear == NULL){
        front = rear = newNode;
        return;
    }
    else{
        rear->next = newNode;
        rear = newNode;
        return;
    }
}

void dequeue(){
    node *temp = front;
    bool status = isEmpty();
    if (status){
        printf("The queue is empty.");
        return;
    }
    else if(front == rear){ // 1st Node
        node *temp = front;
        front = rear = NULL;
        free(temp);
        return;
    }
    else{
        front = front->next;
        free(temp);
    }
}

void display(){
    bool status = isEmpty();
    if (status) {
        printf("Empty queue");
        return;
    }
    struct Node* temp = front;
    while (temp != NULL){
        printf("%d \t", temp->data);
        temp= temp->next;
    }
}

int main() {
    int choice, value;

    do {
        printf("\n--- Queue Menu (Linked List) ---\n");
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