#include<iostream>
using namespace std;
int main()
{
    int index;
int a[3];
for(int i=0;i<3;i++)
{
    cin>>a[i];
}
int lar=a[0];
for(int i=0;i<3;i++)
{
    if(a[i]>lar)
    {
        lar=a[i];
      index=i;
    }
    
}
cout<<"the index is "<<index;

}