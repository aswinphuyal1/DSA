#include<iostream>
using  namespace std;
int main() 
{
    int a[]={1,2,1,3,4};
    int b[]={1,7,2,4,9,0};
    int sizea=sizeof(a)/sizeof(a[0]);

    int sizeb=sizeof(b)/sizeof(b[0]);
    for(int i=0;i<sizea;i++)
    {
        for(int j=0;j<sizeb;j++)
    {
        if(a[i]== b[j])
        {
            cout<< a[i]<<" ";
        }
    }
    }
}