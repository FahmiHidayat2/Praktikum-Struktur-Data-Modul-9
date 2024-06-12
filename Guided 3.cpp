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
