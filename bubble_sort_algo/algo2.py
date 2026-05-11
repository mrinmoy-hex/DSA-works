
def bubble_sort(arr):

    size = len(arr)

    for i in range(size-1):

        swapped = False

        for j in range(size-1-i):
            if arr[j] > arr[j+1]:
                
                # Swap values
                arr[j], arr[j+1] = arr[j+1], arr[j]  
                swapped = True

        if not swapped:
            break


def main():
    arr = [2, 3, 7, 34, 23, 55, 12, 90, 332, 990, 30]

    print("Array elements (before sorting):")
    print(arr)

    print("Array elements after sorting (Bubble sort):")
    bubble_sort(arr)
    print(arr)


if __name__ == '__main__':
    main()