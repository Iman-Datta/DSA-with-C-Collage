# include <stdio.h>
# include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};
typedef struct Node node; // Allias

// typedef int apple; 
// apple a;

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

void insertAtAnyNode(int value, int position) {
    if (position < 1){
    printf("Invalid node position.\n");
    return;
    }

    if (position == 1){
        insertBegining(value);
        return;
    }

    node *newNode = createNode(value);
    node *temp = head, *pre_temp = head;

    while(temp != NULL && position > 1) {
        pre_temp = temp;
        temp = temp->next;

        position --;
    }
    pre_temp->next = newNode;
    newNode->next = temp;
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

void deleteBeginning (){
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    node* temp = head;
    head = head->next;
    free(temp);
}

void deleteEnd(){
    node *temp = head, *pre_temp = head;
    if (temp == NULL) {
        printf("List is already empty.\n");
        return;
    }

        if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != NULL){
        pre_temp = temp;
        temp = temp->next;
    }

    pre_temp->next = NULL;
    free(temp);
}

void deleteAnyNode(int position) {
    node *temp = head, *past =  head, *future = NULL;
    if (temp == NULL) {
        printf ("List is already empty.\n");
        return;
    }
    
    if (position < 1) {
        printf("Invalid position");
        return;
    } 

    if (position == 1) {
        deleteBeginning(position);
        return;
    }

    while (position > 1) {
        past = temp;
        temp = temp->next;

        position --;
    }

    future = temp->next->next;
    past->next = future;
    free(temp);
}

void searchByValue(int val){
    node *temp =  head;
    int pos = 1, status = 0;

    if (temp == NULL) {
        printf("List is already empty.\n");
    }

    while (temp->next != NULL) {
        if (temp->data == val) {
            printf("Your data is found in %d node. The addrees of that node is %d \n", pos, temp->next);
            status = 1;
        }
        pos ++;
        temp = temp->next;
    }
    if (status == 0) {
        printf ("Value %d not found in the list.\n", val);
    }
    
}

void searchByposition(int pos){

}

int main () {
    int choice, value, position;
    while (1)
    {
        printf("\nPress 1: insert data at the starting\n");
        printf("Press 2: insert data at the end\n");
        printf("Press 3: insert data at any node\n");
        printf("Press 4: Display\n");
        printf("Press 5: Delete from beginning\n");
        printf("Press 6: Delete from end\n");

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
            insertAtAnyNode(value, position);
            break;
        case 4:
            display();
            break;
        case 5:
            deleteBeginning();
            break;
        case 6:
            deleteEnd();
            break;
        case 7:
            printf("Enter the number of node: ");
            scanf("%d", &position);
            deleteAnyNode(position);
        case 8:
            printf("Enter your data: ");
            scanf("%d", &value);
            searchByValue(value);
        case 9:
            printf("Enter the node position: ");
            scanf("%d", &position);
            searchByposition(position);
        default:
            break;
        }
    }
}