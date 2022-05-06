#include <stdio.h>

int arr[8] = {60, 40, 20, 95, 70, 30, 50, 90};

void quicksort(int pivot, int stop){
    if (pivot < stop){
        int start = pivot, end = stop, temp;

        while (start <= end){
            if (arr[start] <= arr[pivot]){
                start++;
            } else if (arr[end] > arr[pivot]){
                end--;
            } else {
                temp = arr[start];
                arr[start] = arr[end];
                arr[end] = temp;
                start++;
                end--;

                /*
                printf("\n\nSwap Check\n");
                for (int i = 0; i<8; i++){
                    printf("%d ",arr[i]);
                
                }
                */
            }
        }

        temp = arr[pivot];
        arr[pivot] = arr[end];
        arr[end] = temp;

        /*
        printf("\n\nArray Check\n");
        printf("pivot = %d  stop = %d\n",pivot,stop);
        for (int i = 0; i<8; i++){
            printf("%d ",arr[i]);
        }
        */

        quicksort(pivot, end-1);

        quicksort(end+1, stop);
        
    }



}

int main(){
    int i;

    printf("Unsorted array\n");
    for (i = 0; i<8; i++){
        printf("%d ",arr[i]);
    } 

    quicksort(0,7);

    printf("\n\nSorted array\n");
    for (i = 0; i<8; i++){
        printf("%d ",arr[i]);
    } 
    
    return 0;
}
