#ifndef TRANSAKSI_H
#define TRANSAKSI_H
#include <string>

using namespace std;

struct Node {
    string kodeBarang;
    string namaBarang;
    int hargaSatuan;
    int jumlah;
    int subtotal;
    Node* next;
};

// Fungsi deklarasi
void insertTransaksi(Node*& head, string kode, string nama, int harga, int qty);
int hitungTotal(Node* head);
void cetakStruk(Node* head, int totalAkhir);
void hapusSemuaTransaksi(Node*& head);

#endif
