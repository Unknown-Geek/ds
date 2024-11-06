/* Ex No:13
 * Menu driven program to implement queue using a Linked List
 * 70 Shravan Nander Pandala S3 B2
 * 06/10/2024
 */

#include <stdio.h>
#include <stdlib.h>

//Structure for linked list
struct Node {
    int data;
    struct Node *next;
};

//Function Prototypes
void display(struct Node *head);
void enqueue(struct Node *head,int data);
void dequeue(struct Node *head);

//Main Function
void main(){
    int ch,running = 1;
    int data;
    // Properly initialize the queue header node
    struct Node *queue = malloc(sizeof(struct Node));
    if (queue == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    queue->next = NULL;

    printf("\nMENU\n");
    printf("1.Display contents\n2.Enqueue\n3.Dequeue\n4.Exit\n");
    while(running){
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                display(queue);
                break;

            case 2:
                printf("Enter the data : ");
                scanf("%d",&data);
                enqueue(queue,data);
                break;

            case 3:
                dequeue(queue);
                break;

            case 4 :
                exit(0);

            default:
                printf("Invalid Choice\n");
                break;
        }
        if (ch == 4)
            break;
    }
}

//Function to display the nodes
void display(struct Node *head){
    struct Node *current;  // Declare current locally
    if(head->next == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("The elements of queue are : \n");
    current = head->next;
    while(current != NULL){
        printf("%d\t",current->data);
        current = current->next;
    }
    printf("\n");
}

//Function to insert at end
void enqueue(struct Node *head,int data) {
    struct Node *temp = malloc(sizeof(struct Node));  // Declare temp locally
    struct Node *current;  // Declare current locally
    temp->data = data;
    temp->next = NULL;
    if(head->next == NULL){
        head->next = temp;
        printf("Element inserted\n");
        return;
    }
    current = head->next;
    while(current->next != NULL)
        current = current->next;
    current->next = temp;
    printf("Element inserted\n");
}

//Function to delete the node at beginning
void dequeue(struct Node *head){
    struct Node *temp;  // Declare temp locally
    int num;
    if(head->next == NULL) {
        printf("Queue is empty\n");
        return;
    }
    temp = head->next;
    num = temp->data;
    head->next = head->next->next;
    free(temp);
    printf("Element dequeued : %d\n",num);
}
