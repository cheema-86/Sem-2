#include <stdio.h>

int main()
{
    int arr[] = {34, 56, 4, 10, 77, 51, 93, 30, 5, 52};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    int i, key, j,pass = 0;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        pass++;
        arr[j + 1] = key;
    }
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nPass = %d",pass);
 
    return 0;
}