# SMARTCASHIER MINI MARKET

Proyek ini adalah implementasi sistem kasir sederhana untuk minimarket menggunakan bahasa ++. Aplikasi ini membuktikan penggunaan:
- **Raw Array** untuk manajemen data barang (`statis`)
- **Raw Linked List** untuk manajemen data transaksi (`dinamis`)

## Kriteria Terpenuhi
Semua fitur Wajib (Core) telah diimplementasikan:
- [x] Tambah Barang
- [x] Lihat Barang
- [x] Cari Barang
- [x] Transaksi Beli (Mengurangi Stok Barang, Data masuk ke Keranjang List)
- [x] Hitung Total
- [x] Cetak Struk
- [x] Exit + Cleanup Linked List

Fitur Bonus (Level 2):
- [x] Diskon Bertingkat ( >200rb Diskon 15%, >100rb Diskon 10% )
- [x] Validasi Input Angka yang stabil

## Cara Compile & Run
Aplikasi ini sudah dipecah secara modular: `main.cpp`, `Barang.cpp`, `Transaksi.cpp`, dan `utils.cpp`.

Buka Terminal/CMD, arahkan ke folder `kasir-project` dan jalankan command ini:

```bash
# Compile (menggunakan g++)
g++ -std=c++11 -Wall -Wextra -o kasir main.cpp src/Barang.cpp src/Transaksi.cpp src/utils.cpp

# Run Windows (MSYS2/MinGW)
./kasir.exe

# Run Linux/WSL
./kasir
```

## Struktur File
```
kasir-project/
├── main.cpp              // Entry point
├── includes/
│   ├── Barang.h          // Deklarasi fungsi barang
│   ├── Transaksi.h       // Deklarasi fungsi linked list keranjang
│   └── utils.h           // Utilitas umum (clear, format rupiah, validasi int)
├── src/
│   ├── Barang.cpp        // Implementasi logika manajemen array barang
│   ├── Transaksi.cpp     // Implementasi linked list transaksi belanja
│   └── utils.cpp         // Implementasi utils
└── README.md             // Cara kompilasi dan informasi project
```

## Coba Test Case:
1. Jalankan program, `BRG001` (Indomie) dan `BRG002` (Teh Pucuk) sudah dibekalkan.
2. Tambahkan barang baru -> **Menu 1**
3. Cek barang yang ditambahkan -> **Menu 2**
4. Cari barang khusus -> **Menu 3**
5. Lakukan transaksi, pastikan saldo pembelian lebih dari Rp 100.000 (misalnya beli barang Rp 3.500 qty = 30) -> **Menu 4**.  Pastikan diskon berhasil teraplikasi!
6. Exit (**Menu 5**) dengan clean tanpa error memory leak.
