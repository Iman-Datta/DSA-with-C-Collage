# include <stdio.h>
# include <stdlib.h>

typedef struct BTS{
    int data;
    struct BTS *left;
    struct BTS *right;
}node;

node *createNode(int val){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node *insert(node *current, int val){
    if (current == NULL){
        return createNode(val);
    }
    if (val < current->data){
        current->left = insert(current->left, val);
    }
    else
        current->right = insert(current->right, val);
    return current;
}

node *search(node* current, int key){
    if(current == NULL){
        return current;
    }
    if(key < current->data){
        return search(current->left, key);
    }
    else if(key == current->data)
        return current;
    else
        return search(current->right,key);
}

int main () {
    node* root = NULL;
    node* result;

    int n, val, key;
    printf("Enter no. of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(int i = 0; i < n; i++){
        scanf("%d", &val);
        root = insert(root,val);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    result = search(root, key);

    if (result != NULL)
        printf("%d found in BST", key);
    else
        printf("%d not found in BST", key);

    return 0;
}