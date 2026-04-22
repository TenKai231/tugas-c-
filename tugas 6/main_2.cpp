#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Node {
    string keterangan;
    long long jumlahUang;
    Node* next;
};

// Insert Akhir
void tambahTransaksi(Node*& head, string keterangan, long long jumlahUang) {
    Node* newNode = new Node;
    newNode->keterangan = keterangan;
    newNode->jumlahUang = jumlahUang;
    newNode->next = nullptr;
    
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Tampilkan Semua Transaksi
void tampilkanSemua(Node* head) {
    if (head == nullptr) {
        cout << "Tidak ada transaksi." << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->keterangan << " -> " << temp->jumlahUang << endl;
        temp = temp->next;
    }
}

// Tampilkan transaksi lebih dari 5,000,000
void tampilkanLebihDari5Juta(Node* head) {
    if (head == nullptr) {
        cout << "Tidak ada transaksi." << endl;
        return;
    }
    Node* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->jumlahUang > 5000000) {
            cout << temp->keterangan << " -> " << temp->jumlahUang << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Tidak ada transaksi yang lebih dari 5.000.000" << endl;
    }
}

// Hitung total saldo dan jumlah transaksi
void hitungTotal(Node* head, long long saldoAwal = 0) {
    long long totalPengeluaran = 0;
    int jumlahTransaksi = 0;
    
    Node* temp = head;
    while (temp != nullptr) {
        totalPengeluaran += temp->jumlahUang;
        jumlahTransaksi++;
        temp = temp->next;
    }
    cout << "Total pengeluaran : " << totalPengeluaran << endl;
    cout << "Jumlah transaksi  : " << jumlahTransaksi << endl;
    // Asumsi jika ini pengeluaran, saldo bisa saldoAwal - totalPengeluaran
    // Atau jika hanya mau menampilkan total
    cout << "Sisa Saldo        : " << (saldoAwal - totalPengeluaran) << endl;
}

// Hapus transaksi dengan nilai uang tertentu
void hapusTransaksi(Node*& head, long long targetHapus) {
    if (head == nullptr) {
        cout << "Data kosong, tidak ada yang dihapus." << endl;
        return;
    }
    
    // Hapus di awal
    while (head != nullptr && head->jumlahUang == targetHapus) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Berhasil menghapus transaksi di awal dengan nilai " << targetHapus << endl;
    }
    
    if (head == nullptr) return;
    
    // Hapus di tengah/akhir
    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->jumlahUang == targetHapus) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Berhasil menghapus transaksi dengan nilai " << targetHapus << endl;
        } else {
            current = current->next;
        }
    }
}

// Cari transaksi
void cariTransaksi(Node* head, long long targetCari) {
    if (head == nullptr) {
        cout << "Data kosong." << endl;
        return;
    }
    Node* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->jumlahUang == targetCari) {
            cout << "Ditemukan: " << temp->keterangan << " -> " << temp->jumlahUang << endl;
            found = true;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Transaksi dengan nilai " << targetCari << " tidak ditemukan." << endl;
    }
}

int main(){
    cout << "Rama Ferdiansyah" << endl;
    cout << "09020282529067" << endl;
    cout << "PROGRAM TRANSAKSI MENGGUNAKAN LINKED LIST\n" << endl;
    
    Node* head = nullptr;
    string nim = "09020282529067";
    int digitTerakhir = nim[nim.length() - 1] - '0';
    
    // Target hapus (7000000) dan Target cari (70000)
    long long targetHapus = digitTerakhir * 1000000; 
    long long targetCari = digitTerakhir * 10000;
    
    // Saldo awal opsional (misal bebas 50.000.000)
    long long saldoAwal;
    cout << "Berapa Gaji / Saldo Awal anda: ";
    cin >> saldoAwal;
    
    int jumlahInput;
    cout << "Berapa banyak transaksi yang ingin diinput di awal? (Bisa kurang dari 14 agar tidak terlalu panjang): ";
    cin >> jumlahInput;
    cin.ignore(); // Bersihkan buffer input

    cout << "\n--- INPUT TRANSAKSI AWAL ---" << endl;
    for (int i = 0; i < jumlahInput; i++) {
        string ket;
        long long uang;
        cout << "Transaksi " << i + 1 << " - Keterangan : ";
        getline(cin, ket);
        cout << "Transaksi " << i + 1 << " - Jumlah uang: ";
        cin >> uang;
        cin.ignore();
        tambahTransaksi(head, ket, uang);
    }
    
    int pilihan;
    do {
        cout << "\n===== MENU TRANSAKSI =====" << endl;
        cout << "1. Tambah Transaksi (Insert Akhir)" << endl;
        cout << "2. Tampilkan Semua Transaksi" << endl;
        cout << "3. Tampilkan Transaksi > 5.000.000" << endl;
        cout << "4. Hitung Total & Sisa Saldo" << endl;
        cout << "5. Hapus Transaksi (Target: " << targetHapus << ")" << endl;
        cout << "6. Cari Transaksi (Target: " << targetCari << ")" << endl;
        cout << "7. Tambah Gaji / Saldo" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih opsi : ";
        cin >> pilihan;
        cin.ignore(); // Bersihkan buffer input
        
        if (pilihan == 1) {
            string ket;
            long long uang;
            cout << "Keterangan : ";
            getline(cin, ket);
            cout << "Jumlah uang: ";
            cin >> uang;
            tambahTransaksi(head, ket, uang);
            cout << "Transaksi berhasil ditambahkan." << endl;
        } 
        else if (pilihan == 2) {
            cout << "\n--- DATA TRANSAKSI ---" << endl;
            tampilkanSemua(head);
        }
        else if (pilihan == 3) {
            cout << "\n--- TRANSAKSI > 5.000.000 ---" << endl;
            tampilkanLebihDari5Juta(head);
        }
        else if (pilihan == 4) {
            cout << "\n--- REKAP SALDO ---" << endl;
            hitungTotal(head, saldoAwal);
        }
        else if (pilihan == 5) {
            cout << "\n--- HAPUS TRANSAKSI ---" << endl;
            hapusTransaksi(head, targetHapus);
        }
        else if (pilihan == 6) {
            cout << "\n--- CARI TRANSAKSI ---" << endl;
            cariTransaksi(head, targetCari);
        }
    } while (pilihan != 0);
    
    return 0;
}













/* 
    jumlaha transksi awal - digital trnakaski NIM + 3
    nim = 09020282529067 -> jumlah transaksi = 14 (sesuai jumlah digit NIM)
    ini mengunakan linked list untuk menyimpan data transaksi dengan fitur insert akhir, kemudian menampilkan semua transaksi yang lebih dari gaji > 5000000,
    buat lah trnaksais C++ dengan fitur 
    tambahakan transaksi (insert akhir )
    input :
    ketergaan : jumlah uang 

    tampilkan semua transkasi lebih dari gaji > 5000000
    belanaja -> 2000000
    transportasi -> 50000
    
    dan hitunglah totoal salndo dan jumalah totoal tranaskasi dan juga hapus transksi dengan aturan hapus tranaksi dnegan digit trerakhir NIM, misal hapus transaksi dengan digit terakhir NIM 7 maka hapus transaksi dengan jumlah uang 7000000
    cara trnasaski cari berdasarkan jumlah digit terakhir NIM X 10000
    buat dalam fungsi yah dan juga looping jagan langsung di totak simapa di dalam link list 

    cari trnaksi cari berdasarkan jumalah digit terakhir NIM X 10000 dan hasil ya akan tidak di temukan jika tidak ada transaksi dengan jumlah uang sesuai target cari, dan tampilkan data transaksi jika ditemukan
*/