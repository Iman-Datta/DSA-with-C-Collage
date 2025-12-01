#include <stdio.h>
#include <stdlib.h>

// Singly linked list node
struct SNode {
    int data;
    struct SNode *next;
};

// Doubly linked list node
struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
};

// global heads
struct SNode *sHead = NULL;
struct DNode *dHead = NULL;

// create singly node
struct SNode* createSNode(int value) {
    struct SNode *newNode = (struct SNode*)malloc(sizeof(struct SNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// insert at end of singly list
void insertSinglyAtEnd(int value) {
    struct SNode *newNode = createSNode(value);

    if (sHead == NULL) {
        sHead = newNode;
        return;
    }

    struct SNode *temp = sHead;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// create doubly node
struct DNode* createDNode(int value) {
    struct DNode *newNode = (struct DNode*)malloc(sizeof(struct DNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// convert singly to doubly (your insertAtEnd style)
struct DNode* singlyToDoubly(struct SNode *head) {
    struct SNode *tempS = head;
    struct DNode *dHead = NULL;
    struct DNode *tempD;

    while (tempS != NULL) {

        // create new doubly node from singly node data
        struct DNode *newNode = createDNode(tempS->data);

        // same style as your insertAtEnd
        if (dHead == NULL) {
            dHead = newNode;
        } else {
            tempD = dHead;
            while (tempD->next != NULL) {
                tempD = tempD->next;
            }
            tempD->next = newNode;
            newNode->prev = tempD;
        }

        tempS = tempS->next;
    }

    return dHead;
}

// print singly list
void printSingly(struct SNode *head) {
    struct SNode *temp = head;
    printf("Singly list: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// print doubly list (forward)
void printDoubly(struct DNode *head) {
    struct DNode *temp = head;
    printf("Doubly list (forward): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // create a singly list: 10 -> 20 -> 30 -> 40
    insertSinglyAtEnd(10);
    insertSinglyAtEnd(20);
    insertSinglyAtEnd(30);
    insertSinglyAtEnd(40);

    printSingly(sHead);

    // convert to doubly
    dHead = singlyToDoubly(sHead);

    printDoubly(dHead);

    return 0;
}
