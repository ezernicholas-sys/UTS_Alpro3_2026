#include <iostream>
using namespace std;


int main(){
 string kartu;
    cout << "Masukkan nomor kartu: ";
    cin >> kartu;

    int panjang = kartu.length();
    string jenis = "Tidak Diketahui";

    // Identifikasi jenis kartu
    if (panjang == 14 && kartu.substr(0, 2) == "65") {
        jenis = "NUSANTARA";
    } 
    else if (panjang == 16 && 
            (kartu.substr(0, 2) == "77" || kartu.substr(0, 2) == "78")) {
        jenis = "GARUDA";
    } 
    else if (panjang == 15 && kartu.substr(0, 2) == "91") {
        jenis = "MERDEKA";
    }

    // Jika tidak sesuai jenis, langsung tidak valid
    if (jenis == "Tidak Diketahui") {
        cout << "Jenis kartu tidak valid" << endl;
        return 0;
    }

    int total = 0;
    int hitung = 0;

    // Perulangan dari belakang
    for (int i = panjang - 1; i >= 0; i--) {
        int digit = kartu[i] - '0';

        // Digit kedua dari belakang dikalikan 2
        if (hitung % 2 == 1) {
            digit = digit * 2;
            if (digit > 9) {
                digit = (digit / 10) + (digit % 10);
            }
        }

        total += digit;
        hitung++;
    }

    // Validasi
    if (total % 10 == 0) {
        cout << "Jenis Kartu: " << jenis << endl;
        cout << "Status: VALID" << endl;
    } else {
        cout << "Jenis Kartu: " << jenis << endl;
        cout << "Status: TIDAK VALID" << endl;
    }

    return 0;
}