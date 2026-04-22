#include <iostream>
using namespace std;

int main() {
    int arr[20], n;
    int max, min;
    float rata = 0;

    cout << "Masukkan jumlah data (maks 20): ";
    cin >> n;

    if (n > 20) {
        cout << "Data melebihi batas!";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i+1 << ": ";
        cin >> arr[i];
    }

    max = min = arr[0];

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
        rata += arr[i];

        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    rata /= n;

    cout << "\nNilai terbesar: " << max;
    cout << "\nNilai terkecil: " << min;
    cout << "\nRata-rata: " << rata;

    return 0;
}