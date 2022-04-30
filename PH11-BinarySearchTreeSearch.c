#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node * left;
    int data;
    struct node * right;
};

struct node * createRoot(int item){
    //defining new node
    struct node * newnode;
    newnode = (struct node *)malloc(sizeof(struct node *));

    newnode->data = item;

    //return the address of the node to the previous node
    return newnode; 
}

struct node * insert(struct node* current, int item){
    if (current == NULL){
        struct node * newnode;
        newnode = (struct node *)malloc(sizeof(struct node *));

        newnode->data = item;

        return newnode;
    } else if(current-> data < item){
        current->right = insert(current->right, item);
        return current;
    } else {
        current->left = insert(current->left, item);
        return current;
    }

}

void search(struct node* current, int item){
    if (current == NULL){
        printf("Not found");
    } else if(current-> data < item){
        search(current->right, item);
    } else if (current-> data > item){
        search(current->left, item);
    } else if (current->data == item){
        printf("%d found",item);
    } else {
        printf("Unexpected error");
    }
}



void pre(struct node * item){
    printf("%d ",item->data);

    if (item -> left != 0){
        pre(item->left);
    }

    if (item -> right != 0){
        pre(item->right);
    }
}

void post(struct node * item){
   if (item -> left != 0){
        post(item->left);
    }

    if (item -> right != 0){
        post(item->right);
    }
    
    printf("%d ",item->data);
}

void inorder(struct node * item){
    if (item -> left != 0){
        inorder(item->left);
    }

    printf("%d ",item->data);

    if (item -> right != 0){
        inorder(item->right);
    }
}



int main(){
    struct node * root;

    int input, toSearch;

    printf("Enter root node: ");
    scanf("%d", &input);

    root = createRoot(input);

    while (1){
        printf("Enter data to enter: ");
        scanf("%d", &input);
        if (input == -1){
            break;
        }
        insert(root, input);
    }


    printf("\n\nEnter item to search: ");
    scanf("%d", &toSearch);


    search(root,toSearch);


    printf("\n\nDisplay  preorder:  ");
    pre(root);

    printf("\n\nDisplay postorder:  ");
    post(root);

    printf("\n\nDisplay   inorder:  ");
    inorder(root);

    return 0;
}