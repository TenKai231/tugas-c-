#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Node {
    string keterangan;
    long long jumlahUang;
    Node* next;
};

int main() {
    cout << "======================================" << endl;
    cout << "  Nama : Rama Ferdiansyah" << endl;
    cout << "  NIM  : 09020282529067" << endl;
    cout << "  PROGRAM TRANSAKSI - LINKED LIST" << endl;
    cout << "======================================\n" << endl;

    Node* head = nullptr;
    string nim = "09020282529067";
    int digitTerakhir = nim[nim.length() - 1] - '0'; // 7

    int jumlahAwal = digitTerakhir + 3;          // 10
    long long targetHapusPosisi = digitTerakhir; // hapus ke-7
    long long targetCari = digitTerakhir * 10000; // 70000

    cout << "Jumlah transaksi awal : " << jumlahAwal << " (digit terakhir NIM + 3)" << endl;

    // 1. INPUT TRANSAKSI (Insert di Akhir)
    cout << "\n--- INPUT DATA TRANSAKSI ---" << endl;
    for (int i = 1; i <= jumlahAwal; i++) {
        string ket;
        long long uang;

        cout << "Transaksi " << i << " - Keterangan : ";
        getline(cin >> ws, ket);

        cout << "Transaksi " << i << " - Jumlah uang: Rp";
        cin >> uang;

        Node* newNode = new Node;
        newNode->keterangan = ket;
        newNode->jumlahUang = uang;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
        }
    }

    // 2. TAMPILKAN SEMUA TRANSAKSI
    cout << "\n--- SEMUA DATA TRANSAKSI ---" << endl;
    Node* temp = head;
    if (temp == nullptr) cout << "Data kosong." << endl;
    int no = 1;
    while (temp != nullptr) {
        cout << no++ << ". " << temp->keterangan << " -> Rp" << temp->jumlahUang << endl;
        temp = temp->next;
    }

    // 3. HITUNG TOTAL & JUMLAH TRANSAKSI
    cout << "\n--- TOTAL TRANSAKSI ---" << endl;
    temp = head;
    long long totalUang = 0;
    int jumlahData = 0;
    while (temp != nullptr) {
        totalUang += temp->jumlahUang;
        jumlahData++;
        temp = temp->next;
    }
    cout << "Jumlah Total Transaksi : " << jumlahData << endl;
    cout << "Total Uang Pengeluaran : Rp" << totalUang << endl;

    // 4. HAPUS TRANSAKSI KE- (digit terakhir NIM = ke-7)
    cout << "\n--- MENGHAPUS DATA KE-" << targetHapusPosisi << " ---" << endl;
    if (head == nullptr) {
        cout << "Gagal menghapus, data kosong." << endl;
    } else if (targetHapusPosisi == 1) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        cout << "Data ke-1 berhasil dihapus." << endl;
    } else {
        Node* prev = nullptr;
        Node* curr = head;
        int pos = 1;
        while (curr != nullptr && pos < targetHapusPosisi) {
            prev = curr;
            curr = curr->next;
            pos++;
        }
        if (curr == nullptr) {
            cout << "Data ke-" << targetHapusPosisi << " tidak ditemukan." << endl;
        } else {
            prev->next = curr->next;
            delete curr;
            cout << "Data ke-" << targetHapusPosisi << " berhasil dihapus." << endl;
        }
    }

    // Tampilkan setelah dihapus
    cout << "\n--- DATA SETELAH DIHAPUS ---" << endl;
    temp = head;
    if (temp == nullptr) cout << "Data kosong." << endl;
    no = 1;
    while (temp != nullptr) {
        cout << no++ << ". " << temp->keterangan << " -> Rp" << temp->jumlahUang << endl;
        temp = temp->next;
    }

    // 5. CARI TRANSAKSI = targetCari (70000)
    cout << "\n--- CARI TRANSAKSI Rp" << targetCari << " ---" << endl;
    temp = head;
    bool ketemu = false;
    while (temp != nullptr) {
        if (temp->jumlahUang == targetCari) {
            cout << "Ditemukan: " << temp->keterangan << " -> Rp" << temp->jumlahUang << endl;
            ketemu = true;
        }
        temp = temp->next;
    }
    if (!ketemu) {
        cout << "Transaksi Rp" << targetCari << " tidak ditemukan." << endl;
    }

    return 0;
}