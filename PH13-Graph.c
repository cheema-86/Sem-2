#include <stdio.h>
#include <stdlib.h>

struct node{
    int data; 
    struct node* next; 
};

struct node *newnode;

struct node * insert(struct node *head){
    newnode = (struct node*)malloc(sizeof(struct node));
        
    printf("Enter neighbour: ");
    scanf("%d",&newnode->data);

    newnode->next = head; 
    head = newnode; 
    return head;
}

void display(struct node *temp, int i){
    printf("\nNeighbours of %d: ",i+1);
    while (temp != 0){
        printf("%d ", temp->data); 
        if(temp->next == NULL){break;}
        temp = temp->next;
    }
}

int main(){
    int i, j, items, neighbours;

    printf("Enter number of nodes: ");
    scanf("%d",&items);

    struct node *nodeList[items], *head;

    for(i = 0; i<items; i++){
        nodeList[i] = NULL;
        printf("Enter number of neighbours for %d: ",i+1);
        scanf("%d",&neighbours);

        for(j = 0; j<neighbours; j++){
            nodeList[i] = insert(nodeList[i]);
        }
    }

    printf("\n\n\n--Graph--\n");
    for(i = 0; i<items; i++){
        display(nodeList[i], i);
    }

    return 0;
}

// 5 3 4 3 2 2 4 1 2 4 1 4 5 3 2 1 1 4