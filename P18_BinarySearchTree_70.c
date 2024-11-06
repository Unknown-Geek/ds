/* Ex no:18
 * Program to implement a binary search tree using linked list : Insertion,Deletion,Search,Display contents
 * 70 shravan Nander Pandala
 * 24/10/24
 */
 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}*temp,*newNode,*current;

// Function to create a new node
struct Node* createNode(int value) {
    newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node
struct Node* insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// Function to find minimum value node in a tree
struct Node* minValueNode(struct Node *node) {
    current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node
struct Node* deleteNode(struct Node *root, int value) {
    if (root == NULL) {
        return root;
    }
    
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        //Only one child
        if (root->left == NULL) {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            temp = root->left;
            free(root);
            return temp;
        }
        
        // If two children
        temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to search for a value
struct Node* search(struct Node *root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    
    if (value < root->data) {
        return search(root->left, value);
    }
    
    return search(root->right, value);
}

// Function to display tree in ascending order (inorder traversal)
void display(struct Node *root) {
    if (root != NULL) {
        display(root->left);
        printf("%d ", root->data);
        display(root->right);
    }
}

void main() {
    struct Node *root = NULL;
    int choice, value;
    printf("\nMENU:\n1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");
    while (1) {
        printf("\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;
                
            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                if (search(root, value) == NULL) 
                    printf("%d not found", value);
                else 
                    root = deleteNode(root, value);
                break;
                
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value) != NULL) {
                    printf("%d found\n", value);
                } else {
                    printf("%d not found\n", value);
                }
                break;
                
            case 4:
                printf("Tree contents in ascending order: ");
                display(root);
                printf("\n");
                break;
                
            case 5:
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice!\n");
        }
    }
}