#include<stdio.h>
#include<stdlib.h>

void enqueue();
void dequeue();
void display();
int rear = -1;
int front = -1;
int queue[100];
int size;

int main()
{
    printf("\nCODE BY Aswin Phuyal\n\n\n");
    int a;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);
    while(1)
    {
        printf("\nMenu:\n");
        printf("1) Enqueue\n");
        printf("2) Dequeue\n");
        printf("3) Display\n");
        printf("4) Exit\n");
        printf("Enter your choice: ");
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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
        }
    }
}

void enqueue()
{
    if(rear == size - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
        }
        printf("Enter the element to enqueue: ");
        scanf("%d", &queue[++rear]);
        printf("Element %d enqueued successfully.\n", queue[rear]);
    }
}

void dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Element dequeued is %d\n", queue[front++]);
    }
}

void display()
{
    if(front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The elements in the queue are: ");
        for(int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
