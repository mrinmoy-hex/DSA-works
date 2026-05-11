#include <stdio.h>

void printArr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Optimized bubble sort (adaptive)
void bubbleSort(int *arr, int n) {
    int isSorted = 0;

    // For number of passes
    for (int i = 0; i < n-1; i++) {
        printf("Pass no: %d\n", i+1);
        isSorted = 1;

        // For comparisions in each pass
        for (int j = 0; j < n-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap the values 
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                isSorted = 0;
            }
        }

        if (isSorted) {
            return;
        }
    }
}

int main() {
    int arr[] = {12, 54, 65, 7, 23, 9};
    int arr2[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr2)/ sizeof(int);

    printf("Array elements before sorting: \n");
    printArr(arr, n);

    printf("Array after BUBBLE SORT:\n");
    bubbleSort(arr2, n);
    printArr(arr2, n);

    return 0;
}