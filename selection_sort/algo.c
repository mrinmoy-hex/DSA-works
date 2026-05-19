#include <stdio.h>

void printArr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *arr, int n) {
    int indexOfMin, temp;
    for (int i = 0; i < n-1; i++) {
        indexOfMin = i;
        // loop for comparision of the min
        for (int j = i+1; j < n; j++) {
            
            if (arr[j] < arr[indexOfMin]) {
                indexOfMin = j;
            }
        }
        // Swap arr[i] and arr[indexOfMin]
        temp = arr[i];
        arr[i] = arr[indexOfMin];
        arr[indexOfMin] = temp; 
    }
}

int main() {
    // 00, 01, 02, 03, 04
    // 03, 05, 02, 13, 12
    /*
    After 1st pass:
    00, 01, 02, 03, 04
    02, 05, 03, 13, 12
    
    After 2nd pass:
    00, 01, 02, 03, 04
    02, 03, 05, 13, 12
    
    After 3rd pass:
    00, 01, 02, 03, 04
    02, 03, 05, 13, 12

    After 4th pass:
    00, 01, 02, 03, 04
    02, 03, 05, 12, 13
    */

    int arr[] = {3, 5, 2, 13, 12};
    int n = 5;
    
    printf("Array before sorting:\n");
    printArr(arr, n);

    printf("Array running selection sort:\n");
    selectionSort(arr, n);
    printArr(arr, n);

    return 0;
}