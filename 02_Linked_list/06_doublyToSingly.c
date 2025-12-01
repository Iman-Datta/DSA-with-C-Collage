#include <stdio.h>
#include <stdlib.h>

/* ---------- Singly Linked List ---------- */
struct SNode {
    int data;
    struct SNode *next;
};

/* ---------- Doubly Linked List ---------- */
struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
};

/* ---------- Create Singly Node ---------- */
struct SNode* createSNode(int value) {
    struct SNode *newNode = (struct SNode*)malloc(sizeof(struct SNode));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

/* ---------- Create Doubly Node ---------- */
struct DNode* createDNode(int value) {
    struct DNode *newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

/* ---------- Insert at End (Singly) ---------- */
struct SNode* insertSinglyAtEnd(struct SNode *head, int value) {
    struct SNode *newNode = createSNode(value);

    if (head == NULL)
        return newNode;

    struct SNode *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* ---------- Convert Singly → Doubly ---------- */
struct DNode* singlyToDoubly(struct SNode *head) {
    struct SNode *tempS = head;
    struct DNode *dHead = NULL;
    struct DNode *tempD;

    while (tempS != NULL) {
        struct DNode *newNode = createDNode(tempS->data);

        if (dHead == NULL) {
            dHead = newNode;
        } else {
            tempD = dHead;
            while (tempD->next != NULL)
                tempD = tempD->next;

            tempD->next = newNode;
            newNode->prev = tempD;
        }

        tempS = tempS->next;
    }

    return dHead;
}

/* ---------- Convert Doubly → Singly ---------- */
struct SNode* doublyToSingly(struct DNode *head) {
    struct DNode *tempD = head;
    struct SNode *sHead = NULL;
    struct SNode *tempS;

    while (tempD != NULL) {
        struct SNode *newNode = createSNode(tempD->data);

        if (sHead == NULL) {
            sHead = newNode;
        } else {
            tempS = sHead;
            while (tempS->next != NULL)
                tempS = tempS->next;

            tempS->next = newNode;
        }

        tempD = tempD->next;
    }

    return sHead;
}

/* ---------- Print Singly ---------- */
void printSingly(struct SNode *head) {
    printf("Singly List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* ---------- Print Doubly (Forward) ---------- */
void printDoubly(struct DNode *head) {
    printf("Doubly List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/* ---------- MAIN ---------- */
int main() {
    struct SNode *sHead = NULL;
    struct DNode *dHead = NULL;
    struct SNode *sAgain = NULL;

    /* Create Singly List */
    sHead = insertSinglyAtEnd(sHead, 10);
    sHead = insertSinglyAtEnd(sHead, 20);
    sHead = insertSinglyAtEnd(sHead, 30);
    sHead = insertSinglyAtEnd(sHead, 40);

    printSingly(sHead);

    /* Singly → Doubly */
    dHead = singlyToDoubly(sHead);
    printDoubly(dHead);

    /* Doubly → Singly */
    sAgain = doublyToSingly(dHead);
    printSingly(sAgain);

    return 0;
}
