#include <iostream>
using namespace std;

int main() {
    int matriks[3][3];
    int jumlah = 0, max;

    cout << "Input matriks 3x3:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> matriks[i][j];
        }
    }

    max = matriks[0][0];

    cout << "\nMatriks:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriks[i][j] << " ";
            jumlah += matriks[i][j];

            if (matriks[i][j] > max)
                max = matriks[i][j];
        }
        cout << endl;
    }

    cout << "Jumlah: " << jumlah;
    cout << "\nRata-rata: " << jumlah / 9.0;
    cout << "\nNilai terbesar: " << max;

    return 0;
}