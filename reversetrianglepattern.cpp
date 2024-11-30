#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {  // Outer loop for rows, starting from `n` down to 1
        for (int j = i+1; j > 0; j--) {  // Inner loop for numbers in decreasing order
            cout << j << " ";
        }
        cout << endl;  // Move to the next line after each row
    }

    return 0;
}
