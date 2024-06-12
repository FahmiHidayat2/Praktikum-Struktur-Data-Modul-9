# <h1 align="center">Laporan Praktikum Modul Rekursif dan Hash Table</h1>
<p align="center">Fahmi Hidayat</p>

## Dasar Teori
### Rekursif
Rekursi adalah teknik dalam pemrograman di mana sebuah fungsi memanggil dirinya sendiri untuk menyelesaikan tugas. Ketika fungsi dipanggil, ia menyelesaikan bagian kecil dari tugas tersebut dan kemudian memanggil dirinya sendiri dengan masalah yang lebih sederhana atau lebih kecil. Proses ini terus berlanjut sampai masalah mencapai kasus dasar yang dapat langsung dipecahkan. Rekursi sangat berguna dalam memecahkan masalah yang dapat dipecahkan secara rekursif, seperti pencarian dalam struktur data berhirarki (seperti pohon atau graf), algoritma pembagian dan penaklukkan, dan banyak lagi. Namun, penggunaan rekursi harus hati-hati agar tidak mengakibatkan stack overflow atau kinerja yang buruk karena overhead yang terkait dengan memanggil fungsi secara berulang.

Algoritma rekursif merupakan metode yang baik serta efektif diekspresikan sebagai rangkaian terbatas untuk melakukan suatu perintah. Algoritma Rekursif terdiri dari dua kata yaitu algoritma dan rekursif [1]. Dimana algoritma menurut Gun Gun Maulana merupakan metode efektif yang diekspresikan sebagai rangkaian terbatas. Algoritma juga merupakan kumpulan perintah untuk menyelesaikan masalah

### Hash Table
Hash Table adalah struktur data yang digunakan untuk menyimpan kumpulan pasangan kunci-nilai (key-value pairs) di mana pengambilan (retrieval) dan penyisipan (insertion) data dilakukan dengan sangat cepat. Ini mencapai kecepatan tersebut dengan menggunakan fungsi hash, yang mengonversi kunci ke indeks dalam struktur penyimpanan yang disebut tabel hash. Keuntungan utama hash table adalah kecepatan akses konstan (O(1)) untuk pengambilan dan penyisipan elemen, tergantung pada implementasinya. Namun, dalam beberapa kasus, tabrakan hash (collision) dapat terjadi ketika dua kunci menghasilkan indeks yang sama, dan solusi untuk tabrakan ini (seperti chaining atau probing) perlu dipertimbangkan agar hash table tetap efisien dan andal. Hash table banyak digunakan dalam bahasa pemrograman dan aplikasi, seperti dalam pengindeksan dalam database, implementasi struktur data seperti set dan kamus, dan algoritma pencocokan pola.

## Guided 

### 1. Guided 1

```C++
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
```
### 2. Guided 2
```c++
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
```

### 3. Guided 3 
```c++
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int TABLE_SIZE = 11; // Ukuran tabel hash

// Kelas untuk menyimpan node hash
class HashNode {
public:
    string name; // Nama kunci
    string phone_number; // Nomor telepon sebagai nilai

    // Konstruktor untuk inisialisasi nama dan nomor telepon
    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

// Kelas untuk struktur data hash map
class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE]; // Array dari vektor untuk tabel hash

public:
    // Fungsi hash untuk menghitung nilai hash dari kunci
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c; // Menambahkan nilai ASCII dari setiap karakter
        }
        return hash_val % TABLE_SIZE; // Menggunakan modulo untuk mendapatkan indeks
    }

    // Fungsi untuk memasukkan pasangan kunci-nilai ke dalam hash map
    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name); // Menghitung hash dari nama
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number; // Update nomor telepon jika nama sudah ada
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number)); // Menambahkan node baru jika nama belum ada
    }

    // Fungsi untuk menghapus node berdasarkan nama
    void remove(string name) {
        int hash_val = hashFunc(name); // Menghitung hash dari nama
        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it); // Menghapus node
                return;
            }
        }
    }

    // Fungsi untuk mencari nomor telepon berdasarkan nama
    string searchByName(string name) {
        int hash_val = hashFunc(name); // Menghitung hash dari nama
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number; // Mengembalikan nomor telepon jika ditemukan
            }
        }
        return ""; // Mengembalikan string kosong jika tidak ditemukan
    }

    // Fungsi untuk mencetak semua isi hash table
    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]"; // Mencetak nama dan nomor telepon
                }
            }
            cout << endl;
        }
    }
};

// Fungsi utama
int main() {
    HashMap employee_map;
    employee_map.insert("Mistah", "1234"); // Memasukkan data
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    // Mencetak nomor telepon berdasarkan nama
    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;
    cout << "Phone Hp Ghana : " << employee_map.searchByName("Ghana") << endl;

    employee_map.remove("Mistah"); // Menghapus data
    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;
    employee_map.print(); // Mencetak seluruh hash table

    return 0;
}
```
## Unguided 

### 1. Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif.

```C++
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
```
Program di atas adalah implementasi fungsi untuk menghitung faktorial menggunakan rekursi dalam bahasa C++. Fungsi faktorial adalah sebuah fungsi rekursif yang mengambil satu argumen bilangan bulat positif n. Pada setiap panggilan rekursif, fungsi memeriksa apakah n sama dengan 0 atau 1, yang merupakan kasus dasar, dan mengembalikan nilai 1. Jika n bukan 0 atau 1, maka fungsi akan mengembalikan hasil perkalian antara n dan hasil rekursif dari panggilan fungsi faktorial(n - 1). Dalam fungsi main, pengguna diminta untuk memasukkan bilangan bulat positif. Jika input adalah bilangan negatif, program akan mencetak pesan bahwa faktorial tidak didefinisikan untuk bilangan negatif. Jika input adalah bilangan bulat positif, program akan memanggil fungsi faktorial untuk menghitung faktorial dari bilangan tersebut dan mencetak hasilnya. Program ini memberikan contoh sederhana dari penggunaan rekursi untuk menghitung faktorial.
#### Output:
<img width="443" alt="image" src="https://github.com/FahmiHidayat2/Praktikum-Struktur-Data-Modul-9/assets/161399477/0dd34700-fd1a-4869-83e4-d7bd228f79c4">

### 2. Buatlah versi program Rekursif Tidak Langsung (Indirect Recursion) dari soal nomor 1 di atas!

```c++
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
```
Program di atas telah dimodifikasi mengimplementasikan rekursi tidak langsung (indirect recursion) untuk menghitung faktorial dari suatu bilangan bulat positif. Dalam pendekatan ini, dua fungsi digunakan: faktorial sebagai fungsi utama yang bertindak sebagai antarmuka pengguna, dan faktorialHelper sebagai fungsi bantuan yang secara rekursif menghitung faktorial dengan mempertahankan akumulator. Saat fungsi faktorial dipanggil, ia memanggil fungsi faktorialHelper dengan melewatkan nilai awal akumulator yaitu 1. Fungsi faktorialHelper kemudian secara rekursif memanggil dirinya sendiri dengan nilai yang semakin berkurang hingga mencapai kasus dasar, yaitu ketika nilai n sama dengan 0 atau 1. Pada saat itu, fungsi faktorialHelper mengembalikan nilai akumulator yang telah mengakumulasi hasil perkalian sepanjang proses rekursi. Dengan pendekatan ini, program berhasil menghitung faktorial dari bilangan bulat positif yang dimasukkan pengguna menggunakan rekursi tidak langsung.
#### Output :
<img width="421" alt="image" src="https://github.com/FahmiHidayat2/Praktikum-Struktur-Data-Modul-9/assets/161399477/b2ccf73c-0d01-435e-99b4-931f0db5b255">

### 3.Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai.
```c++
#include <iostream>
#include <vector>
#include <string>

// Struktur data untuk merepresentasikan mahasiswa
struct Mahasiswa {
    std::string nim;
    int nilai;
    Mahasiswa(std::string n, int val) : nim(n), nilai(val) {}
};

// Ukuran default dari hash table
const int TABLE_SIZE = 10;

// Kelas untuk hash table
class HashTable {
private:
    // Vektor untuk menyimpan elemen-elemen hash table
    std::vector<Mahasiswa*> table[TABLE_SIZE];

    // Fungsi hash sederhana untuk menghasilkan indeks dari kunci
    int hash(std::string key) {
        int hashValue = 0;
        for (char ch : key) {
            hashValue += ch;
        }
        return hashValue % TABLE_SIZE;
    }

public:
    // Fungsi untuk menambahkan data mahasiswa ke hash table
    void tambahData(std::string nim, int nilai) {
        int index = hash(nim);
        table[index].push_back(new Mahasiswa(nim, nilai));
    }

    // Fungsi untuk menghapus data mahasiswa dari hash table berdasarkan NIM
    void hapusData(std::string nim) {
        int index = hash(nim);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if ((*it)->nim == nim) {
                delete *it;
                table[index].erase(it);
                break;
            }
        }
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan NIM
    Mahasiswa* cariBerdasarkanNIM(std::string nim) {
        int index = hash(nim);
        for (Mahasiswa* mahasiswa : table[index]) {
            if (mahasiswa->nim == nim) {
                return mahasiswa;
            }
        }
        return nullptr;
    }

    // Fungsi untuk mencari data mahasiswa berdasarkan nilai
    Mahasiswa* cariBerdasarkanNilai(int nilai) {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            for (Mahasiswa* mahasiswa : table[i]) {
                if (mahasiswa->nilai == nilai) {
                    return mahasiswa;
                }
            }
        }
        return nullptr;
    }
};

int main() {
    HashTable hashTable;

    // Menambahkan data mahasiswa
    hashTable.tambahData("123456", 85);
    hashTable.tambahData("654321", 75);
    hashTable.tambahData("111222", 90);

    // Mencari data mahasiswa berdasarkan NIM
    Mahasiswa* mahasiswa1 = hashTable.cariBerdasarkanNIM("123456");
    if (mahasiswa1 != nullptr) {
        std::cout << "Data mahasiswa dengan NIM 123456 ditemukan. Nilainya: " << mahasiswa1->nilai << std::endl;
    } else {
        std::cout << "Data mahasiswa dengan NIM 123456 tidak ditemukan." << std::endl;
    }

    // Menghapus data mahasiswa
    hashTable.hapusData("654321");

    // Mencari data mahasiswa berdasarkan nilai
    Mahasiswa* mahasiswa2 = hashTable.cariBerdasarkanNilai(90);
    if (mahasiswa2 != nullptr) {
        std::cout << "Data mahasiswa dengan nilai 90 ditemukan. NIM: " << mahasiswa2->nim << std::endl;
    } else {
        std::cout << "Data mahasiswa dengan nilai 90 tidak ditemukan." << std::endl;
    }

    return 0;
}
```
Implementasi hash table untuk menyimpan data mahasiswa menggunakan bahasa C++ telah dibuat. Dalam program ini, setiap entri dalam hash table direpresentasikan sebagai vektor yang berisi pointer ke objek Mahasiswa. Fungsi hash sederhana digunakan untuk mengonversi NIM mahasiswa menjadi indeks dalam hash table. Program menyediakan fungsi-fungsi dasar untuk menambahkan data baru ke hash table, menghapus data berdasarkan NIM, dan mencari data baik berdasarkan NIM maupun nilai. Fungsi `tambahData` digunakan untuk menambahkan data mahasiswa ke hash table dengan menghasilkan indeks menggunakan fungsi hash, lalu menambahkan objek Mahasiswa ke vektor di indeks tersebut. Fungsi `hapusData` digunakan untuk menghapus data mahasiswa dari hash table berdasarkan NIM dengan mencari objek Mahasiswa yang sesuai dan menghapusnya dari vektor. Fungsi `cariBerdasarkanNIM` dan `cariBerdasarkanNilai` digunakan untuk mencari data mahasiswa berdasarkan NIM dan nilai secara berturut-turut. Dengan implementasi ini, pengguna dapat dengan mudah menyimpan, mengakses, dan mengelola data mahasiswa menggunakan hash table.

## Kesimpulan
Laporan praktikum membahas implementasi modul rekursif dan hash table dalam C++. Rekursi memanfaatkan teknik pemanggilan fungsi diri sendiri, sementara hash table menyimpan pasangan kunci-nilai dengan akses cepat. Contoh penggunaan rekursi meliputi perhitungan faktorial dan panggilan rekursif tidak langsung, sedangkan hash table digunakan untuk menyimpan data mahasiswa dengan fitur dasar tambah, cari, dan hapus data berdasarkan NIM atau nilai. Rekursi memecah masalah menjadi lebih kecil, sementara hash table menawarkan akses data cepat.
## Referensi
[1] S. Setiawan, R. Manurung, and A. Azurat, “Struktur Data dan Algoritma Dasar-dasar Rekursif Devide and Conquer Mengulang : Maximum Contiguous subsequence,” 2010.
