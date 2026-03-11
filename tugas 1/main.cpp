#include <print>
#include <string>
#include <iostream>

int main() {
    std::string nama;
    std::print("Masukkan nama Abang: ");
    std::cin >> nama;
    std::println("Halo {}, semangat belajar C++23 nya!", nama);
    return 0;
}