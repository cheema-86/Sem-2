#include <stdio.h>

int front = -1, rear = -1, queue[8];

void insert(){
    if ((rear + 1 == front) || (front==0 && rear==8)){
        printf("Overflow");
    } else {
        int item;
        printf("Item to insert: ");
        scanf("%d",&item);

        if (front==-1 || rear == -1){
            front = 0;
            rear = 0;
        } else if (++rear > 8){
            rear = 0;
        }

        queue[rear] = item;
    }
}

void delete(){
    if (front == -1){
        printf("Underflow");
    } else {
        printf("Item %d removed.\n",queue[front]);
        queue[front] = 0;
        if (rear == front){
            front = -1;
            rear = -1;
        } else if (++front > 8){
            front=0;
        }
    }
}


int main()
{
    int choice = 1;

    while (choice){
        printf("\n\nEnter 1 to queue\n");
        printf("Enter 2 to dequeue\n");
        printf("Enter 3 to display\n");
        printf("Enter 0 to exit\n");

        scanf("%d",&choice);

        switch (choice){
        case 1:
            insert();
            break;
        
        case 2:
            delete();
            break;

        case 3:
            printf("Queue: ");
            for (int i = 0; i<=8; i++){
                printf("%d ",queue[i]);
            }
            printf("\n");
            break;

        default:
            break;
        }

    }



    return 0;
}
