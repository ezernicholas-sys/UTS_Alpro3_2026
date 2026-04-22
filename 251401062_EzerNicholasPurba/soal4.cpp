#include <iostream>
using namespace std;

int main() {
    int N;
    string S;

    cout << "Masukkan jumlah babak: ";
    cin >> N;
    cout << "Masukkan hasil pertandingan: ";
    cin >> S;

    int poinA = 0, poinB = 0;
    int streakA = 0, streakB = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'A') {
            poinA += 3;
            streakA++;
            streakB = 0;

            if (streakA == 3) {
                poinA += 2;
                streakA = 0; // reset setelah bonus
            }
        }
        else if (S[i] == 'B') {
            poinB += 3;
            streakB++;
            streakA = 0;

            if (streakB == 3) {
                poinB += 2;
                streakB = 0;
            }
        }
        else if (S[i] == 'C') {
            poinA += 1;
            poinB += 1;
            streakA = 0;
            streakB = 0;
        }
    }

    cout << "\nPoin A: " << poinA << endl;
    cout << "Poin B: " << poinB << endl;

    if (poinA > poinB)
        cout << "Pemenangnya adalah pemain A" << endl;
    else if (poinB > poinA)
        cout << "Pemenangnya adalah pemain B" << endl;
    else
        cout << "Hasil seri" << endl;

    return 0;
}