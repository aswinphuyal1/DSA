#include<stdio.h>
#include<stdlib.h>

int push();
int pop();
int top = -1;
int size;
int *stack; // Declare stack as a pointer to int

int main()
{
    int a, i = 0;

    printf("Enter the size of the stack: ");
    scanf("%d", &size);
    
    stack = (int*)malloc(size * sizeof(int)); // Allocate memory for the stack
    if (stack == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    while(1)
    {
        printf("Enter \n 1)to push\n, 2)to pop\n, 3)to display\n, 4)to exit\n: ");
        scanf("%d", &a);
        switch(a)
        {
            case 1:
                push();
                break;
            case 2:
               
                break;
            case 3:
              
                break;
            case 4:
                free(stack);
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }
}

int push()
{
    if(top == size - 1)
    {
        printf("Stack is full\n");
    }
    else
    {
        printf("Enter the element to push: ");
        scanf("%d", &stack); // Increment top and then assign value
    top++;
    }
}