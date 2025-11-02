# include <stdio.h>
# include <stdlib.h>

struct linkedList{
    int data;
    struct linkedList *next;
};
typedef struct linkedList node;


node *createNode(int val){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(node **head, int val){
    node* newNode = createNode(val);
    if(*head == NULL){
        *head = newNode;
    }
    else{
        node *temp = *head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(node* head){
    if(head == NULL){
        return;
    }
    else{
        node *temp = head;
        while (temp != NULL){
            printf("%d \t", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

node *mergeSortedLists(node *h1, node *h2){
    node *result;
    if(h1 == NULL) return h2;
    if(h2 == NULL) return h1;
    if(h1->data < h2->data){
        result = h1;
        result->next = mergeSortedLists(result->next, h2);
    }
    else{
        result = h2;
        result->next = mergeSortedLists(h1, result->next);
    }
    return result;
}

int main () {
    node* head1 = NULL;
    node* head2 = NULL;

    int n,m, val;
    printf("Enter the number of element in 1st linked list: ");
    scanf("%d", &n);

    printf("Enter elements in sorted order for List 1:\n");
    for(int i = 0; i <n; i++){
        scanf("%d", &val);
        insertAtEnd(&head1, val);
    }

    printf("Enter the number of element in 2nd linked list: ");
    scanf("%d", &m);

    printf("Enter elements in sorted order for List 2:\n");
    for(int i = 0; i <m; i++){
        scanf("%d", &val);
        insertAtEnd(&head2, val);
    }

    printf("\nList 1: ");
    printList(head1);
    printf("List 2: ");
    printList(head2);
    
    node* mergedList = mergeSortedLists(head1, head2);
    printf("\nMerged Sorted List: ");
    printList(mergedList);

    return 0;
}