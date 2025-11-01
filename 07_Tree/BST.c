#include <stdio.h>
#include <stdlib.h>

typedef struct BTS{
    int data;
    struct BTS *left;
    struct BTS *right;
}node;

// Create a new node
node *createNode(int val){
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert in BST
node *insert(node *current, int val){
    if (current == NULL){
        return createNode(val);
    }
    if (val < current->data)
        current->left = insert(current->left, val);
    else if (val > current->data)   // prevent duplicates
        current->right = insert(current->right, val);
    return current;
}

// Search in BST
node *search(node* current, int key){
    if(current == NULL || current->data == key)
        return current;
    if(key < current->data)
        return search(current->left, key);
    else
        return search(current->right,key);
}

// Inorder traversal
void inorder(node* current){
    if(current == NULL) return;
    inorder(current->left);
    printf("%d ", current->data);
    inorder(current->right);
}

// Find minimum
node* findMin(node* root){
    if(root == NULL) return NULL;
    while(root->left != NULL)
        root = root->left;
    return root;
}

// Find maximum
node* findMax(node* root){
    if(root == NULL) return NULL;
    while(root->right != NULL)
        root = root->right;
    return root;
}

// Delete a node in BST
node* deleteNode(node* root, int key){
    if(root == NULL)
        return NULL;

    if(key < root->data)
        root->left = deleteNode(root->left, key);
    else if(key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if(root->left == NULL){
            node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main () {
    node* root = NULL;
    node* result;
    int choice, val, key;

    while(1){
        printf("\n--- BST MENU ---\n");
        printf("1. Insert node\n");
        printf("2. Search node\n");
        printf("3. Inorder traversal\n");
        printf("4. Find Minimum\n");
        printf("5. Find Maximum\n");
        printf("6. Delete node\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("%d inserted successfully.\n", val);
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &key);
                result = search(root, key);
                if(result != NULL)
                    printf("%d found in BST.\n", key);
                else
                    printf("%d not found in BST.\n", key);
                break;
            case 3:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                result = findMin(root);
                if(result != NULL)
                    printf("Minimum value in BST: %d\n", result->data);
                else
                    printf("BST is empty.\n");
                break;
            case 5:
                result = findMax(root);
                if(result != NULL)
                    printf("Maximum value in BST: %d\n", result->data);
                else
                    printf("BST is empty.\n");
                break;
            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                printf("%d deleted (if it existed) from BST.\n", val);
                break;
            case 7:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}