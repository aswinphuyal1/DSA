#include<stdio.h>
#include<stdlib.h>

int fact(int);
int gcd(int, int);
int towerOfHanoi(int, char, char, char);
int fibonacci(int);  // Function prototype for Fibonacci series
int count = 1;

int main()
{
    int a;
    printf("\nCODE BY Aswin Phuyal\n\n\n");
    while(1)
    {
        printf("enter your choice\n 1) for factorial\n 2) for gcd\n 3) for Tower of Hanoi\n 4) for Fibonacci series\n 5) to exit\n");
        scanf("%d", &a);
        switch(a)
        {
            case 1:
                printf("enter the number you want to find the factorial of: ");
                int b;
                scanf("%d", &b);
                int z = fact(b);
                printf("the factorial of the number is %d\n", z);
                break;
            case 2:
                printf("enter the two numbers you want to find the gcd of: ");
                int x, y;
                scanf("%d%d", &x, &y);
                int g = gcd(x, y);
                printf("the gcd of the numbers is %d\n", g);
                break;
            case 3:
                printf("enter the number of disks: ");
                int n;
                scanf("%d", &n);
                char from_rod, to_rod, aux_rod;
                printf("enter the source rod: ");
                scanf(" %c", &from_rod);
                printf("enter the destination rod: ");
                scanf(" %c", &to_rod);
                printf("enter the auxiliary rod: ");
                scanf(" %c", &aux_rod);
                towerOfHanoi(n, from_rod, to_rod, aux_rod);
                printf("The number of moves required are %d\n", count - 1);
                break;
            case 4:
                printf("enter the number of terms for Fibonacci series: ");
                int terms;
                scanf("%d", &terms);
                printf("Fibonacci series: ");
                for (int i = 0; i < terms; i++) {
                    printf("%d ", fibonacci(i));
                }
                printf("\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid input. Please try again.\n");
        }
    }
    return 0;
}

int fact(int a)
{
    if(a == 0)
    {
        return 1;
    }
    else
    {
        return a * fact(a - 1);
    }
}

int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("%d) Move disk 1 from rod %c to rod %c\n", count, from_rod, to_rod);
        count++;
        return 1;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("%d) Move disk %d from rod %c to rod %c\n", count, n, from_rod, to_rod);
    count++;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
    return 1;
}

int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}