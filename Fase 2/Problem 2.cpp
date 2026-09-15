#include <iostream>
using namespace std;

int main() {
    char pesan[1000];

    cout << "Masukkan pesan: ";
    cin >> pesan;

    // Menghitung panjang pesan secara manual
    int panjang = 0;

    while (pesan[panjang] != '\0') {
        panjang++;
    }

    // Jika pesan kosong
    if (panjang == 0) {
        cout << "Pesan kosong." << endl;
        return 0;
    }

    // Huruf pertama tidak berubah
    char hasil[1000];

    hasil[0] = pesan[0];

    // Proses huruf berikutnya
    for (int i = 1; i < panjang; i++) {

        // Mengubah huruf menjadi nilai A=1 sampai Z=26
        int nilaiHuruf = pesan[i] - 'A' + 1;

        int nilaiSebelumnya = pesan[i - 1] - 'A' + 1;

        // Melakukan pergeseran
        int nilaiBaru = nilaiHuruf + nilaiSebelumnya;

        // Jika melewati 26, kembali ke A
        while (nilaiBaru > 26) {
            nilaiBaru = nilaiBaru - 26;
        }

        // Mengubah kembali nilai menjadi huruf
        hasil[i] = 'A' + nilaiBaru - 1;
    }

    hasil[panjang] = '\0';

    cout << "\nPesan asli   : " << pesan << endl;
    cout << "Pesan terenkripsi: " << hasil << endl;

    return 0;
}