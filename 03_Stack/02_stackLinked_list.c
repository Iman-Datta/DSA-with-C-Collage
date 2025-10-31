# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

node *top = NULL;

bool isEmpty(){ // Stack underflow condition.
    if(top == NULL){
        return true;
    }
    return false;
}

void push(int val) {
    node *newNode = (node*)malloc(sizeof(node));
    if (!newNode) { // Over flow condition
        printf("Heap Overflow\n");
        return;
    }
    newNode->data = val;
    newNode->next = NULL;
    if (top == NULL){
        top = newNode;
    }
    else{
        newNode->next = top;
        top = newNode;
    }
}

void display(){
    node *temp = top;
    bool status = isEmpty();
    if (status) {
        printf("Empty Stack");
        return;
    }

    while (temp != NULL){
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    free (temp);
}

void pop(){
    bool status = isEmpty();
    if (status) {
        printf("Empty Stack");
        return;
    }
    top = top->next;
}

void viewTop(){
    bool status = isEmpty();
    if (status) {
        printf("Empty Stack");
        return;
    }
    printf("The top is: %d", top->data);
}

int main() {
    int choice, value;
    
    while (1) {
        printf("\n----- Stack Menu -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. top\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                viewTop();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}