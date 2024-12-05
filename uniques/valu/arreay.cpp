
#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,1,2,3,4};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Unique elements: ";
    for (int i = 0; i < size; i++) {
        int isUnique = 1;

        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = 0; // Elem
            }
        }

        if (isUnique) {
            cout << arr[i] << " ";
        }
    }
    return 0;
}
