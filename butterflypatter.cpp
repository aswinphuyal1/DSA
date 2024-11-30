#include <iostream>
using namespace std;

int main() {
    int rows = 7; // Total rows for the upper triangle
    int columns = 7; // Total columns for the vertical lines
    
    // Upper triangular pattern with a grid
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if (j <= i) {
                cout << "* "; // Print stars
            } else {
                cout << "  "; // Empty spaces
            }
        }
        cout << endl;
    }

    // Horizontal line
    for (int i = 0; i < columns * 2; ++i) {
        cout << "-"; // Adjust the length of the horizontal line
    }
    cout << endl;

    // Lower triangular pattern
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j) {
            if (j < rows - i) {
                cout << "* "; // Print stars
            } else {
                cout << "  "; // Empty spaces
            }
        }
        cout << endl;
    }

    return 0;
}
