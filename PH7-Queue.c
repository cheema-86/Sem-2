#include <stdio.h>

int front = -1, rear = -1, queue[20];

void insert(){
    if (rear >= 20){
        printf("Overflow");
    } else {
        int item;
        printf("Item to insert: ");
        scanf("%d",&item);

        if (rear == -1){
            front = 0;
        }

        queue[++rear] = item;
    }
}

void delete(){
    if (front == -1){
        printf("Underflow");
    } else {
        if (rear == front){
            printf("Item %d removed.\n",queue[front]);
            front = -1;
            rear = -1;
        } else {
            printf("Item %d removed.\n",queue[front]);
            front++;
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
            for (int i = front; i<=rear; i++){
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
