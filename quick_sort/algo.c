#include <stdio.h>

void printArr(int *arr, int n)
{
    // Print array elements
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low]; // choose first element as pivot
    int i = low + 1;      // left pointer
    int j = high;         // right pointer
    int temp;

    do
    {
        // move i until larger element is found
        while (arr[i] <= pivot)
        {
            i++;
        }

        // move j until smaller element is found
        while (arr[j] > pivot)
        {
            j--;
        }

        // swap misplaced elements
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

    } while (i < j);

    // place pivot in its correct position
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j; // return pivot index
}

void quickSort(int *arr, int low, int high)
{
    int partitionIndex;

    // continue if subarray has more than one element
    if (low < high)
    {
        partitionIndex = partition(arr, low, high);
        printArr(arr, 8);
        quickSort(arr, low, partitionIndex - 1);  
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main()
{
    int arr[] = {3, 5, 2, 13, 12, 45, 11, 7};
    int n = 8;

    printf("Array before sorting:\n");
    printArr(arr, n);

    printf("Array after quick sort:\n");
    quickSort(arr, 0, n - 1);

    printArr(arr, n);

    return 0;
}