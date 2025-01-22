#include<stdio.h>
#include<stdlib.h>
int enqueue();
int dequeue();
int display();
int rear=-1;
int front=-1;
int queue[100];
int size;
int main()
{
   // int size;

    printf("\nCODE BY ASwin phuyal\n\n\n");
    int a;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    while(1)
    {
        printf("Enter \n 1)to enqueue\n 2)to dequeue\n 3)to display\n 4)to exit\n: ");
        scanf("%d", &a);
        switch(a)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
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

enqueue()
{
    if(rear==size-1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(front==-1)
        {
            front=0;
        }
        printf("Enter the element to enqueue: ");
        scanf("%d", &queue[++rear]);
    }
}

dequeue()
{
    if(front==-1||front>rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Element dequeued is %d\n",queue[front++]);
    }
}

display()
{
    if(front==-1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The elements in the queue are: ");
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
