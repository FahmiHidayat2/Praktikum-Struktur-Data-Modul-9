#include <iostream>

// Fungsi untuk menghitung faktorial menggunakan rekursi langsung
long long faktorial(int n) {
    if 
        (n == 0 || n== 1) 
        return 1;
    else // basis rekursi
        return n * faktorial(n - 1); // rekursi
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
