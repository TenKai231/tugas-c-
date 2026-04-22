#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& arr, int size) {
    if (size == 1)
        return arr[0];

    int minSebelumnya = findMin(arr, size-1);

    if (arr[size-1] < minSebelumnya)
        return arr[size-1];
    else
        return minSebelumnya;
}

int main() {
    int n;
    cout << "Masukkan jumlah elemen: ";
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << i << ": ";
        cin >> arr[i];
    }

    cout << "Nilai terkecil = " << findMin(arr, n) << endl;
    return 0;
}
