#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i, n, m;
    int *ptr1, *ptr2;

    printf("enter the size of memory N: ");
    scanf("%d", &n);

    ptr1 = (int*)malloc(sizeof(int) * n);
    if (ptr1 == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    printf("Garbage values:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", *(ptr1 + i));
    }
    printf("\n");

    for(i = 0; i < n; i++) {
        printf("enter the value for pointer %d: ", i + 1);
        scanf("%d", (ptr1 + i));
    }

    printf("The values are:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", *(ptr1 + i));
    }
    printf("\n");

    printf("enter the new size of memory M: ");
    scanf("%d", &m);

    ptr2 = (int*)realloc(ptr1, sizeof(int) * m);
    if (ptr2 == NULL) {
        printf("Memory not reallocated.\n");
        free(ptr1);
        return 1;
    }

    if (m > n) {
        for(i = n; i < m; i++) {
            printf("enter the value for pointer %d: ", i + 1);
            scanf("%d", (ptr2 + i));
        }
    }

    printf("The values are:\n");
    for(i = 0; i < m; i++) {
        printf("%d ", *(ptr2 + i));
    }
    printf("\n");

    free(ptr2);

    return 0;
}

