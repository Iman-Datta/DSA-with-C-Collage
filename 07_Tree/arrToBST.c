# include <stdio.h>
# include <stdlib.h>

typedef struct BST{
    int data;
    struct BST *right, *left;
} node;

node *creatNode(int val){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

node *arrToBST(int arr[], int low, int high){
    if (low > high) return NULL;
    int mid = low + (high - low)/2;

    node *root = creatNode(arr[mid]);
    root->left = arrToBST(arr,low,mid-1);
    root->right = arrToBST(arr,mid+1,high);
    return root;
}

void inOrder(node *root){
    if (root == NULL){
        return;
    }

    inOrder(root->left);
    printf("%d \t", root->data);
    inOrder(root->right);
}

int main(){
    int arr[] = {1,2,4,7,11,31,43,55};
    int sz = sizeof(arr)/sizeof(arr[0]);
    
    node *root = arrToBST(arr, 0, sz-1);

    printf("Inorder Traversal of Balanced BST:\n");
    inOrder(root);
    return 0;
}
