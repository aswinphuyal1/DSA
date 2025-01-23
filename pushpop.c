#include<stdio.h>
#include<stdlib.h>

int push();
int pop();
void display();
int top = -1;
int size;
int stack[100]; // Declare stack as an array with a fixed size
int n;

int main()
{
     printf("\nCompiled  BY ASwin phuyal\n\n\n");
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
                pop();
                break;
            case 3:
                display();
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
        scanf("%d", &stack[++top]); // Increment top and then assign value
    }
}

int pop()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Popped element: %d\n", stack[top--]); // Print and decrement top
    }
}

void display()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for(int i = 0; i <= top; i++) // Fix the loop to include the top element
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}