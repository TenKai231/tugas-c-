#include <iostream>
using namespace std;

// Fungsi rekursif membalik array 1D
void reverseArray(int arr[], int start, int end) {
    if (start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    reverseArray(arr, start + 1, end - 1);
}

int main() {

    int a[3][3] = { {1, 8}, {2, 4, 6}, {5} };

    cout << "=== ARRAY SEBELUM DIBALIK ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    // Membalik setiap baris
    for (int i = 0; i < 3; i++) {
        reverseArray(a[i], 0, 2);
    }

    cout << "\n=== ARRAY SETELAH DIBALIK TIAP BARIS ===" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
