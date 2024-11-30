#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
int n=4;
//cin>>n;
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)
    {
cout<<j<<setw(4);
    }
    cout<<endl;
}

}