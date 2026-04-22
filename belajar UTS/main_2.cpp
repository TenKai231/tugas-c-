#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

void TambakanData (int nilai) {
    Node* baru = new Node();
    baru->next = NULL;
    baru->data = nilai;

    if (head == NULL) {
        head = baru;
    }else {
        Node* temp = head;
        while (temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void tampilkanData () {
    Node* temp = head;
    if (temp == NULL) {
        cout << "Data kosong\n";
        return;
    }

    while ( temp != NULL) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void hapusData (int nilai) {
    Node* temp = head;
    Node* prev = NULL;

    if (temp != NULL && temp->data == nilai) {
        head = temp->next;
        delete temp;
        cout << "Data Berhasil Di Hapus\n" ;
        return;
    }
    while (temp != NULL && temp->data != nilai)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Data Tidak di Temukan\n";
        return;
    }
    
    prev->next = temp->next;
    delete temp;

    cout << "Data Berhasil di Hapus\n";
}

int main() {
    
    int piliha,data,nilai;
    
    do {
        cout << "Proggram pengram data sederhana"  << endl;
        cout << "\n1. Tambahkan Data" ; 
        cout << "\n2. Tampilkan Data" ; 
        cout << "\n3. Hapus Data" ; 
        cout << "\n4. Keluar\n";
        cout << "pilih Proggram yang anda akan gunakan : ";
        cin >> piliha;
        switch (piliha)
        {
        case 1:
            cout << "Masukan data : " ;
            cin >> data;
            TambakanData(data);
            break;
        case 2:
            cout << "menapilakan Data yang tersedia\n";
            tampilkanData();
            break;
        case 3:
            tampilkanData();
            cout << "pilih data yang igin kamu hapus";
            cin >>  nilai;
            hapusData(nilai);
            tampilkanData();
            break;
        default:
            break;
        }
    }while (piliha != 4); 
    return 0;
}