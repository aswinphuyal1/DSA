#include <stdio.h>
// function to perform selection sort
void selectionSort(int arr[], int n) {
    // outer loop for each position in the array
    for (int i = 0; i < n - 1; i++) {
        // assume minimum is the first element of unsorted part
        int minIndex = i;
        
        // inner loop to find the smallest element in unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // wwap smallest element with the first unsorted element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        // to print array after each pass
        printf("Pass %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}
// func to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
printf("**\tCompiled By Aswin phuyal\t**\n");
    int arr[] = {64, 25, 12, 22, 11};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);  // Size of the array

    printf("Original array: ");
    printArray(arr, n);

    // Call selection sort
    selectionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);
}
