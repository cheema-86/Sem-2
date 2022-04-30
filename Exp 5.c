#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next; 
};

struct node *head, *newnode, *temp;

void display(){
    printf("\n---Linked List---\n\n");
    temp = head;
    while (temp != 0){ 
        printf("%d, ", temp->data); 
        temp = temp->next; 
    }
}

void insertEnd(){
    newnode = (struct node*)malloc(sizeof(struct node));
        
    printf("Enter data for new node: ");
    scanf("%d",&newnode->data); 

    newnode->next = 0; 

    if (head == 0){
        head = newnode;
        temp = newnode;
    } else {
        temp = head; 

        while(temp->next != 0){ 
            temp = temp->next; 
        }

        //insert to list
        temp->next = newnode;
        temp = newnode;
    }
}

void insert0(){
    newnode = (struct node*)malloc(sizeof(struct node)); 
        
    printf("Enter data for new node: ");
    scanf("%d",&newnode->data);

    newnode->next = head; 
    head = newnode; 
}

void delete0(){
    if (head==0){
        printf("Underflow");
    } else {
        head = head->next;
    }
}

int delete(int toFind){
    if (head==0){
        printf("Underflow");
    } else {
        if (head->data == toFind){
            delete0();
            return 0;
        }

        temp = head; 
        while (temp->next != 0 && temp->next->data != toFind){  
            temp = temp->next; 
        }

        if (temp->next != 0){
            temp->next = temp->next->next;
        } else {
            printf("Element does not exixt in the list.");
        }
    }
}


int main(){

    int run = 1, choice;
    head = 0;

    while (run){
        printf("\n\nEnter 1 to insert to beginning\n");
        printf("Enter 2 to insert to end\n");
        printf("Enter 3 to delete from beginning\n");
        printf("Enter 4 to delete specific element\n");
        printf("Enter 5 to display\n");
        printf("Enter 0 to exit\n");


        scanf("%d",&choice);

        switch (choice)
        {
        case 0:
            run = 0;
            break;

        case 1:
            insert0();
            break;
        
        case 2:
            insertEnd();
            break;

        case 3:
            delete0();
            break;

        case 4:
            int num;
            printf("Enter number to delete: ");
            scanf("%d",&num);

            delete(num);
            break;

        case 5:
            display();
            break;

        default:
            printf("Invalid input");
            break;
        }
    }

    printf("Exiting....\n");
    display();

    return 0;
}