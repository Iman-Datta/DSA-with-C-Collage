#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Recursive function to create a binary tree
Node* createBinaryTree() {
    int val;
    printf("Enter node value (-1 for NULL): ");
    scanf("%d", &val);

    if(val == -1) return NULL;

    Node* root = createNode(val);

    printf("Enter left child of %d:\n", val);
    root->left = createBinaryTree();

    printf("Enter right child of %d:\n", val);
    root->right = createBinaryTree();

    return root;
}

// Traversals
void preorder(Node* root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Height of binary tree
int height(Node* root) {
    if(root == NULL) return 0;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Count leaf nodes
int countLeafNodes(Node* root) {
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Main menu
int main() {
    Node* root = NULL;
    int choice;

    while(1) {
        printf("\n--- Binary Tree Menu ---\n");
        printf("1. Create tree\n");
        printf("2. Preorder traversal\n");
        printf("3. Inorder traversal\n");
        printf("4. Postorder traversal\n");
        printf("5. Find height\n");
        printf("6. Count leaf nodes\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                root = createBinaryTree();
                printf("Binary tree created successfully.\n");
                break;
            case 2:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;
            case 3:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;
            case 4:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("Height of binary tree: %d\n", height(root));
                break;
            case 6:
                printf("Number of leaf nodes: %d\n", countLeafNodes(root));
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
