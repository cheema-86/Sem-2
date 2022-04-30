#include <stdio.h>

int main(){
    int array[3][3] = {1,2,3,4,5,6,7,8,9};
    printf("{\n");
    for (int i = 0; i < 3; i++){
        printf("{");
        for (int j = 0; j< 3; j++){
            printf("%d, ",array[i][j]);
        }
        printf("} \n");
    }
    printf("}\n\n");
    return 0;

}