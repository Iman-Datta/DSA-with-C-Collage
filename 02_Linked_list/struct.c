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

int main () {
    int choice, value;
    printf("Press 1: insert data at the starting\n");
    printf("Press 2: insert data at the end\n");
    printf("Press 3: insert data at the middle\n");
    printf("Press 4: Display\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("Enter the your data: ");
        scanf("%d", &value);
        Begining(value);
        break;insert
    case 2:
        printf("Enter the your data: ");
        scanf("%d", &value);
        insertEnd(value);
        break;
    default:
        break;
    }
}