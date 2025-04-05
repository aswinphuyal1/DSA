#include <stdio.h>
void insertionsort(int arr[], int n) {
    int i, key, j;
    //  to trace the sorting process
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        
        // move elements of arr[0..i-1] that are greater than key, one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;

        // display current state of array
        printf("step %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}
int main() {
    int n;
printf("**\tCompiled By Aswin phuyal\t**\n");
    // uswr input
    printf("enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    
    // get the elements from the user
    printf("enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // for insertion sort and trace the steps
    printf("\nsorting steps:\n");
    insertionsort(arr, n);
    // final sorted array
    printf("\nsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n"); }

