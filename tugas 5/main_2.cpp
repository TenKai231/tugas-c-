#include <iostream>
using namespace std;

int main() {
    int arr[20];
    int n = 0, pilihan, cari, index;

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
            if (n < 20) {
                cout << "Masukkan data: ";
                cin >> arr[n];
                n++;
            } else {
                cout << "Array penuh!";
            }
            break;

        case 2:
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            break;

        case 3:
            cout << "Data yang dicari: ";
            cin >> cari;
            index = -1;

            for (int i = 0; i < n; i++) {
                if (arr[i] == cari) {
                    index = i;
                    break;
                }
            }

            if (index != -1)
                cout << "Data ditemukan di index " << index;
            else
                cout << "Data tidak ditemukan";
            break;

        case 4:
            cout << "Index yang dihapus: ";
            cin >> index;

            if (index >= 0 && index < n) {
                for (int i = index; i < n-1; i++)
                    arr[i] = arr[i+1];
                n--;
            }
            break;

        case 5:
            cout << "Index yang diedit: ";
            cin >> index;

            if (index >= 0 && index < n) {
                cout << "Data baru: ";
                cin >> arr[index];
            }
            break;
        }

    } while (pilihan != 6);

    return 0;
}