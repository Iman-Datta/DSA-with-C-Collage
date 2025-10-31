# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

# define MAX 5

int stack[MAX];
int top = -1;

bool isEmpty() {
    if (top == -1) {
        return true;
    }
    return false;
}

void push(int val){
    if(top >= MAX -1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

void pop() {
    bool state = isEmpty();
    if (state){
        printf("Stack is empty\n");
        return;
    }
    else
        top--;
}

void display(){
    bool state = isEmpty();
    if (state){
        printf("Stack is empty\n");
        return;
    }
    else{
        for (int i = top; i >= 0; i--){
            printf("%d \t", stack[i]);
        }
        printf("\n");
    }
}

void viewtop(){
    bool state = isEmpty();
    if (state){
        printf("Stack is empty\n");
        return;
    }
    else
    printf("The top is: %d\n", stack[top]);
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
                viewtop();
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
