#include<iostream>
using namespace std;

void functionB(int n); // Deklarasi fungsi functionB

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1); // Panggilan rekursif tidak langsung
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2); // Panggilan rekursif tidak langsung
    }
}

int main() { // Memperbaiki penulisan 'int main'
    int num = 5; // Memperbaiki penulisan 'int num = 5'
    cout << "Rekursif Tidak Langsung: "; // Memperbaiki penulisan string
    functionA(num);
    return 0; // Memperbaiki penulisan 'return 0'
}
