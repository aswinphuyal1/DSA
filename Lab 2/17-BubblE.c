#include <stdio.h>
// bubble sort func and trace each pass
void bubblesort(int arr[], int n) {
    int i, j, temp;
 
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            // compare adjacent elements
            if (arr[j] > arr[j+1]) {
                // swap the elements if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        // display array after each pass
        printf("pass %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    int n;
printf("**\tCompiled By Aswin phuyal\t**\n");
    printf("BUBBLE SORT\n");
    // take input from the user
    printf("enter no. of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // func call
    printf("\nsorting process:\n");
    bubblesort(arr, n);

    // final sorted array
    printf("\nsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

