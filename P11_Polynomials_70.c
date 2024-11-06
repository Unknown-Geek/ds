/* Ex No:11
 * Menu driven program to find the sum and product of two polynomials using a Linked List
 * 70 Shravan Nander Pandala S3 B2
 * 05/09/2024
 */

#include <stdio.h>
#include <stdlib.h>

//Structure for linked list
struct Term {
	int c,d;
	struct Term *next;
} *temp,*current,*poly1,*poly2,*sum_list,*product_list,*result;

//Function Prototypes
void display(struct Term *head);
void insert_term(struct Term *head,int c,int d);
void sum(struct Term *p1,struct Term *p2);
void product(struct Term *p1,struct Term *p2);

//Main Function
void main() {
	int n1,n2,coeff,deg;
	poly1 = malloc(sizeof(struct Term));
	poly2 = malloc(sizeof(struct Term));
	poly1->next = NULL;
	poly2->next = NULL;

	printf("Enter the number of terms in polynomial 1 : ");
	scanf("%d",&n1);
	printf("\n");
	printf("Enter the number of terms in polynomial 2 : ");
	scanf("%d",&n2);
	printf("\n");
	printf("Enter the terms of polynomial 1 coefficent and degree wise : \n");
	for(int i=0 ; i<n1 ; i++){
		scanf("%d%d",&coeff,&deg);
		insert_term(poly1,coeff,deg);
	}
	printf("Enter the terms of polynomial 2 coefficent and degree wise : \n");
	for(int j=0 ; j<n2 ; j++){
		scanf("%d%d",&coeff,&deg);
		insert_term(poly2,coeff,deg);
	}
	printf("Polynomial 1 : ");
	display(poly1);
	printf("\n");
	printf("Polynomial 2 : ");
	display(poly2);
	printf("\n");
	sum(poly1,poly2);
	product(poly1,poly2);
}

//Function to display the polynomial
void display(struct Term *head){
	if(head->next == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	current = head->next;
	while(current != NULL){
		if(current->d == 0 )
			printf("%d",current->c);
		else if (current->c == 1)
			printf("x^%d",current->d);
		else
			printf("%dx^%d",current->c,current->d);

		if(current->next != NULL)
			printf(" + ");
		current = current->next;
	}
	printf("\n");
}

//Function to insert a term
void insert_term(struct Term *head,int c,int d) {
	temp = malloc(sizeof(struct Term));
	temp->c = c;
	temp->d = d;
	temp->next == NULL;
	if(head->next == NULL){
		temp->next = head->next;
		head->next = temp;
		return;
	}
	current = head->next;
	while(current->next != NULL)
		current = current->next;
	current->next = temp;
}

void sum(struct Term *p1,struct Term *p2) {
	int c,d;
	struct Term *cursor1,*cursor2;
	sum_list = malloc(sizeof(struct Term));
	sum_list->next = NULL;
	cursor1 = p1->next;
	cursor2 = p2->next;
	while(cursor1!=NULL && cursor2!=NULL) {
		if (cursor1->d > cursor2->d) {
			d = cursor1->d;
			c = cursor1->c;
			cursor1 = cursor1->next;
		}
		else if (cursor1->d < cursor2->d) {
			d = cursor2->d;
			c = cursor2->c;
			cursor2 = cursor2->next;
		}
		else {
			d = cursor1->d;
			c = cursor1->c + cursor2->c;
			cursor1 = cursor1->next;
			cursor2 = cursor2->next;
		}
		insert_term(sum_list,c,d);
	}
	while(cursor1!=NULL) {
		insert_term(sum_list,cursor1->c,cursor1->d);
		cursor1 = cursor1->next;
	}
	while(cursor2!=NULL) {
		insert_term(sum_list,cursor2->c,cursor2->d);
		cursor2 = cursor2->next;
	}
	printf("Sum of polynomials is : ");
	display(sum_list);
}

//Fuction to find the product
void product(struct Term *p1,struct Term *p2) {
	int c,d;
	struct Term *temp,*prev,*cursor1,*cursor2,*cursor3;
	product_list = malloc(sizeof(struct Term));
	product_list->next = NULL;

	cursor1 = p1->next;
	while (cursor1 != NULL) {
        cursor2 = p2->next;
        while (cursor2 != NULL) {
            c = cursor1->c * cursor2->c;
            d = cursor1->d + cursor2->d;
            cursor3 = product_list->next;
 			prev = product_list;
            while (cursor3 != NULL && cursor3->d > d) {
                prev = cursor3;
                cursor3 = cursor3->next;
            }
            if (cursor3 != NULL && cursor3->d == d)
                cursor3->c += c;
            else {
                temp = malloc(sizeof(struct Term));
                temp->c = c;
                temp->d = d;
                temp->next = cursor3;
                prev->next = temp;
            }    
            cursor2 = cursor2->next;
        }
        cursor1 = cursor1->next;
    }
	printf("Product of polynomials is : ");
	display (product_list);
}