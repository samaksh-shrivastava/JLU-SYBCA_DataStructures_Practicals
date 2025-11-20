#include <iostream>
using namespace std;

int main() {
    int size, n;
    cin >> size >> n;
    int table[100];
    for (int i = 0; i < size; i++) {
        table[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int key;
        cin >> key;
        int index = key % size;
        table[index] = key;
    }
    for (int i = 0; i < size; i++) {
        cout << i << ":" << table[i] << endl;
    }
    return 0;
}
