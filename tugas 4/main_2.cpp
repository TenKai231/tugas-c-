#include <iostream>
#include <cstring>
using namespace std;

int testPalindrome(char str[], int left, int right) {
    if (left >= right)
        return 1;

    if (str[left] != str[right])
        return 0;

    return testPalindrome(str, left+1, right-1);
}

int main() {
    char kata[100];

    cout << "Masukkan kata: ";
    cin >> kata;

    if (testPalindrome(kata, 0, strlen(kata)-1))
        cout << "Palindrome (1)" << endl;
    else
        cout << "Bukan Palindrome (0)" << endl;

    return 0;
}
