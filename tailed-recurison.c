#include<stdio.h>
#include<stdlib.h>
int facto(int,int);
int main()
{

    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Factorial of %d is %d\n", num, facto(num,1));

}
int facto(int n,int a)
{
    if(n==0)
    {
        return a;
    }
    else
    {
        return facto(n-1,n*a);
    }
}