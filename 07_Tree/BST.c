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
void inorder(node* current){ // Left -> Root -> Right
    if(current == NULL) return;
    inorder(current->left);
    printf("%d ", current->data);
    inorder(current->right);
}

// Preorder traversal
void preorder(node* current){ // Root -> Left -> Right
    if(current == NULL) return;
    printf("%d ", current->data);
    preorder(current->left);
    preorder(current->right);
}

// Postorder traversal
void postorder(node* current){ //Left → Right → Root
    if(current == NULL) return;
    postorder(current->left);
    postorder(current->right);
    printf("%d ", current->data);
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

// Find Lowest Common Ancestor (LCA) in BST
node* findLCA(node* root, int n1, int n2) {
    if(root == NULL) return NULL;

    if(n1 < root->data && n2 < root->data)
        return findLCA(root->left, n1, n2);

    if(n1 > root->data && n2 > root->data)
        return findLCA(root->right, n1, n2);

    return root;  // split point, root is LCA
}

// Main function with menu
int main () {
    node* root = NULL;
    node* result;
    node* lca;
    int choice, val, key, n1, n2;

    while(1){
        printf("\n--- BST MENU ---\n");
        printf("1. Insert node\n");
        printf("2. Search node\n");
        printf("3. Inorder traversal\n");
        printf("4. Preorder traversal\n");
        printf("5. Postorder traversal\n");
        printf("6. Find Minimum\n");
        printf("7. Find Maximum\n");
        printf("8. Delete node\n");
        printf("9. Find LCA of two nodes\n");
        printf("10. Exit\n");
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
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 5:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 6:
                result = findMin(root);
                if(result != NULL)
                    printf("Minimum value in BST: %d\n", result->data);
                else
                    printf("BST is empty.\n");
                break;

            case 7:
                result = findMax(root);
                if(result != NULL)
                    printf("Maximum value in BST: %d\n", result->data);
                else
                    printf("BST is empty.\n");
                break;

            case 8:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = deleteNode(root, val);
                printf("%d deleted (if it existed) from BST.\n", val);
                break;

            case 9:
                printf("Enter two node values to find LCA: ");
                scanf("%d %d", &n1, &n2);
                lca = findLCA(root, n1, n2);
                if(lca != NULL)
                    printf("LCA of %d and %d is %d\n", n1, n2, lca->data);
                else
                    printf("LCA not found (one or both nodes may be missing).\n");
                break;

            case 10:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
