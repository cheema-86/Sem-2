#include <stdio.h>

int stack[8], top = 0;

void push(){
    int item;
    if (top >= 8){
        printf("STACK OVERFLOW");
    } else {
        printf("Enter value: ");
        scanf("%d",&item);

        stack[top] = item;
        top++;
    }
}

void pop(){
    int item;
    if (top < 0){
        printf("STACK UNDERFLOW");
    } else {
        printf("Item %d removed",stack[top--]);
    }
}

void display(){
    printf("__Stack__\n");
    for (int i = top-1; i>=0; i--){
        printf("%d ",stack[i]);
    }
}

int main(){
    int run = 1, choice;
    while(run){
        printf("\n\nEnter 1 to push\n");
        printf("Enter 2 to pop\n");
        printf("Enter 3 to display\n");
        printf("Enter 0 to exit\n");
        
        scanf("%d",&choice);

        switch (choice){
        case 0:
            run = 0;
            break;
        
        case 1:
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        default:
            break;
        }
    }

    return 0;
}