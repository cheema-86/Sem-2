#include <stdio.h>
#include <stdlib.h>

int main(){
    struct node{
        int data;
        struct node* next;
    };

    int run = 1;
    struct node *head, *newnode, *temp;

    head = 0;

    while (run){
        newnode = (struct node*)malloc(sizeof(struct node)); //(datatype)malloc(amount of memory);
        
        printf("Enter data for new node:");
        scanf("%d",&newnode->data);

        newnode->next = 0;

        if (head == 0){
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Enter 1 for more items, 0 to exit");
        scanf("%d",&run);
    }

    temp = head;
    while (temp != 0){
        printf("%d, ", temp->data);
        temp = temp->next;
    }

    return 0;
}