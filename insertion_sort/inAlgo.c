#include <stdio.h>

void printArr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int *arr, int n) {
    // Loop for passes
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        // Loop for each pass
        while(j >=0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    // -1 0  1   2   3   4   5
    //    7, 12, 23, 54, 65, 9

    // Indices:  0   1   2   3   4   5
    // Array:   12, 54, 65, 07, 23, 09
    
    // --- 1st Pass ---
    // 12, | 54, 65, 07, 23, 09  --> i=1, key=54, j=0
    // 12, 54, | 65, 07, 23, 09  --> 1st pass done (i=1)!
    
    // --- 2nd Pass ---
    // 12, 54, | 65, 07, 23, 09  --> i=2, key=65, j=1
    // 12, 54, 65, | 07, 23, 09  --> 2nd pass done (i=2)!
    
    // --- 3rd Pass (Detailed Shift) ---
    // 12, 54, 65, | 07, 23, 09  --> i=3, key=7, j=2
    // 12, 54, 65, | 65, 23, 09  --> i=3, key=7, j=1 (65 shifted right)
    // 12, 54, 54, | 65, 23, 09  --> i=3, key=7, j=0 (54 shifted right)
    // 12, 12, 54, | 65, 23, 09  --> i=3, key=7, j=-1 (12 shifted right)
    // 7, 12, 54, 65, | 23, 09   --> i=3, key=7, j=-1 --> 3rd pass done (i=3)!
    
    // --- Fast Forwarding ---
    // 4th Pass:
    // 7, 12, 54, 65, | 23, 09   --> i=4, key=23, j=3
    // (23 is compared with 65, 54, and 12. It shifts 65 and 54 then inserts after 12)
    // 7, 12, 23, 54, 65, | 09   --> After the 4th pass
    
    // 5th Pass:
    // 7, 12, 23, 54, 65, | 09   --> i=5, key=9, j=4
    // (9 is compared with 65, 54, 23, 12, and 7. It shifts everything down to index 1)
    // 7, 9, 12, 23, 54, 65      --> Final sorted array!

    int arr[] = {12, 54, 65, 7, 23, 9};
    int n = (sizeof(arr)/sizeof(int));
    printf("Array:\n");
    printArr(arr, n);

    insertionSort(arr, n);
    printArr(arr, n);

    return 0;
}