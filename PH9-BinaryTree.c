#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node * left;
    int data;
    struct node * right;
};

struct node * create(){
    //getting data value for node
    int item;

    printf("Enter data: ");
    scanf("%d", &item);

    if (item == -1){
        return 0;
    }
    //end obtaining data

    //defining new node
    struct node * newnode;
    newnode = (struct node *)malloc(sizeof(struct node *));

    newnode->data = item;

    //entering data into left child of the node
    printf("Editing left child of %d:\n",item);
    newnode->left = create(); 


    //entering data into right child of the node
    printf("Editing right child of %d:\n",item);
    newnode->right = create();

    //return the address of the node to the previous node
    return newnode; 
}

void display(struct node * item){
    printf("Children of %d: ", item->data);
    if (item->left != 0){
        printf("%d ", item->left->data);
    }

    if (item->right != 0){
        printf("& %d", item->right->data);
    }

    printf("\n\n");

    if (item->left != 0){
        display(item->left);
    }

    if (item->right != 0){
        display(item->right);
    }

}

int main(){
    struct node * root;

    root = create();

    printf("\n\nDisplay tree\n\n");
    display(root);

    return 0;
}