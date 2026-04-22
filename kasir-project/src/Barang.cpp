#include "../includes/Barang.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Inisialisasi daftar barang jika diperlukan (misal hardcode data awal)
void initBarang(Barang arr[], int& count) {
    count = 0;
}

// Menambahkan barang baru ke dalam array
bool tambahBarang(Barang arr[], int& count, Barang baru) {
    if (count >= MAX_BARANG) {
        return false; // kapasitas penuh
    }
    
    // Cek duplikasi kode
    for (int i = 0; i < count; i++) {
        if (arr[i].kode == baru.kode && arr[i].isActive) {
            return false; // kode sudah ada
        }
    }
    
    baru.isActive = true;
    arr[count] = baru;
    count++;
    return true;
}

// Mencari barang berdasarkan kode
Barang* cariBarangByKode(Barang arr[], int count, string kode) {
    for (int i = 0; i < count; i++) {
        // Asumsi case-sensitive
        if (arr[i].kode == kode && arr[i].isActive) {
            return &arr[i]; // Return pointer ke barang yang ditemukan
        }
    }
    return nullptr; // Tidak ditemukan
}

// Menampilkan semua barang
void tampilSemuaBarang(Barang arr[], int count) {
    cout << "------------------------------------------------------------------\n";
    cout << "| " << setw(10) << left << "Kode" 
         << "| " << setw(20) << left << "Nama" 
         << "| " << setw(15) << left << "Harga (Rp)" 
         << "| " << setw(10) << left << "Stok" << " |\n";
    cout << "------------------------------------------------------------------\n";
    
    bool ada = false;
    for (int i = 0; i < count; i++) {
        if (arr[i].isActive) {
            ada = true;
            cout << "| " << setw(10) << left << arr[i].kode 
                 << "| " << setw(20) << left << arr[i].nama 
                 << "| " << setw(15) << left << arr[i].harga 
                 << "| " << setw(10) << left << arr[i].stok << " |\n";
        }
    }
    
    if (!ada) {
        cout << "| " << setw(61) << left << "Data barang kosong!" << " |\n";
    }
    cout << "------------------------------------------------------------------\n";
}

// Mengurangi stok barang ketika ada transaksi
bool kurangiStok(Barang arr[], int count, string kode, int jumlah) {
    Barang* b = cariBarangByKode(arr, count, kode);
    if (b != nullptr) {
        if (b->stok >= jumlah) {
            b->stok -= jumlah;
            return true;
        }
    }
    return false;
}
