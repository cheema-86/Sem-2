#include <stdio.h>
#include <stdlib.h>

//New data structure
struct node{
    int data; //Actual data
    struct node* next; //Pointing to the next node
};

//Variables
struct node *head, *newnode, *temp;

//Function to display the list
void display(){
    printf("\n---Linked List---\n\n");
    temp = head; //Starting from first index
    while (temp != 0){ //Check if node is empty
        printf("%d, ", temp->data); 
        temp = temp->next; //Go to next node
    }
}

//Function to insert at the end of the list
void insertEnd(){
    newnode = (struct node*)malloc(sizeof(struct node)); //Setup memory for new node
        
    printf("Enter data for new node: ");
    scanf("%d",&newnode->data); //Insert data to new node

    newnode->next = 0; //Signify that this is last node

    if (head == 0){
        head = newnode;
        temp = newnode;
    } else {
        //Start traversing through the list to the end
        temp = head; //start from first index

        while(temp->next != 0){ //check if node is empty
            temp = temp->next; //goto next node
        }

        //insert to list
        temp->next = newnode;
        temp = newnode;
    }
}

//Function to insert at the beginning of the list
void insert0(){
    newnode = (struct node*)malloc(sizeof(struct node)); //Setup memory for new node
        
    printf("Enter data for new node: ");
    scanf("%d",&newnode->data); //Insert data to new node

    newnode->next = head; //Put current first node as next one from it
    head = newnode; //Put new node in first place
}

//Function to delete first element
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
        //Start traversing through the list to the end
        if (head->data == toFind){
            delete0();
            return 0;
        }

        temp = head; //Starting from first index
        while (temp->next != 0 && temp->next->data != toFind){  
            temp = temp->next; //Go to next node
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