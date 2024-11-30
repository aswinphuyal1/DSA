/* #include<iostream>
using namespace std;
int main()
{
 
    int n;
    cin>>n;
     int a=1;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<i;j++)
        {
 
   cout<<" ";
         
        }
        for(int k=0;k<=i-1;k++)
        {
            cout<<i+1<<" ";
        }
   
        cout<<endl;
    }

}*/

#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)  // Loop for rows
    {
        // Print leading spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        
        // Print numbers
        for (int k = 0; k < n - i; k++)
        {
            cout << i + 1<<" ";
        }
        
        cout << endl;  // Move to the next line
    }

    return 0;
}
