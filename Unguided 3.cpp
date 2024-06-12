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

