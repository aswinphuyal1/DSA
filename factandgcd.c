#include<stdio.h>
#include<stdlib.h>

int fact(int);
int gcd(int, int);

int main()
{
    int a;
    printf("\nCODE BY Aswin Phuyal\n\n\n");
    printf("enter your choice\n 1) for factorial\n 2) for gcd\n");
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
        default:
            printf("Invalid input. Please try again.\n");
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