#include <stdio.h>

int main() {
    int num = 10;
    int *ptrs;

    ptrs = &num;

    printf("%d\n", *ptrs);
    printf("%p\n", ptrs);


    // For arrays
    int arr[] = {6, 2, 1, 5, 3};
    int *q;
    q = arr;    // points to the base address of arr

    printf("%p\n", q);  
    q++;

    printf("%p\n", q); 
    printf("%d\n", *q); 

    return 0;
}