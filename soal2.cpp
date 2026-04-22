#include <iostream>
using namespace std;

int main() {
    long long kode;
    int keluar;

    cout << "Masukkan kode parkir (10 digit): ";
    cin >> kode;

    cout << "Masukkan jam keluar (HHMM): ";
    cin >> keluar;

    // Ekstrak data
    int jenis = kode / 100000000;
    int waktuMasuk = (kode / 10000) % 10000;
    int lokasi = kode % 10000;

    // Pisah jam & menit masuk
    int jamMasuk = waktuMasuk / 100;
    int menitMasuk = waktuMasuk % 100;

    // Pisah jam & menit keluar
    int jamKeluar = keluar / 100;
    int menitKeluar = keluar % 100;

    // Konversi ke menit total
    int totalMasuk = jamMasuk * 60 + menitMasuk;
    int totalKeluar = jamKeluar * 60 + menitKeluar;

    int durasiMenit = totalKeluar - totalMasuk;

    // Pembulatan ke jam
    int durasiJam = durasiMenit / 60;
    if (durasiMenit % 60 != 0) {
        durasiJam++;
    }

    // Tentukan jenis kendaraan
    string nama;
    int biaya = 0;

    if (jenis == 10) {
        nama = "Mobil";
        biaya = 5000;
        if (durasiJam > 1)
            biaya += (durasiJam - 1) * 3000;
    }
    else if (jenis == 20) {
        nama = "Motor";
        biaya = 3000;
        if (durasiJam > 1)
            biaya += (durasiJam - 1) * 2000;
    }
    else if (jenis == 30) {
        nama = "Bus";
        biaya = 10000;
        if (durasiJam > 1)
            biaya += (durasiJam - 1) * 7000;
    }
    else {
        cout << "Kode jenis kendaraan tidak valid!" << endl;
        return 0;
    }

    // Output
    cout << "\n=== DATA PARKIR ===" << endl;
    cout << "Jenis kendaraan : " << nama << endl;
    cout << "Waktu masuk     : " << jamMasuk << ":" << menitMasuk << endl;
    cout << "Waktu keluar    : " << jamKeluar << ":" << menitKeluar << endl;
    cout << "Durasi (jam)    : " << durasiJam << endl;
    cout << "Lokasi parkir   : " << lokasi << endl;
    cout << "Total biaya     : Rp " << biaya << endl;

    return 0;
}