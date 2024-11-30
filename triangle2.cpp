#include<iostream>
using namespace std;
int main()
{
 
    int n;
    cin>>n;
     char a='a';
    for(int i=0;i<n;i++)
    {
       // int z=0;
        //z++;
       
        for(int j=0;j<i+1;j++)
        {
 
    cout<<a<<" ";
         
        }
   
        cout<<endl;
    a=a+1;
    }

}
/*
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    char a = 'a'; // Start with lowercase 'a'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << a << " "; // Print the current character
        }
        cout << endl;
        a++; // Increment the character for the next row
    }

    return 0;
}
*/