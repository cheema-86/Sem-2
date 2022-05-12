#include <stdio.h>

int main(){
    int n = 8, temp, inter = 0;
    int arr[]={32,51,27,85,66,23,13,57};

    /*
    printf("Enter the values you want to sort (8 values):");
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
    */

    for (int pass = 0; pass<=n-1; pass++){
        for (int i = 0; i<n-pass; i++){
            if(arr[i]>arr[i+1]){
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                inter++;
            }
        }
    }

    printf("____SORTED ARRAY____\n");
    for (int i = 0; i < n; i++){
        printf("%d, ",arr[i]);
    }
    printf("\nInterchanges = %d",inter);


    return 0;
}