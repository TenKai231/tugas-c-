#include <iostream>
#include <array>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void tambahData(int nilai){
    Node* baru = new Node();
    baru->next = NULL;
    baru->data = nilai;

    if(head == NULL) {
        head = baru;
    }else {
        Node * temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void tampilkanData () {
    Node* temp = head;
    if (temp == NULL) {
        cout << "Data Kosong\n";
        return;
    }

    while(temp != NULL) {
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
            cout << "Data di temukan " << index << endl;
            ditemukan = true;
            break;
        }
        temp = temp->next;
        index++;
    }

    if(!ditemukan)
        cout << "Data tidak di temukan\n";
}

void hapusData(int nilai) {
    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == nilai) {
        head = temp->next;
        delete temp;
        cout << "Data berhasil di hapus\n";
        return;
    }

    while (temp != NULL && temp->data != nilai) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Data Berhasil di hapus\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    
    cout << "Data Berhasil di Hapus\n";
}

void editData(int index, int nilaiBaru) {
    Node* temp = head;

    for (int i = 0; temp != NULL && i < index; i++) {
        temp = temp->next;
    }
    
    if(temp != NULL) 
        temp->data = nilaiBaru;
}

int main(){
    int pilihan, data, index;
    
    do {
        cout << "\n1. Tambahakan Data";
        cout << "\n2. Tampilkan Data";
        cout << "\n3. Cari Data";
        cout << "\n4. Hapus Data";
        cout << "\n5. Edit Data";
        cout << "\n6. Keluar\n";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukan data: ";
                cin >> data;
                tambahData(data);
                break;
            case 2:
                tampilkanData();
                break;
            case 3:
                cout << "Dataa yang dicari: ";
                cin >> data;
                cariData(data);
                break;
            case 4:
                cout << "index yang di hapus: ";
                cin >> index;
                hapusData(index);
                break;
            case 5:
                cout << "index yang diedit: ";
                cin >> index;
                cout << "Data baru: ";
                cin >> data;
                editData(index,data);
                break;
        }
    }while (pilihan !=6);
    
    return 0;
}