#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "Masukkan nilai a, b, c: ";
    cin >> a >> b >> c;

    double D = b*b - 4*a*c; // diskriminan

    if (D > 0) {
        double x1 = (-b + sqrt(D)) / (2*a);
        double x2 = (-b - sqrt(D)) / (2*a);
        cout << "Akar-akar berbeda:\n";
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    } 
    else if (D == 0) {
        double x = -b / (2*a);
        cout << "Akar kembar: x = " << x << endl;
    } 
    else {
        cout << "Tidak memiliki akar real." << endl;
    }

    return 0;
}
