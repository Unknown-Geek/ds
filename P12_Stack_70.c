/* Ex No:12
 * Menu driven program to implement stack using a Linked List
 * 70 Shravan Nander Pandala S3 B2
 * 06/10/2024
 */

#include <stdio.h>
#include <stdlib.h>

//Structure for linked list
struct Node {
	int data;
	struct Node *next;
} *temp,*head,*current;

//Function Prototypes
void display(struct Node *head);
void push(struct Node *head,int data);
void pop(struct Node *head);

//Main Function
void main(){
	int ch,running = 1;
	int data,key;
	struct Node *stack;
	stack->next = NULL;

	printf("\nMENU\n");
	printf("1.Display contents\n2.Push\n3.Pop\n4.Exit\n");
	while(running){
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				display(stack);
				break;

			case 2:
				printf("Enter the data : ");
				scanf("%d",&data);
				push(stack,data);
				break;

			case 3:
				pop(stack);
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
	if(head->next == NULL) {
		printf("Stack is empty\n");
		return;
	}
	printf("The elements of stack are : \n");
	current = head->next;
	while(current != NULL){
		printf("%d\t",current->data);
		current = current->next;
	}
	printf("\n");
}

//Function to insert at beginning
void push(struct Node *head,int data){
	temp = malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
	printf("Element pushed to stack\n");
}

//Function to delete the node at beginning
void pop(struct Node *head){
	int num;
	if(head->next == NULL) {
		printf("Stack is empty\n");
		return;
	}
	temp = head->next;
	num = temp->data;
	head->next = head->next->next;
	free(temp);
	printf("Element popped : %d\n",num);
}
