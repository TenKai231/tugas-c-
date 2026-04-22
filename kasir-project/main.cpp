#include <iostream>
#include <string>
#include "includes/Barang.h"
#include "includes/Transaksi.h"
#include "includes/utils.h"

using namespace std;

Barang database[MAX_BARANG];
int jumlahBarang = 0;
Node* headTransaksi = nullptr;

void tampilMenu() {
    clearScreen();
    cout << "=======================================\n";
    cout << "      SMARTCASHIER MINI MARKET         \n";
    cout << "=======================================\n";
    cout << "[1] Tambah Barang\n";
    cout << "[2] Lihat Barang\n";
    cout << "[3] Cari Barang\n";
    cout << "[4] Transaksi\n";
    cout << "[5] Keluar\n";
    cout << "=======================================\n";
    cout << "Pilih Menu: ";
}

void menuTambahBarang() {
    clearScreen();
    cout << "--- TAMBAH BARANG ---\n";
    Barang btn;
    cout << "Kode Barang: ";
    cin >> btn.kode;
    
    // Validasi apakah kode sudah ada
    if (cariBarangByKode(database, jumlahBarang, btn.kode) != nullptr) {
        cout << "[Warning] Kode barang sudah ada!\n";
        return;
    }
    
    cout << "Nama Barang: ";
    cin.ignore();
    getline(cin, btn.nama);
    
    cout << "Harga (Rp): ";
    btn.harga = getValidIntInput();
    
    cout << "Stok Awal: ";
    btn.stok = getValidIntInput();

    btn.isActive = true;

    if (tambahBarang(database, jumlahBarang, btn)) {
        cout << "[Sukses] Barang berhasil ditambahkan.\n";
    } else {
        cout << "[Gagal] Database penuh.\n";
    }
}

void menuLihatBarang() {
    clearScreen();
    cout << "--- DAFTAR BARANG ---\n";
    tampilSemuaBarang(database, jumlahBarang);
}

void menuCariBarang() {
    clearScreen();
    cout << "--- CARI BARANG ---\n";
    string kode;
    cout << "Masukkan Kode Barang: ";
    cin >> kode;
    
    Barang* hasil = cariBarangByKode(database, jumlahBarang, kode);
    if (hasil != nullptr) {
        cout << "\n[Barang Ditemukan]\n";
        cout << "Kode  : " << hasil->kode << "\n";
        cout << "Nama  : " << hasil->nama << "\n";
        cout << "Harga : " << formatRupiah(hasil->harga) << "\n";
        cout << "Stok  : " << hasil->stok << "\n";
    } else {
        cout << "\n[Barang Tidak Ditemukan]\n";
    }
}

void menuTransaksi() {
    clearScreen();
    cout << "--- TRANSAKSI KASIR ---\n";
    
    char lanjut;
    do {
        string kode;
        cout << "\nKode Barang: ";
        cin >> kode;
        
        Barang* barang = cariBarangByKode(database, jumlahBarang, kode);
        if (barang == nullptr) {
            cout << "[Error] Barang tidak ditemukan.\n";
        } else {
            cout << "Nama  : " << barang->nama << "\n";
            cout << "Stok  : " << barang->stok << "\n";
            cout << "Harga : " << formatRupiah(barang->harga) << "\n";
            
            cout << "Jumlah Beli: ";
            int qty = getValidIntInput();
            
            if (qty > barang->stok) {
                cout << "[Error] Stok tidak cukup!\n";
            } else if (qty <= 0) {
                cout << "[Error] Jumlah beli harus lebih dari 0.\n";
            } else {
                // Kurangi stok dan masukkan ke keranjang
                barang->stok -= qty;
                insertTransaksi(headTransaksi, kode, barang->nama, barang->harga, qty);
                cout << "[Sukses] Barang ditambahkan ke keranjang.\n";
            }
        }
        
        cout << "Tambah barang lain? (y/n): ";
        cin >> lanjut;
    } while (lanjut == 'Y' || lanjut == 'y');

    if (headTransaksi == nullptr) {
        cout << "Transaksi dibatalkan karena keranjang kosong.\n";
        return;
    }

    // Hitung total dan cetak struk
    clearScreen();
    int total = hitungTotal(headTransaksi);
    int diskon = 0;
    
    // Bonus 1: Diskon bertingkat
    if (total > 200000) {
        diskon = total * 0.15; // 15%
    } else if (total > 100000) {
        diskon = total * 0.10; // 10%
    }
    
    int totalAkhir = total - diskon;
    cetakStruk(headTransaksi, totalAkhir);
    
    if (diskon > 0) {
        cout << "Wow, Anda mendapat diskon: " << formatRupiah(diskon) << "\n";
    }
    
    // Clears keranjang
    hapusSemuaTransaksi(headTransaksi);
}

int main() {
    initBarang(database, jumlahBarang);
    
    // Seed data untuk test (Bisa dihapus)
    tambahBarang(database, jumlahBarang, {"BRG001", "Indomie Goreng", 3500, 50, true});
    tambahBarang(database, jumlahBarang, {"BRG002", "Teh Pucuk", 4000, 30, true});

    int pilihan;
    do {
        tampilMenu();
        pilihan = getValidIntInput();
        
        switch (pilihan) {
            case 1:
                menuTambahBarang();
                pauseScreen();
                break;
            case 2:
                menuLihatBarang();
                cin.ignore(); // handle previous enter key
                pauseScreen();
                break;
            case 3:
                menuCariBarang();
                cin.ignore(); 
                pauseScreen();
                break;
            case 4:
                menuTransaksi();
                cin.ignore();
                pauseScreen();
                break;
            case 5:
                cout << "Keluar dari program... Membersihkan memori...\n";
                if (headTransaksi != nullptr) {
                    hapusSemuaTransaksi(headTransaksi);
                }
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi.\n";
                cin.ignore();
                pauseScreen();
                break;
        }
    } while (pilihan != 5);

    return 0;
}
