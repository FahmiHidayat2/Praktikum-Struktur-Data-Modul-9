#include<iostream>
using namespace std;

// Code ini berfungsi untuk melakukan hitung mundur
// dari angka yang diinputkan
void countdown(int n) {
    if (n == 0) {
        return; // Hanya perlu 'return;' karena fungsi ini bertipe void
    }
    cout << n << " "; // Menambahkan spasi untuk pemisah antar angka
    countdown(n - 1);
}

int main() {
    cout << "Rekursif Langsung: ";
    countdown(5); // 5 merupakan inputnya
    cout << endl;
    return 0;
}
