# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

# define MAX 5

int queue[MAX];
int front = -1, rear = -1;

bool isEmpty(){
    if (front == -1){
        return true;
    }
    return false;
}

bool isFull(){
    if (rear == MAX - 1){
        return true;
    }
    return false;
}

void enqueue(int val){
    bool status = isFull();
    if (status){
        printf("Queue is full. Cannot insert %d\n", val);
        return;
    }
    else {
        if (front == -1){
            front = 0;
        }
        queue[++rear] = val;
        printf("%d inserted into queue\n", val);
    }
}

void dequeue(){
    bool status = isEmpty();
    if(status) {
        printf("Queue is empty");
        return;
    }
    else{
        if (front == rear){
            front = rear = -1;
        }
        else{
            front ++;
        }
    }
}

void display(){
    bool status = isEmpty();
    if(status) {
        printf("Queue is empty");
        return;
    }
    for (int i =  front; i <= rear; i++){
        printf("%d \t", queue[i]);
    }
    printf("\n");
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
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
