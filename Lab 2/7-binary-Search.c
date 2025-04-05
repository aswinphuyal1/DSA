#include <stdio.h>
// func to perform binary search
int binarySearch(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // calculate middle index

        // if key is present at mid
        if (arr[mid] == key) {
            return mid;
        }

        // if key is greater than mid ignore left half
        if (arr[mid] < key) {
            left = mid + 1;
        }
        // if key is smaller than mid ignore right half
        else {
            right = mid - 1;
        }
    }
    return -1; 
}
int main() {
    int n, key;
printf("**\tCompiled By Aswin phuyal\t**\n");
    // ask user for no. of elements in array
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    int arr[n];  // declare array of size n

    // ask user for elements of the array
    printf("Enter the elements of the list in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // ask user for the key to search
    printf("Enter the key to search: ");
    scanf("%d", &key);

    // perform binary search
    int result = binarySearch(arr, n, key);

    // display the result
    if (result == -1) {
        printf("Key not found in the list.\n");
    } else {
        printf("Key found at index %d.\n", result);
    }}
