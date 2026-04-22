#include "../includes/utils.h"
#include <iostream>
#include <limits>
#include <cstdlib>

using namespace std;

// Opsional: Format integer ke string Rupiah sederhana
string formatRupiah(int nominal) {
    return "Rp. " + to_string(nominal); 
}

// Membersihkan console screen
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Pause screen waiting for input
void pauseScreen() {
    cout << "\nTekan Enter untuk kembali ke menu...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Meminta input integer dan menangani bila user input string/char
int getValidIntInput() {
    int value;
    while (true) {
        if (cin >> value) {
            break;
        } else {
            cout << "[Error] Input harus berupa angka. Coba lagi: ";
            cin.clear(); // Hapus flag error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Abaikan sisa input
        }
    }
    return value;
}
