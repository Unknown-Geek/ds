/* Ex No:15
 * Menu driven program to perform operations on a Doubly Linked List
 * 70 Shravan Nander Pandala S3 B2
 * 14/10/2024
 */

#include <stdio.h>
#include <stdlib.h>

//Structure for node
struct Node {
	int data;
	struct Node *next;
	struct Node *prev;
} *temp,*current;

//Structure for doubly linked list
struct List {
	struct Node *head;
	struct Node *tail;
} *list;

//Function Prototypes
void display_beginning(struct Node *head);
void display_end(struct Node *tail);
void insert_beginning(struct Node *head,int data);
void insert_end(struct Node *head,struct Node *tail,int data);
void insert_after_Node(struct Node *head, int data, int afterNode);
void delete_beginning(struct Node *head);
void delete_end(struct Node *tail);
void delete_Node(struct Node *head,struct Node *tail,int key);

//Main Function
void main(){
	int ch,running = 1;
	int data,key;
	list = malloc(sizeof(struct List));
	list->head = NULL;
	list->tail = NULL;

	printf("\nMENU\n");
	printf("1.Insert at beginning\n2.Insert at end\n3.Insert after a given node\n");
	printf("4.Delete from beginning\n5.Delete from end\n6.Delete node with a key value\n7.Display contents from beginning\n8.Display contents from end\n9.Exit\n");
	while(running){
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch) {
			case 1:
				printf("Enter the data : ");
				scanf("%d",&data);
				insert_beginning(list->head,data);
				break;

			case 2:
				printf("Enter the data : ");
				scanf("%d",&data);
				insert_end(list->head,list->tail,data);
				break;

			case 3:
				printf("Enter the data : ");
				scanf("%d",&data);
				printf("Enter the after node value : ");
				scanf("%d",&key);
				insert_after_Node(list->head,data,key);
				break;

			case 4:
				delete_beginning(list->head);
				break;

			case 5:
				delete_end(list->tail);
				break;

			case 6:
				printf("Enter the key value : ");
				scanf("%d",&key);
				delete_Node(list->head,list->tail,key);
				break;

			case 7:
				display_beginning(list->head);
				break;

			case 8:
				display_end(list->tail);
				break;

			case 9 :
				exit(0);

			default:
				printf("invalid Choice\n");
				break;
		}
	}
}

//Function to display the nodes from beginning
void display_beginning(struct Node *head){
	if(head == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	printf("The elements of linked list from beginning are : \n");
	current = head;
	while(current != NULL){
		printf("%d\t",current->data);
		current = current->next;
	}
	printf("\n");
}

//Function to display the nodes from end
void display_end(struct Node *tail){
	if(tail == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	printf("The elements of linked list from end are : \n");
	current = tail;
	while(current != NULL){
		printf("%d\t",current->data);
		current = current->prev;
	}
	printf("\n");
}

//Function to insert at beginning
void insert_beginning(struct Node *head,int data){
	temp = malloc(sizeof(struct Node));
	temp->data = data;
    temp->prev = NULL;
    temp->next = head;
    if(head!=NULL)
        head->prev = temp;
    list->head = temp;
    if(list->tail == NULL)
        list->tail = temp;
	printf("Element inserted at beginning\n");
}

//Function to insert at end
void insert_end(struct Node *head,struct Node *tail,int data) {
	temp = malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	if(tail == NULL){
	    temp->prev = NULL;
		list->head = temp;
        list->tail = temp;
		return;
	}
	temp->prev = tail;
	tail->next = temp;
	list->tail = temp;
	printf("Element inserted at end\n");
}

//Function to insert after a given value
void insert_after_Node(struct Node *head, int data, int afterNode){
	temp = malloc(sizeof(struct Node));
	temp->data = data;
	temp->next = NULL;
	temp->prev = NULL;
	if(head == NULL){
		list->head = temp;
		list->tail = temp;
		return;
	}
	current = head;
	while(current != NULL){
		if(current->data == afterNode){
			temp->next = current->next;
			temp->prev = current;
			if(current->next != NULL)
			    current->next->prev = temp;
			else
			    list->tail = temp;
			current->next = temp;
			break;
		}
		current = current->next;
	}
	printf("Element inserted after %d\n",afterNode);
}

//Function to delete the node at beginning
void delete_beginning(struct Node *head){
	if(head == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	temp = head;
	list->head = head->next;
	if(list->head == NULL)
	    list->tail = NULL;
	else
	    list->head->prev = NULL;
	free(temp);
	printf("Element deleted from beginning\n");
}

//Function to delete the node at the end
void delete_end(struct Node *tail){
	if(tail == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	if(tail->prev == NULL) {
		temp = tail;
		list->tail = NULL;
		list->head = NULL;
		free(temp);
		return;
	}
	temp = tail;
	list->tail = tail->prev;
	list->tail->next = NULL;
	free(temp);
	printf("Element deleted from end\n");
}

//Function to delete the node with a given key
void delete_Node(struct Node *head,struct Node *tail,int key){
    int flag = 0;
	if(head == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	current = head;
	while(current != NULL){
		if(current->data == key){
		    flag = 1;
		    if(current->prev == NULL)
		        list->head = current->next;
		    else
		        current->prev->next= current->next;
		    if(current->next == NULL)
		        list->tail = current->prev;
		    else
		        current->next->prev = current->prev;
		    break;
	    }
	    current = current->next;
	}
	if (flag!=0) {
	    free(current);
	    printf("Element %d deleted\n",key);
	}
    else
        printf("Element %d not found\n",key);
}

