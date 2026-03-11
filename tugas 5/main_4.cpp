#include <iostream>
using namespace std;

int main() {
    int nilai[30], n;
    int max, min, lulus = 0;
    float rata = 0;

    cout << "Jumlah mahasiswa: ";
    cin >> n;

    if (n > 30) {
        cout << "Melebihi batas!";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << "Nilai mahasiswa ke-" << i+1 << ": ";
        cin >> nilai[i];
    }

    max = min = nilai[0];

    for (int i = 0; i < n; i++) {
        rata += nilai[i];

        if (nilai[i] > max) max = nilai[i];
        if (nilai[i] < min) min = nilai[i];
        if (nilai[i] >= 75) lulus++;
    }

    rata /= n;

    cout << "\nNilai tertinggi: " << max;
    cout << "\nNilai terendah: " << min;
    cout << "\nRata-rata kelas: " << rata;
    cout << "\nJumlah lulus: " << lulus;
    cout << "\nPersentase kelulusan: " << (lulus * 100.0 / n) << "%";

    return 0;
}