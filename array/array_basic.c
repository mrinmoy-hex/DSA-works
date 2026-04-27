#include <stdio.h>

// Function prototypes
void traversal(int arr[], int n);

void insertion(int arr[], int pos, int value, int *size, int capacity);

int deletion(int arr[], int pos, int *size);

int main() {
    // Declare with extra capacity 
    int arr[10] = {6, 2, 1, 5, 3};
    int size = 5;
    int capacity = 10;

    traversal(arr, size);

    // Insert 10 at position 3
    insertion(arr, 3, 10, &size, capacity);
    traversal(arr, size);

    // Delete value at position 3
    int deleted = deletion(arr, 3, &size);
    traversal(arr, size);

    printf("The deleted value was: %d\n", deleted);

  return 0;
}

// Function definition

// Use a pointer for size so the function can update the caller's variable
void traversal(int arr[], int n) {
    printf("Array elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion(int arr[], int pos, int value, int *size, int capacity) {
    if (pos < 1 || pos > *size + 1 || *size >= capacity) {
        printf("Insertion failed: Invalid position or array full.\n");
        return;
    }

    // Shift elements to the right
    for (int i = *size - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }
    
    arr[pos - 1] = value;
    (*size)++; // Update the size in main
}

int deletion(int arr[], int pos, int *size) {
    if (pos < 1 || pos > *size) {
        printf("Deletion failed: Invalid position.\n");
        return -1;
    }

    int deleted = arr[pos - 1]; // Save value before overwriting

    // Shift elements to the left
    for (int i = pos - 1; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*size)--; // Update the size in main
    return deleted;
}
