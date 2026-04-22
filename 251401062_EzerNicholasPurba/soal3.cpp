#include <iostream>
using namespace std;

int main(){
    int kode;

    cout << "Masukkan kode transaksi (8 digit): ";
    cin >> kode;

    // Ekstrak data
    int hari = kode / 1000000;
    int loyal = (kode / 10000) % 100;
    int belanja = kode % 10000;

    string jenisHari, jenisPelanggan;
    int poinPerUnit = 0;

    // Validasi hari
    if (hari == 1) jenisHari = "Hari Kerja";
    else if (hari == 2) jenisHari = "Akhir Pekan";
    else if (hari == 3) jenisHari = "Hari Libur Nasional";
    else {
        cout << "Kode hari tidak valid!" << endl;
        return 0;
    }

    // Validasi pelanggan
    if (loyal == 1) jenisPelanggan = "Biasa";
    else if (loyal == 2) jenisPelanggan = "Silver";
    else if (loyal == 3) jenisPelanggan = "Gold";
    else {
        cout << "Kode pelanggan tidak valid!" << endl;
        return 0;
    }

    // Tentukan poin
    if (hari == 1) { // hari kerja
        if (loyal == 1) poinPerUnit = 1;
        else if (loyal == 2) poinPerUnit = 2;
        else if (loyal == 3) poinPerUnit = 3;
    }
    else if (hari == 2) { // akhir pekan
        if (loyal == 1) poinPerUnit = 2;
        else if (loyal == 2) poinPerUnit = 3;
        else if (loyal == 3) poinPerUnit = 5;
    }
    else if (hari == 3) { // hari libur
        if (loyal == 1) poinPerUnit = 3;
        else if (loyal == 2) poinPerUnit = 5;
        else if (loyal == 3) poinPerUnit = 7;
    }

    // Hitung total
    int totalUang = belanja * 100000;
    int totalPoin = belanja * poinPerUnit;

    // Output
    cout << "\n=== DATA TRANSAKSI ===" << endl;
    cout << "Jenis hari        : " << jenisHari << endl;
    cout << "Jenis pelanggan   : " << jenisPelanggan << endl;
    cout << "Jumlah belanja    : Rp " << totalUang << endl;
    cout << "Total poin        : " << totalPoin << endl;

    return 0;
}