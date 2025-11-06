# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

// In case of linked list the head node is a global node
node* head = NULL;

node *createNode(int val){
    node *newNode = (node*)malloc(sizeof(node));

    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

void insertBegining(int val){
    node *newNode = createNode(val);
    if (head == NULL){
        head = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

void display(){
    node* temp = head;
    if (head == NULL) {
        printf("Your linked list is empty\n");
        return;
    }
    
    printf("Your Linked List: \n");
    while (temp != NULL) {
        printf("%d -->>", temp->data);
        temp = temp->next;
    }
}

void insertEnd(int val) {
    node *newNode = createNode(val);
    node *temp = head;

    if (head == NULL) {
        head = newNode;
    }
    else {
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtAnyNode(int val, int pos){
    int count = 0;
    node* temp = head, *preTemp = head;
    while (temp != NULL) {
        count ++;
        temp = temp->next;
    }
    temp = head;

    node *newNode = createNode(val);

    if (pos < 0 || pos > count) {
        printf("Invalid node position.\n");
        return;
    }
    else if (head == NULL){
        head = newNode;
        return;
    }
    else if (pos == 0) {
        insertBegining(val);
        return;
    }
    else {
        while (pos > 0 && temp != NULL){
            preTemp = temp;
            temp = temp->next;
            pos --;
        }
        newNode->next = temp;
        preTemp->next = newNode;
        return;
    }

}

void deleteBeginning(){
    node *temp = head;
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    head = head->next;
    free(temp);
}

void deleteEnd(){
    node *temp = head, *preTemp = head;
    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    if (temp->next == NULL){
        free(temp);
        head = NULL;
        return;
    }
    while (temp->next != NULL){
        preTemp = temp;
        temp = temp->next;
    }

    preTemp->next = NULL;
    free(temp);
}

void deleteAnyNode(int pos){
    node *temp = head, *past =  head, *future = NULL;
    if (pos < 0) {
        printf ("Invalid position.\n");
        return;
    }
    else if (pos == 0) {
        deleteBeginning();
        return;
    }
    else{
        while (pos != 0  && temp != NULL){
            past = temp;
            temp = temp->next;
            pos --;
        }
        if (temp == NULL){
            printf("Position out of range.\n");
            return;
        }
        past->next = temp->next;
        free(temp);
        return;
    }
}

void searchByValue(int val) {
    node *temp = head;
    int pos = 0, status = 0;

    if (head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    while(temp != NULL){
        if (temp->data == val) {
            printf("Your data is found at node position %d", pos);
            status = 1;
        }
        temp = temp->next;
        pos ++;
    }
    if (status == 0){
        printf("Not found");
    }
    return;
}

void searchByposition(int pos) {
    node *temp = head;
    int tempPos = pos;

    while (pos > 0 && temp != NULL){
        temp = temp->next;
        pos --;
    }
    if (temp == NULL) {
        printf("Position %d not found.\n", tempPos);
        return;
    }
    printf("At %d number node: Your data is %d \n", tempPos, temp->data);
}

void reverseList() {
    node *prev = NULL;
    node *current = head;
    node *next = NULL;

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
    printf("Linked list reversed successfully.\n");
}


int main () {
    int choice, value, position;
    while (1){
        printf("\nPress 1: insert data at the starting\n");
        printf("Press 2: insert data at the end\n");
        printf("Press 3: insert data at any node\n");
        printf("Press 4: Display\n");
        printf("Press 5: Delete from beginning\n");
        printf("Press 6: Delete from end\n");
        printf("Press 7: Delete at any node\n");
        printf("Press 8: Search by value\n");
        printf("Press 9: Search by position\n");
        printf("Press 10: reverse the linked list\n");
        printf("Press 11: Exsit the function\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
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
            break;

            case 8:
            printf("Enter your data: ");
            scanf("%d", &value);
            searchByValue(value);
            break;

            case 9:
            printf("Enter the node position: ");
            scanf("%d", &position);
            searchByposition(position);
            break;

            case 10:
            reverseList();
            break;

            case 11:
            printf("Exiting the program.\n");
            return 0;

            default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
}

// 1. In a linked list, the head is a pointer (usually a struct type variable) that stores the address of the first node. The head itself doesn’t contain data; it only points to the first node.

// 2. The last node contains data, but its pointer to the next node is set to NULL, indicating the end of the list.