#include <stdio.h>
#include <stdlib.h>

//New data structure
struct node{
    int data; //Actual data
    struct node* next; //Pointing to the next node
};

//Variables
struct node *head, *newnode, *temp;

//Function to display the stack
void display(){
    printf("\n--- Stack ---\n\n");
    temp = head; //Starting from first index
    while (temp != 0){ //Check if node is empty
        printf("%d, ", temp->data); 
        temp = temp->next; //Go to next node
    }
}


//Function to push to stack
void push(){
    newnode = (struct node*)malloc(sizeof(struct node)); //Setup memory for new node
        
    printf("Enter data for new node: ");
    scanf("%d",&newnode->data); //Insert data to new node

    newnode->next = head; //Put current first node as next one from it
    head = newnode; //Put new node in first place
    printf("Added to stack");
}

//Function to pop from stack
void pop(){
    if (head==0){
        printf("Stack Underflow");
    } else {
        printf("%d removed from stack",head->data);
        head = head->next;
    }
}


int main(){

    int run = 1, choice;
    head = 0;

    while (run){
        printf("\n\nEnter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 5 to display\n");
        printf("Enter 0 to exit\n");


        scanf("%d",&choice);

        switch (choice)
        {
        case 0:
            run = 0;
            break;

        case 1:
            push();
            break;

        case 2:
            pop();
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