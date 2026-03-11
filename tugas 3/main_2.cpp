#include <print>
#include <iostream>
using namespace std;

int main (){
    int i=0, a, b, c;
    println("Program mancari Bilangan Terbesar dari 3 buah bilangan");
    while(i<1){
        print("Masukan nilai A:"); cin >> a;
        print("Masukan nilai B:"); cin >> b;
        print("Masukan nilai C:"); cin >> c;
        if ( a < b && a < c ){
            println("bilangan terkecil adalah {}", a ); 
        }else if (a < b && b < c){
            println("bilangan terkecil adalah {}", b ); 
        }else if (c < a && c < b){
            println("bilangan terkecil adalah {}", c ); 
        }

    println(" ");
    string x;
    print("Coba Lagi (y/n) ? "); cin >> x;
    if (x == "y"){
        b = 0;
    } else if ( x == "n"){
        i = 1;
    }
    println(" ");
    }
    return 0;
}