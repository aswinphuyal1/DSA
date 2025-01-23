#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,n,m;
    int *ptr1,*ptr2;
     

     printf("enter the sixe of the memory you want");
     scanf("%d",&n);

     ptr1=(int*)malloc(sizeof(int)*n);
     for(i=0;i<n;i++)
     {
        printf("%d",*(ptr1+i));
     }
     printf("\n");
printf("the mermory is allocated");
     printf("the value of N is");
     for(i=0;i<n;i++)
     {

        printf("%d",*(ptr1+i));

     }








}