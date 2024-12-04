#include<iostream>
using namespace std;

int linearsearch(int a[],int  sz, int x)
{
for(int i=0;i<sz;i++)
{
    if(a[i]==x)
    {
        return i;
    }
    
}
return -1;

}
int main()
{
    int index;
int a[3];
for(int i=0;i<3;i++)
{
    cin>>a[i];
}

int z=linearsearch(a,3,2);
cout<<z;
return 0;
}
