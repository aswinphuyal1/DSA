#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) // Rows
    {
        // Print leading spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // Print increasing sequence
        for (int k = 1; k <= i + 1; k++)
        {
            cout << k;
        }

        // Print decreasing sequence
        for (int k = i; k > 0; k--)
        {
            cout << k;
        }

        cout << endl; // Move to the next line
    }

    return 0;
}
