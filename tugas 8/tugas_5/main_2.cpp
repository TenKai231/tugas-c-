#include <iostream>
using namespace std;

struct Node {
    string data;
    Node* next;
};

Node* depan = NULL;
Node* belakang = NULL;

// Mobil masuk
void enqueue(string plat) {
    Node* baru = new Node();
    baru->data = plat;
    baru->next = NULL;

    if (belakang == NULL) {
        depan = belakang = baru;
    } else {
        belakang->next = baru;
        belakang = baru;
    }

    cout << "Mobil masuk: " << plat << endl;
}

// Mobil keluar
void dequeue() {
    if (depan == NULL) {
        cout << "Parkiran kosong!\n";
    } else {
        Node* hapus = depan;
        cout << "Mobil keluar: " << depan->data << endl;
        depan = depan->next;

        if (depan == NULL)
            belakang = NULL;

        delete hapus;
    }
}

// Lihat terdepan
void peek() {
    if (depan == NULL)
        cout << "Tidak ada mobil\n";
    else
        cout << "Mobil terdepan: " << depan->data << endl;
}

// Tampilkan semua
void tampil() {
    Node* temp = depan;

    if (temp == NULL) {
        cout << "Kosong\n";
    } else {
        cout << "Daftar mobil:\n";
        while (temp != NULL) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}

int main() {
    int pilih;
    string plat;

    do {
        cout << "\n=== QUEUE MOBIL (LINKED LIST) ===\n";
        cout << "1. Mobil Masuk\n";
        cout << "2. Mobil Keluar\n";
        cout << "3. Lihat Terdepan\n";
        cout << "4. Tampilkan Semua\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;
        cin.ignore();

        switch (pilih) {
            case 1:
                cout << "Nomor plat: ";
                getline(cin, plat);
                enqueue(plat);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                tampil();
                break;
        }
    } while (pilih != 5);
}