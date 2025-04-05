#include <stdio.h>
// func to perform linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;  // return the index if the key is found
        }
    }
    return -1;  // return -1 if key is not found
}

int main() {
    int n, key;
printf("**\tCompiled By Aswin phuyal\t**\n");
    // ask user for the size of the array
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    int arr[n];  // declare the array of size n

    // ssk user for the elements of the array
    printf("Enter the elements of the list: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // ask user for the key to search
    printf("Enter the key to search: ");
    scanf("%d", &key);

    // perform linear search
    int result = linearSearch(arr, n, key);

    // display result
    if (result == -1) {
        printf("Key not found in the list.\n");
    } else {
        printf("Key found at index %d.\n", result);
    }

    return 0;
}
