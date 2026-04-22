#include <iostream>
using namespace std;

struct Node {
    int nomor;
    Node* next;
};

Node* head = NULL;

void tambahPasien(int nomor) {
    Node* baru = new Node();
    baru->nomor = nomor;
    baru->next = NULL;

    if(head == NULL) { 
        head = baru;
    } else {
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void tampilAntrian() {
    Node* temp = head;

    if(temp == NULL) {
        cout << "Antrian kosong\n";
        return;
    }

    cout << "Daftar Antrian:\n";
    while(temp != NULL) {
        cout << "Nomor: " << temp->nomor << endl;
        temp = temp->next;
    }
}

void panggilPasien() {
    if(head == NULL) {
        cout << "Tidak ada pasien\n";
        return;
    }

    Node* hapus = head;
    cout << "Memanggil pasien nomor: " << hapus->nomor << endl;

    head = head->next;
    delete hapus;
}

int main() {
    int pilihan, nomor;

    do {
        cout << "\n1. Tambah Pasien\n";
        cout << "2. Tampilkan Antrian\n";
        cout << "3. Panggil Pasien\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;
        switch(pilihan) {
            case 1:
                cout << "Masukkan nomor antrian: ";
                cin >> nomor;
                tambahPasien(nomor);
                break;

            case 2:
                tampilAntrian();
                break;

            case 3:
                panggilPasien();
                break;
        }

    } while(pilihan != 4);

    return 0;
}