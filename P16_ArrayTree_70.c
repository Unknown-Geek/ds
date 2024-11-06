/* Ex No:16
 * Menu driven program to create a complete binary tree using array and perform operations on it
 * 70 Shravan Nander Pandala S3 B2
 * 14/10/2024
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100

char tree[SIZE][SIZE];

void display(char tree[SIZE][SIZE],int n) {
    int count = 1;
    for(int i = 1 ; i<=n ; i++) {
        if(count == i){
            count = count * 2;
            printf("\n");
        }
        if(tree[i] != NULL)
            printf("%s\t",tree[i]);
        else {
            printf("NULL");
            printf("\t");
        }
    }
    printf("\n");
}

void display_child(char person[SIZE],int n) {
    for(int i = 1 ; i<=n ; i++) {
        if(strcmp(tree[i],person) == 0) {
            if (strcmp(tree[2*i], "") != 0)
                printf("%s\t%s",tree[2*i],tree[2*i+1]);
            else
                printf("%s has no children.",person);
        }
    }
    printf("\n");
}

char* find_father(char person[SIZE],int n) {
    static char father[SIZE];
    strcpy(father,"");
    for(int i = 1 ; i<=n ; i++) {
        if(strcmp(tree[i],person) == 0) {
            if (strcmp(tree[i / 2], "") != 0)
                strcpy(father,tree[i/2]);
            break;
        }
    }
    return father;
}

void find_grandfather(char person[SIZE], int n) {
    char father[SIZE];
    char grandfather[SIZE];
    
    strcpy(father, find_father(person, n));
    if (strcmp(father, "") != 0) {
        strcpy(grandfather, find_father(father, n));
        if (strcmp(grandfather, "") != 0)
            printf("Grandfather: %s\n", grandfather);
        else
            printf("%s has no Grandfather.\n", person);
    } else
        printf("%s has no Grandfather.\n", person);
}

void main() {
    int n,choice;
    char temp[SIZE],key[SIZE];
    printf("Enter the size of tree : ");
    scanf("%d",&n);
    printf("Enter the members in the level order : \n");
    while (getchar() != '\n');
    for(int i = 1; i<=n; i++) {
        if(i%2 == 0 && i != 1){
                printf("Enter the children of %s:\n",tree[i/2]);
        }
        gets(temp);
        if(strcasecmp(temp,"") == 0)
            tree[i][0] = '\0';
        else
            strcpy(tree[i],temp);
    }
    printf("\nMENU:");
    printf("\n1. Display the tree");
    printf("\n2. Display the children of a person");
    printf("\n3. Find the father of a person");
    printf("\n4. Find the grandfather of a person");
    printf("\n5. Exit");
    while(1) {   
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("\nThe tree is :");
                display(tree,n);
                break;
            case 2:
                printf("\nEnter the person whose children is to be displayed : ");
                scanf("%s",key);
                display_child(key,n);
                break;
            case 3:
                printf("\nEnter the person to find the father for : ");
                scanf("%s",key);
                printf("Father : %s\n",find_father(key,n));
                break;
            case 4:
                printf("\nEnter the person to find the grandfather for : ");
                scanf("%s",key);
                find_grandfather(key,n);
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
}