#include "../includes/Transaksi.h"
#include "../includes/utils.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Menambahkan transaksi baru ke tail (akhir) linked list
void insertTransaksi(Node*& head, string kode, string nama, int harga, int qty) {
    Node* newNode = new Node;
    newNode->kodeBarang = kode;
    newNode->namaBarang = nama;
    newNode->hargaSatuan = harga;
    newNode->jumlah = qty;
    newNode->subtotal = harga * qty;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// Menghitung total belanja dari list transaksi (tanpa diskon)
int hitungTotal(Node* head) {
    int total = 0;
    Node* curr = head;
    while (curr != nullptr) {
        total += curr->subtotal;
        curr = curr->next;
    }
    return total;
}

// Mencetak struk belanja
void cetakStruk(Node* head, int totalAkhir) {
    cout << "\n====================================================\n";
    cout << "               STRUK BELANJA MINI MARKET            \n";
    cout << "====================================================\n";
    cout << setw(15) << left << "Nama Barang" 
         << setw(10) << left << "Qty" 
         << setw(15) << left << "Harga" 
         << setw(15) << left << "Subtotal" << "\n";
    cout << "----------------------------------------------------\n";
    
    Node* curr = head;
    while (curr != nullptr) {
        cout << setw(15) << left << curr->namaBarang 
             << setw(10) << left << curr->jumlah 
             << setw(15) << left << formatRupiah(curr->hargaSatuan) 
             << setw(15) << left << formatRupiah(curr->subtotal) << "\n";
        curr = curr->next;
    }
    
    cout << "----------------------------------------------------\n";
    cout << setw(40) << right << "TOTAL TAGIHAN: " << formatRupiah(totalAkhir) << "\n";
    cout << "====================================================\n";
    cout << "            TERIMA KASIH ATAS KUNJUNGAN ANDA        \n";
    cout << "====================================================\n";
}

// Membersihkan semua node pada linked list
void hapusSemuaTransaksi(Node*& head) {
    Node* curr = head;
    while (curr != nullptr) {
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    head = nullptr; // Reset head
}
