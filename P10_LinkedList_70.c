/* Ex No:10
 * Menu driven program to perform operations on a Linked List
 * 70 Shravan Nander Pandala S3 B2
 * 05/09/2024
 */

#include <stdio.h>
#include <stdlib.h>

//Structure for linked list
struct Node {
	int data;
	struct Node *next;
} *temp,*head, *current;

//Function Prototypes
void display(struct Node *head);
void insert_beginning(struct Node *head,int data);
void insert_end(struct Node *head,int data);
void insert_after_Node(struct Node *head, int data, int afterNode);
void delete_beginning(struct Node *head);
void delete_end(struct Node *head);
void delete_Node(struct Node *head,int key);

//Main Function
void main(){
	int ch,running = 1;
	int data,key;
	struct Node *list;
	list->data = NULL;
	list->next = NULL;

	printf("\nMENU\n");
	printf("1.Display contents\n2.Insert at beginning\n3.Insert at end\n4.Insert after a given node\n");
	printf("5.Delete from beginning\n6.Delete from end\n7.Delete node with a key value\n8.Exit\n");
	while(running){
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				display(list);
				break;

			case 2:
				printf("Enter the data : ");
				scanf("%d",&data);
				insert_beginning(list,data);
				break;

			case 3:
				printf("Enter the data : ");
				scanf("%d",&data);
				insert_end(list,data);
				break;

			case 4:
				printf("Enter the data : ");
				scanf("%d",&data);
				printf("Enter the after node value : ");
				scanf("%d",&key);
				insert_after_Node(list,data,key);
				break;

			case 5:
				delete_beginning(list);
				break;

			case 6:
				delete_end(list);
				break;

			case 7:
				printf("Enter the key value : ");
				scanf("%d",&key);
				delete_Node(list,key);
				break;

			case 8 :
				exit(0);

			default:
				printf("invalid Choice\n");
				break;
		}
		if (ch == 8)
			break;
	}
}

//Function to display the nodes
void display(struct Node *head){
	if(head->next == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	printf("The elements of linked list are : \n");
	current = head->next;
	while(current != NULL){
		printf("%d\t",current->data);
		current = current->next;
	}
	printf("\n");
}

//Function to insert at beginning
void insert_beginning(struct Node *head,int data){
	temp = malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = head->next;
	head->next = temp;
	printf("Element inserted at beginning\n");
}

//Function to insert at end
void insert_end(struct Node *head,int data) {
	temp = malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	if(head->next == NULL){
		temp->next = head->next;
		head->next = temp;
		return;
	}
	current = head->next;
	while(current->next != NULL)
		current = current->next;
	current->next = temp;
	printf("Element inserted at end\n");
}

//Function to insert after a given value
void insert_after_Node(struct Node *head, int data, int afterNode){
	temp = malloc(sizeof(struct Node));
	temp->data = data;
	if(head->next == NULL){
		temp->next = head->next;
		head->next = temp;
		return;
	}
	current = head->next;
	while(current->next != NULL){
		if(current->data == afterNode){
			temp->next = current->next;
			current->next = temp;
		}
		current = current->next;
	}
	printf("Element inserted after %d\n",afterNode);
}

//Function to delete the node at beginning
void delete_beginning(struct Node *head){
	if(head->next == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	temp = head->next;
	head->next = head->next->next;
	free(temp);
	printf("Element deleted from beginning\n");
}

//Function to delete the node at the end
void delete_end(struct Node *head){
	if(head->next == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	if(head->next->next == NULL) {
		temp = head->next;
		head->next = NULL;
		free(temp);
		return;
	}
	current = head->next;
	while(current->next->next != NULL)
		current = current->next;
	free(current->next);
	current->next = NULL;
	printf("Element deleted from end\n");
}

//Function to delete the node with a given key
void delete_Node(struct Node *head,int key){
	if(head->next == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	if(head->next->data == key) {
		temp = head->next;
		head->next = head->next->next;
		free(temp);
		return;
	}
	current = head->next;
	while(current->next != NULL){
		if(current->next->data == key){
			temp = current->next;
			current->next = current->next->next;
			free(temp);
		}
		current = current->next;
	}
	printf("Element %d deleted\n",key);
}

