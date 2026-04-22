#ifndef BARANG_H
#define BARANG_H
#include <string>

using namespace std;

const int MAX_BARANG = 100;

struct Barang {
    string kode;
    string nama;
    int harga;
    int stok;
    bool isActive;
};

// Fungsi deklarasi
void initBarang(Barang arr[], int& count);
bool tambahBarang(Barang arr[], int& count, Barang baru);
Barang* cariBarangByKode(Barang arr[], int count, string kode);
void tampilSemuaBarang(Barang arr[], int count);
bool kurangiStok(Barang arr[], int count, string kode, int jumlah);

#endif
