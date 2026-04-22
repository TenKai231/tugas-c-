#include <iostream>
using namespace std;

int main (){
    int nilai;
    cout << "masukan nilai bilangan : " ; cin >> nilai;
    if ( nilai % 2 ) {
        cout << "nilai ya adalah ganjil";
    }else {
        cout << "nilai ya adalah genap";
    };

    return 0;
}