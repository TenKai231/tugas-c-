#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void tambahData(int nilai) {
    Node* baru = new Node();
    baru->data = nilai;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void tampilkanData() {
    Node* temp = head;

    if (temp == NULL) {
        cout << "Data kosong\n";
        return;
    }

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void cariData(int nilai) {
    Node* temp = head;
    int index = 0;
    bool ditemukan = false;

    while (temp != NULL) {
        if (temp->data == nilai) {
            cout << "Data ditemukan di index " << index << endl;
            ditemukan = true;
            break;
        }
        temp = temp->next;
        index++;
    }

    if (!ditemukan)
        cout << "Data tidak ditemukan\n";
}

void hapusData(int nilai) {
    Node* temp = head;
    Node* prev = NULL;

    // cek jika node pertama yang dihapus
    if (temp != NULL && temp->data == nilai) {
        head = temp->next;
        delete temp;
        cout << "Data berhasil dihapus\n";
        return;
    }

    // cari node yang berisi nilai
    while (temp != NULL && temp->data != nilai) {
        prev = temp;
        temp = temp->next;
    }

    // jika tidak ditemukan
    if (temp == NULL) {
        cout << "Data tidak ditemukan\n";
        return;
    }

    // hapus node
    prev->next = temp->next;
    delete temp;

    cout << "Data berhasil dihapus\n";
}

void editData(int index, int nilaiBaru) {
    Node* temp = head;

    for (int i = 0; temp != NULL && i < index; i++) {
        temp = temp->next;
    }

    if (temp != NULL)
        temp->data = nilaiBaru;
}

int main() {
    int pilihan, data, index;

    do {
        cout << "\n1. Tambah Data";
        cout << "\n2. Tampilkan Data";
        cout << "\n3. Cari Data";
        cout << "\n4. Hapus Data";
        cout << "\n5. Edit Data";
        cout << "\n6. Keluar";
        cout << "\nPilih: ";
        cin >> pilihan;

        switch (pilihan) {

        case 1:
            cout << "Masukkan data: ";
            cin >> data;
            tambahData(data);
            break;

        case 2:
            tampilkanData();
            break;

        case 3:
            cout << "Data yang dicari: ";
            cin >> data;
            cariData(data);
            break;

        case 4:
            cout << "Index yang dihapus: ";
            cin >> index;
            hapusData(index);
            break;

        case 5:
            cout << "Index yang diedit: ";
            cin >> index;
            cout << "Data baru: ";
            cin >> data;
            editData(index, data);
            break;
        }

    } while (pilihan != 6);

    return 0;
}