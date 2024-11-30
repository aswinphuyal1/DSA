/*

*/

#include<iostream>
using namespace std;
int main()
{
   // char a;
   //4 cin>>a;
    int n;
    cin>>n;
     char ch='A';
    for(int i=1;i<=n;i++)
    {
       
        for(int j=1;j<=3;j++)
        {
            cout<<ch<<" ";
            ch=ch+1;
        }
        cout<<endl;

    }
}