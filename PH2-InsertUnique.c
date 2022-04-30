#include <stdio.h>


int main (){

    int array[10];
    int filled = 0, temp, present;

    for (int i = 0; i < 10; i++){
        present = 0;
        scanf("%d",&temp);

        for (int j = 0; j < filled; j++){
            if (temp == array[j]){
                present = 1;
            }
        }

        if (!present){
            array[i] = temp;
            filled++;
        } else {
            i--;
        }
    }

    printf("Array: ");
    for (int x = 0; x<10; x++){
        printf("%d ",array[x]);
    }



    return 0;
}
