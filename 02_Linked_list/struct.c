# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
} node;

node *head = NULL;

node* createNode(int val){
    node* newNode = (node*)malloc(sizeof(node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return 0;
    }

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

void insertBegining(int value){
    node* newNode = createNode(value);
    if (head == NULL){
        head = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }
}

void insertEnd(int value) {
    node *newNode = createNode(value);
    node *temp = head;
    if (head == NULL){
        head = newNode;
    }
    else{
        while (temp->next != NULL){
            temp =  temp->next;
        }
    temp->next = newNode;
    }
}

void insertMiddle(int value, int position) {
    if (position < 1){
        printf("Invalid node position \n");
        return;
    }
    if (position == 1){
        insertBegining(value);
    }
    node *newNode = createNode(value);
    node *temp = head;
    for (int  i = 0; i < position - 1; i++){
        if (temp ==  NULL){
            printf("Invalid node position \n");
            temp = temp->next;
        }
    }
    
     
}

void display() {
    node *temp = head;
    if (head == NULL) {
        printf("Your linked list is empty\n");
        return;
    }

    printf("Your Linked List: \n");
    while (temp != NULL){
        printf("%d -->>", temp->data);
        temp =  temp->next;
    }
}

int main () {
    int choice, value, position;
    while (1)
    {
        printf("\nPress 1: insert data at the starting\n");
        printf("Press 2: insert data at the end\n");
        printf("Press 3: insert data at the middle\n");
        printf("Press 4: Display\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
    
        switch (choice)
        {
        case 1:
            printf("Enter the your data: ");
            scanf("%d", &value);
            insertBegining(value);
            break;
        case 2:
            printf("Enter the your data: ");
            scanf("%d", &value);
            insertEnd(value);
            break;
        case 3:
            printf("Enter the your data: ");
            scanf("%d", &value);
            printf("Enter the number of node: ");
            scanf("%d", &position);
            insertMiddle(value, position);
            break;
        case 4:
            display();
            break;
        default:
            break;
        }
    }
    
}