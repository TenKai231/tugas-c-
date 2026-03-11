#include <iostream>
using namespace std;

int main() {
    int n;
    
    cout << "Masukkan jumlah mahasiswa: ";
    cin >> n;

    int nilai[n];
    int max, min, total = 0;

    for(int i = 0; i < n; i++) {
        cout << "Masukkan nilai mahasiswa ke-" << i+1 << ": ";
        cin >> nilai[i];
    }

    max = min = nilai[0];

    for(int i = 0; i < n; i++) {
        if(nilai[i] > max)
            max = nilai[i];

        if(nilai[i] < min)
            min = nilai[i];

        total += nilai[i];
    }

    float rata = (float) total / n;

    cout << "\nDaftar Nilai Mahasiswa:\n";
    for(int i = 0; i < n; i++) {
        cout << "Mahasiswa " << i+1 << " : " << nilai[i] << endl;
    }

    cout << "\nNilai Tertinggi : " << max << endl;
    cout << "Nilai Terendah : " << min << endl;
    cout << "Nilai Rata-rata : " << rata << endl;

    return 0;
}