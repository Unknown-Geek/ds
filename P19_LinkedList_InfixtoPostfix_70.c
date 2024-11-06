/* Ex no:19
 * Represent an arithmetic expression using a binary tree, display the expression in postfix, prefix and infix form and evaluate it.
 * 70 shravan Nander Pandala
 * 26/10/24
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

// Structure for node
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
}*root,*node;

// Global stack variables
struct Node *stack[SIZE];
int TOP = -1;

// Function to create a new node
struct Node* createNode(char data) {
    node = malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to check if character is operator
int isOperator(char c) {
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        return 1;
    else 
        return 0;
}

// Function to get precedence of operator
int precedence(char c) {
    switch (c) {
        case '^': 
            return 3;
            break;
        case '*':
            return 2;
            break;
        case '/': 
            return 2;
            break;
        case '+':
            return 1;
            break;
        case '-': 
            return 1;
            break;
        default: 
            return 0;
    }
}

// Stack Operations
int isEmpty() {
    return TOP == -1;
}

void push(struct Node *item) {
    TOP++;
    stack[TOP] = item;
}

struct Node* pop() {
    if (!isEmpty())
        return stack[TOP--];
    return NULL;
}

// Infix to Postfix 
void infixTOPostfix(char *infix, char *postfix) {
    TOP = -1;  
    int i, j = 0;
    struct Node *temp;
    
    for (i = 0; infix[i]; i++) {
        if (isdigit(infix[i])) {
            postfix[j] = infix[i];
            j++;
        }
        else if (infix[i] == '(') {
            push(createNode('('));
        }
        else if (infix[i] == ')') {
            while (!isEmpty() && stack[TOP]->data != '(') {
                temp = pop();
                postfix[j] = temp->data;
                j++;
            }
            if (!isEmpty() && stack[TOP]->data != '(')
                return; 
            else
                pop(); 
        }
        else if (isOperator(infix[i])) {
            while (!isEmpty() && precedence(infix[i]) <= precedence(stack[TOP]->data)) {
                temp = pop();
                postfix[j] = temp->data;
                j++;
            }
            push(createNode(infix[i]));
        }
    }
    
    while (!isEmpty()) {
        if (stack[TOP]->data == '(')
            return; 
        temp = pop();
        postfix[j] = temp->data;
        j++;
    }
    
    postfix[j] = '\0';
}

//Function to construct a tree
struct Node* constructTree(char *postfix) {
    TOP = -1;  
    struct Node *t, *t1, *t2;
    
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (!isOperator(postfix[i])) {
            t = createNode(postfix[i]);
            push(t);
        }
        else {
            t = createNode(postfix[i]);
            t1 = pop();
            t2 = pop();
            t->right = t1;
            t->left = t2;
            push(t);
        }
    }
    
    t = pop();
    return t;
}

//Inorder Traversal
void inorder(struct Node *root) {
    if (root) {
        if (isOperator(root->data)) printf("(");
        inorder(root->left);
        printf("%c", root->data);
        inorder(root->right);
        if (isOperator(root->data)) printf(")");
    }
}

//Preorder Traversal
void preorder(struct Node *root) {
    if (root) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//Postorder Traversal
void postorder(struct Node *root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }
}

//Function to evaluate the expression
int evaluate(struct Node *root) {
    if (root == NULL)
        return 0;
    
    if (!isOperator(root->data))
        return root->data - '0';
    
    int l_val = evaluate(root->left);
    int r_val = evaluate(root->right);
    
    switch (root->data) {
        case '+': return l_val + r_val;
        case '-': return l_val - r_val;
        case '*': return l_val * r_val;
        case '/': return l_val / r_val;
    }
    return 0;
}

//Main function
void main() {
    char infix[SIZE], postfix[SIZE];
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixTOPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    
    root = constructTree(postfix);
    
    printf("Infix expression: ");
    inorder(root);
    printf("\n");
    
    printf("Prefix expression: ");
    preorder(root);
    printf("\n");
    
    printf("Result : %d\n", evaluate(root));
}