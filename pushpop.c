#include<stdio.h>
#include<stdlib.h>

int push();
int top = -1;
int size;
int stack(size); // Declare stack as an array with a fixed size
int n;

int main()
{
    int a;

    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    while(1)
    {
        printf("Enter \n 1)to push\n 2)to pop\n 3)to display\n 4)to exit\n: ");
        scanf("%d", &a);
        switch(a)
        {
            case 1:
                push();
                break;
            case 2:
                printf("Invalid input\n");
                break;
            case 3:
                printf("Invalid input\n");
                break;
            case 4:
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
        scanf("%d", &stack); 
        top++;
    }
}