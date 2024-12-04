#include<iostream>
using namespace std;


void reversearray(int arr[],int siz)
{
    int start=0;
    int end=siz-1;
    while(start<=end)
{
    swap(arr[start], arr[end]);
    start++;
    end--;
}
}
int main()
{
    int a[]={1,3,4,5,6,7};
   int siz=6;
    reversearray(a, siz);
    for(int i=0;i<siz;i++)
    {
        cout<<a[i]<<" ";
    }
 
}