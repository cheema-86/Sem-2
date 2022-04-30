#include <stdio.h>

void merge(int array[], int low, int mid, int up){
    int i, j, k, m, n;

    m = mid - low + 1;
    n = up - mid;

    int temp1[m];
    int temp2[n];

    for (i = 0; i < m; i++)
        temp1[i] = array[low + i];
    for (i = 0; i < n; i++)
        temp2[i] = array[mid + 1 + i];

    i = 0;
    j = 0;
    k = low;

    while (i<m && j<n){
        if (temp1[i] < temp2[j]){
            array[k] = temp1[i];
            i++;
            k++;
        } else {
            array[k] = temp2[j];
            j++;
            k++;
        }
    }

    while (j<n){
        array[k] = temp2[j];
        j++;
        k++;
    }

    while (i<m){
        array[k] = temp1[i];
        i++;
        k++;
    }

} 

void mergesort(int array[],int low,int up){
    if (low < up){
        int mid = (low + up)/2;
        mergesort(array,low,mid);
        mergesort(array,mid+1,up);
        
        merge(array,low,mid,up);
    }
}


int main (){
    int arr[10];

    printf("Enter elements in array: ");
    for (int x = 0; x < 10; x++){
        scanf("%d", &arr[x]);
    }

    mergesort(arr,0,9);

    printf("Sorted array: ");
    for (int x = 0; x < 10; x++){
        printf("%d ", arr[x]);
    }
    return 0;
}