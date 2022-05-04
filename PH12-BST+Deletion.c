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

    while (current != NULL && current->left != NULL){
        current = current->left;
    }

    return current;
}
 
 
struct node* delete(struct node* root, int item){
    if (root == NULL){
        return root;
    }

    if (item < root->data){
        root->left = delete(root->left, item);
    } else if (item > root->data){
        root->right = delete(root->right, item);
    } else {

        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }
 
        struct node* temp = min(root->right);

        root->data = temp->data;

        root->right = delete(root->right, temp->data);
    }
    return root;
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

    int input;

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

    while (1){
        printf("Enter item to delete: ");
        scanf("%d", &input);
        if (input == -1){
            break;
        }
        delete(root, input);
    }

    printf("\n\nDisplay  preorder:  ");
    pre(root);

    printf("\n\nDisplay postorder:  ");
    post(root);

    printf("\n\nDisplay   inorder:  ");
    inorder(root);

    return 0;
}