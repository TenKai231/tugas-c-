#include <iostream>
using namespace std;

const int MAX = 100;

int matrix[MAX][MAX];
char nodeName[MAX];
int n;

// Menampilkan matrix
void tampilMatrix()
{
    cout << "\nAdjacency Matrix:\n\n";

    cout << "  ";

    for (int i = 0; i < n; i++)
    {
        cout << nodeName[i] << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << nodeName[i] << " ";

        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}


void tampilKoneksi()
{
    cout << "\nPenjelasan Koneksi Node:\n\n";

    for (int i = 0; i < n; i++)
    {
        bool adaKoneksi = false;

        for (int j = 0; j < n; j++)
        {
            // Hindari node terhubung ke dirinya sendiri
            if (matrix[i][j] == 1 && i != j)
            {
                cout << "Node "
                     << nodeName[i]
                     << " terhubung dengan "
                     << nodeName[j]
                     << endl;

                adaKoneksi = true;
            }
        }

        // Kalau tidak ada koneksi
        if (!adaKoneksi)
        {
            cout << "Node "
                 << nodeName[i]
                 << " tidak memiliki koneksi"
                 << endl;
        }
    }
}


int main()
{
    cout << "Masukkan jumlah node: ";
    cin >> n;

    // Nama node otomatis A B C D ...
    for (int i = 0; i < n; i++)
    {
        nodeName[i] = 'A' + i;
    }

    cout << "\nNode Graph:\n";

    for (int i = 0; i < n; i++)
    {
        cout << nodeName[i] << " ";
    }

    cout << "\n\nMasukkan adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    tampilMatrix();

    tampilKoneksi();

    return 0;
}