#include<iostream>
using namespace std;
int main()
{char ch;

    cout<<"enter a charecter in lower or upper case"<<endl;
cin>>ch;
    if(ch>='a' && ch<='z')
    {
        cout<<"it is ni lower case";
    }
    else 
    {
        cout<<"it is in uppercase ";
    };
}

/*
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;


        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        
        for (int k = 0; k < n - i; k++)
        {
            cout << i + 1;
        }
    
    }

    return 0;
}
*/