#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void insert();
void display();
void search();
void insertInBetween();
void deleteNode();

struct node{
    int data;                   // Data or value which user will give as input
    struct node *link;    // Pointer to the next Node
};

//struct node abc;                        //struct type variable
struct node *start = NULL;      // Struct type Pointer variable

int main(){
    int ch;
    do{
        printf("\n");
        puts("!: Insert node");
        puts("2: Insert node in between");
        puts("3: Display node");
        puts("4: Enter a number to search:");
        puts("5: Enter a number to delete:");
        puts("6: To exit:");
        puts("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insert();
                break;
            case 2:
                insertInBetween();
                break;
            case 3:
                display();
                break;
            case 4:
                search();
                break;
            case 5:
                deleteNode();
                break;
            case 6:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }while(1);
    return 0;
}

void deleteNode(){
    int item, flag=0;
    struct node *ptr = start;
    struct node *prev = start;
    printf("\nEnter the value to be deleted: ");
    scanf("%d",&item);

    if(ptr ==NULL){
        printf("Empty list\n");
        start = NULL;
        return;
    } else {
        while(ptr != NULL){
            if(ptr->data == item){
                prev->link = ptr->link;
                free(ptr);
                flag=1;
                break;
            }

            prev = ptr;
            ptr = ptr->link;
        }

        if(flag==0){
            printf("\nItem to be deleted is not present");
        }
    }
}

void insert(){

    int item;
    printf("\nEnter an item: ");
    scanf("%d",&item);

    // Structure type Pointer variable can access a member of a structure using ARROW operator
    // struct type variable can access a member using DOT operator
    // malloc creates a dynamic memory block inside the Heap memory
    // Start is a Pointer (Stack) which will hold the address of DMA present in Heap

    if(start == NULL){
        start = (struct node *) malloc(sizeof(struct node)); //int *p = (int *) malloc(sizeof(int));
        start->data = item;
        start->link = NULL;
    } else {
         struct node *ptr = start;
        //This loop will not work when there is just one node
        while(ptr->link != NULL){
            ptr = ptr->link;
        }
        ptr->link = (struct node *) malloc(sizeof(struct node));
        ptr = ptr->link;
        ptr->data = item;
        ptr->link = NULL;
    }
}

void insertInBetween(){
    struct node *ptr;           // Existing Node
    struct node *nPtr;          // New node
    int xValue, nValue, flag = 0;
    ptr = start;                    // Initially pointing to first node
    printf("Enter the existing node: ");
    scanf("%d", &xValue);

    while(ptr!=NULL){
        if(ptr->data == xValue){
            nPtr = (struct node *) malloc(sizeof(struct node));
            printf("\nEnter a new value: ");
            scanf("%d",&nValue);
            nPtr->data = nValue;
            nPtr->link = ptr->link;
            ptr->link = nPtr;
            flag = 1;
            break;
        }
        ptr = ptr->link;
    }

    if(flag == 0){
        printf("\nSearch item not found");
    }

}

void display(){
    struct node *ptr;   // We created a Local Struct type Pointer variable
    ptr = start;            // Content of Start (Address of a node) is assign to ptr (so, both ptr and start is pointing to the same node)

    if(ptr==NULL){
        printf("Empty list\n");
    } else {
        while(ptr != NULL){
            printf("\nValue: %d",ptr->data);
            ptr = ptr->link;
        }
    }
}

void search(){
    struct node *ptr = start;
    int item, flag=0;
    if(ptr==NULL){
        printf("Empty list\n");
    } else {
        printf("\nEnter number to search: ");
        scanf("%d",&item);

        while(ptr != NULL){
            if(ptr->data == item){
                printf("\nSearch Found");
                flag=1;
                break;
            }
            ptr = ptr->link;
        }
        if(flag==0){
            printf("\nSearch Not Found");
        }
    }
}
