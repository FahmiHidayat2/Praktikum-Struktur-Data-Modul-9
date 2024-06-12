#include <iostream>

// Deklarasi fungsi rekursif tidak langsung
long long faktorial(int n);

// Fungsi bantuan untuk menghitung faktorial menggunakan rekursi tidak langsung
long long faktorialHelper(int n, int acc) {
    if (n == 0 || n == 1)
        return acc;
    else
        return faktorialHelper(n - 1, acc * n);
}

// Fungsi untuk menghitung faktorial menggunakan rekursi tidak langsung
long long faktorial(int n) {
    return faktorialHelper(n, 1);
}

int main() {
    int angka;
    std::cout << "Masukkan bilangan bulat positif: ";
    std::cin >> angka;

    // Memastikan bahwa angka adalah positif
    if (angka < 0) {
        std::cout << "Faktorial tidak didefinisikan untuk bilangan negatif." << std::endl;
    } else {
        long long hasil = faktorial(angka);
        std::cout << "Hasil Faktorial dari " << angka << " adalah: " << hasil << std::endl;
    }

    return 0;
}

