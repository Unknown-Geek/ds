/* Ex No:14
 * Program to input to numbers as strings, convert them to linked lists, reverse the lists and finding the sum of the numbers.
 * 70 Shravan Nander Pandala S3 B2
 * 11/10/2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

struct Node {
    int val;
    struct Node *next;
} *temp, *cursor, *cursor2;

struct List {
    struct Node *head;
} *num1, *num2, *rev1, *rev2, *sum;

//Fucntio to create list head
struct Node* create_head() {
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    head->val = 0;
    head->next = NULL;
    return head;
}

//Function to insert node at beginning of a list
struct Node* insert_beginning(struct Node *head, int val) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->val = val;
    if(head->next == NULL)
        head->next = temp;
    else {
        temp->next = head->next;
        head->next = temp;
        return head;
    }
}

//Fucntion to insert node at the end of a list
struct Node* insert_end(struct Node *head, int val) {
    struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
    temp->val = val;
    temp->next = NULL;
    if (head->next == NULL)  
        head->next = temp;
    else {
        cursor = head;
        while(cursor->next != NULL) { 
            cursor = cursor->next;
        }
        cursor->next = temp;
    }
    return head;
}

//Function to display contents of a list
void display(struct Node *head) {
    if (head->next == NULL)
        printf("List empty\n");
    else {
        cursor = head->next;
        while (cursor != NULL) {
            printf("%d", cursor->val);
            if (cursor->next != NULL)
                printf("->");
            cursor = cursor->next;
        }
        printf("\n");
    }
}

//Main function
int main() {
    int carry = 0;
    int add;
    char n1[SIZE], n2[SIZE];
    printf("Enter first number: ");
    scanf("%s", n1);
    printf("Enter second number: ");
    scanf("%s", n2);

    num1 = (struct List*) malloc(sizeof(struct List));
    num2 = (struct List*) malloc(sizeof(struct List));
    rev1 = (struct List*) malloc(sizeof(struct List));
    rev2 = (struct List*) malloc(sizeof(struct List));
    sum = (struct List*) malloc(sizeof(struct List));
    num1->head = create_head();
    num2->head = create_head();
    rev1->head = create_head();
    rev2->head = create_head();
    sum->head = create_head();
    
    //converting input numbers to lists
    for (int i = 0; i < strlen(n1); i++) 
        num1->head = insert_end(num1->head, n1[i] - '0'); 
    
    for (int j = 0; j < strlen(n2); j++)
        num2->head = insert_end(num2->head, n2[j] - '0'); 
    printf("Entered numbers as list : \n");
    display(num1->head);
    display(num2->head);
    printf("\n");
    //reversing the lists
    for (int i = 0; i < strlen(n1); i++) 
        rev1->head = insert_beginning(rev1->head, n1[i] - '0'); 
    
    for (int j = 0; j < strlen(n2); j++)
        rev2->head = insert_beginning(rev2->head, n2[j] - '0'); 
    
    //adding the lists
    cursor = rev1->head->next;
    cursor2 = rev2->head->next;
    while(cursor != NULL && cursor2 != NULL) {
        add = cursor->val + cursor2->val+carry;
        carry = add/10;
        add = add%10;
        sum->head = insert_beginning(sum->head,add);
        cursor = cursor->next;
        cursor2 = cursor2->next;
    }
    //Adding remaining digits
    while(cursor != NULL) {
        sum->head = insert_beginning(sum->head,cursor->val);
        cursor = cursor->next;
    }
    while(cursor2 != NULL) {
        sum->head = insert_beginning(sum->head,cursor2->val);
        cursor2 = cursor2->next;
    }
    printf("Sum : ");
    display(sum->head);
    return 0;
}