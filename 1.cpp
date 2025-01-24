#include <iostream>
using namespace std;

// Tail Recursive Function
int factorialTail(int n, int accumulator = 1) {
    if (n == 0) {
        return accumulator;
    }
    return factorialTail(n - 1, accumulator * n);
}

int main() {
    int number ;
    cout << "Enter a number: ";
    cin >> number;
    cout << "Factorial (Tail Recursion) of " << number << " is " << factorialTail(number) << endl;
    return 0;
}
