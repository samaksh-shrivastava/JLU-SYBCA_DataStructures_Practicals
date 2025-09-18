#include <iostream>
using namespace std;

int main() {
    int n, pos, element;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100]; 

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter position to insert (1 to " << n+1 << "): ";
    cin >> pos;

    cout << "Enter element to insert: ";
    cin >> element;

    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position!" << endl;
    } else {
        for (int i = n; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }
        arr[pos - 1] = element;
        n++;
    }

    cout << "Array after insertion: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
