#include <stdio.h>

void insertionsort(int arr[], int n, int order) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // ASCENDING order
        if (order == 1) {
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }
        // DESCENDING order
        else if (order == 2) {
            while (j >= 0 && arr[j] < key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        }

        arr[j + 1] = key;

        // Display current state of array
        printf("Step %d: ", i);
        for (int k = 0; k < n; k++) {
            printf("%d ", arr[k]);
        }
        printf("\n");
    }
}

int main() {
    int n, order;

    printf("**\tCompiled By Aswin Phuyal\t**\n");

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nChoose sorting order:\n");
        printf("1. Ascending\n");
        printf("2. Descending\n");
        printf("0. Exit\n");
        printf("Enter choice (0, 1 or 2): ");
        scanf("%d", &order);

        if (order == 0) {
            printf("Exiting...\n");
            break;
        } else if (order != 1 && order != 2) {
            printf("Invalid choice. Try again.\n");
            continue;
        }

        printf("\nSorting steps:\n");
        insertionsort(arr, n, order);

        printf("\nSorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}