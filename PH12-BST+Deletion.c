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

struct node* min(struct node* node){
    struct node* current = node;

    while (current && current->left != NULL)
        current = current->left;
 
    return current;
}
 
 
struct node* deleteNode(struct node* root, int item){
    if (root == NULL)
        return root;
 
    if (item < root->data){
        root->left = deleteNode(root->left, item);
    } else if (item > root->data){
        root->right = deleteNode(root->right, item);
    } else {

        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        struct node* temp = min(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

/*
struct node * search(struct node* current, int item){
    struct node * newnode;

    if (current == NULL){
        printf("Not found");
        return 0;
    } else if(current-> data < item){
        if(current->right->data == item){
            return current;
        }
        newnode = search(current->right, item);
    } else if (current-> data > item){
        if(current->left->data == item){
            return current;
        }
        newnode = search(current->left, item);
    } else {
        printf("Unexpected error");
        return 0;
    }
    return newnode;
}

void delete(struct node* root, int item){
    struct node * parent, * child;

    parent = search(root, item);

    if (parent->left != NULL && parent->left->data == item){
        child = parent->left;
    } else if(parent->right != NULL && parent->right->data == item){
        child = parent->right;
    } else {
        printf("Search algo broken");
    }

    //Check number of childeren for the node to be deleted

    if (child->left == NULL && child->right == NULL){
        //the node has no children
        free(child); 
    } else if (child->left != NULL && child->right != NULL){
        printf("Deleting nodes with 2 children not supported yet");
    } else if(child->left == NULL){
        child = child->right;
    } else {
        child = child->left;
    }


}
*/

// array to check 15 13 9 7 11 14 17 16 25 29 -1 29

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

    printf("\n\nDisplay  preorder:  ");
    pre(root);

    printf("\n\nDisplay postorder:  ");
    post(root);

    printf("\n\nDisplay   inorder:  ");
    inorder(root);


    printf("\n\nEnter item to delete: ");
    scanf("%d", &toSearch);


    delete(root,toSearch);


    printf("\n\nDisplay  preorder:  ");
    pre(root);

    printf("\n\nDisplay postorder:  ");
    post(root);

    printf("\n\nDisplay   inorder:  ");
    inorder(root);

    return 0;
}