#include <stdio.h>

int main(){
    int array[3][3] = {1,2,3,4,5,6,7,8,9};
    int toFind;
    int found = 0;

    printf("Enter number you want to find: ");
    scanf("%d",&toFind);

    for (int i = 0; i < 3; i++){
        for (int j = 0; j< 3; j++){
            if (array[i][j]==toFind){
                printf("%d found at location [%d][%d]\n",toFind,i,j);
                found = 1;
                break;
            }
        }
    }

    if (!found){
        printf("Requested number not found\n");
    }

    return 0;

}