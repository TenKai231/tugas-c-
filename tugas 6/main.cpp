#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    cout << "Nama  : Rama Ferdiansyah" << endl;
    cout << "NIM   : 09020282529067" << endl;
    cout << "PROGRAM PENJUALAN HARIAN MENGGUNAKAN ARRAY\n" << endl;

    string nim = "09020282529067";
    int digitTerakhir = nim[nim.length() - 1] - '0'; // 7
    int jumlahHari = nim.length();                    // 14
    long long targetCari = (long long)digitTerakhir * 1000; // 7000

    int penjualan[jumlahHari];

    // 1. INPUT DATA - hari ke-1 sampai ke-14
    // 1. INPUT DATA
    cout << "--- INPUT DATA PENJUALAN ---" << endl;
    for (int i = 0; i < jumlahHari; i++) {
    cout << "Masukkan penjualan hari ke-" << (i + 1) 
         << " (index ke-" << i << ") : ";
    cin >> penjualan[i];
}

    // 2. TAMPILKAN SEMUA DATA
    cout << "\n--- SEMUA DATA PENJUALAN ---" << endl;
    for (int i = 0; i < jumlahHari; i++) {
    cout << "Hari ke-" << (i + 1) 
         << " (index ke-" << i << ") : " << penjualan[i] << endl;
}

    // 3. TOTAL & RATA-RATA
    long long total = 0;
    for (int i = 0; i < jumlahHari; i++) {
        total += penjualan[i];
    }
    double rataRata = (double)total / jumlahHari;

    cout << "\n--- STATISTIK PENJUALAN ---" << endl;
    cout << "Total penjualan     : " << total << endl;
    cout << fixed << setprecision(2);
    cout << "Rata-rata penjualan : " << rataRata << endl;

    // 4. NILAI TERBESAR
    int terbesar = penjualan[0];
    for (int i = 1; i < jumlahHari; i++) {
        if (penjualan[i] > terbesar) terbesar = penjualan[i];
    }
    cout << "\nPenjualan terbesar  : " << terbesar << endl;
    cout << "Terjadi pada        : ";
    bool pertama = true;
    for (int i = 0; i < jumlahHari; i++) {
        if (penjualan[i] == terbesar) {
            if (!pertama) cout << ", ";
            cout << "hari ke-" << (i + 1) << " (index " << i << ")";
            pertama = false;
        }
    }
    cout << endl;

    // 5. NILAI TERKECIL
    int terkecil = penjualan[0];
    for (int i = 1; i < jumlahHari; i++) {
        if (penjualan[i] < terkecil) terkecil = penjualan[i];
    }
    cout << "\nPenjualan terkecil  : " << terkecil << endl;
    cout << "Terjadi pada        : ";
    pertama = true;
    for (int i = 0; i < jumlahHari; i++) {
        if (penjualan[i] == terkecil) {
            if (!pertama) cout << ", ";
            cout << "hari ke-" << (i + 1) << " (index " << i << ")";
            pertama = false;
        }
    }
    cout << endl;

    // 6. CARI DATA = targetCari (7000)
    cout << "\n--- CARI PENJUALAN = " << targetCari << " ---" << endl;
    bool ketemu = false;
    for (int i = 0; i < jumlahHari; i++) {
        if (penjualan[i] == targetCari) {
            cout << "Ditemukan pada hari ke-" << (i + 1)
                 << " (index " << i << ") : " << penjualan[i] << endl;
            ketemu = true;
        }
    }
    if (!ketemu) {
        cout << "Data " << targetCari << " tidak ditemukan." << endl;
    }

    return 0;
}