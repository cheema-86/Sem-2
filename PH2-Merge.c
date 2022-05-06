#include <stdio.h>

int main (){
    /*
    int a[5];
    for (int a = 0; a < 5; a++){
        scanf("%d",&a[i]);
    }
    */
    int a[] = {1,5,7,10,13};
    int b[] = {2,3,6,11,12,14,20};

    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);

    int c[m+n];

    int i = 0, j = 0, k =0;

    while (i<m && j<n){
        if (a[i] < b[j]){
            c[k] = a[i];
            i++;
            k++;
        } else {
            c[k] = b[j];
            j++;
            k++;
        }
    }


    if (i>=m) {
        while (j<n){
            c[k] = b[j];
            j++;
            k++;
        }
    }

    if (j>=n) {
        while (i<m){
            c[k] = a[i];
            i++;
            k++;
        }
    }

    printf("Sorted array: ");
    for (int x = 0; x<k; x++){
        printf("%d ",c[x]);
    }



    return 0;
}