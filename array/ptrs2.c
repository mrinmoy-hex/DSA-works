// Cursed C program
#include <stdio.h>

int main() {
// Initialize at declaration
    int a[5] = {2, 3, 4, 5, 6}; 
    int i;    
    int *q = a; // Pointer to the start of the array
    // for (i = 0; i < 5; i++){
    //     scanf("%d", &a[i]);
    // }

    for (i = 0; i < 5; i++) {
        printf("%d ", i[q]);
        // i[q] -> *(i+q)
    }
    printf("\n");

    return 0;
}