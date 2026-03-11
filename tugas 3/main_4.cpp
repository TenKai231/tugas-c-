#include <iostream>
#include <print>
using namespace std;



int main (){
    int alas, tinggi;
    print("Masukan tinggi persegi tiga : "); cin >> tinggi;
    print("Masukan alas persegi tiga : "  ); cin >> alas;

    int rumus = alas * tinggi / 2;

    println("nilai dari segi tiga adalah {}", rumus);

    return 0;

}