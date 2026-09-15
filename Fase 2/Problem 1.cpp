#include <iostream>
using namespace std;

int main() {
    int N, K;

    cout << "Masukkan jumlah astronaut (N): ";
    cin >> N;

    cout << "Masukkan nilai K: ";
    cin >> K;

    // Membuat daftar astronaut 1 sampai N
    int* astronaut = new int[N];

    for (int i = 0; i < N; i++) {
        astronaut[i] = i + 1;
    }

    int jumlah = N;
    int posisi = 0;

    cout << "\nUrutan eliminasi: ";

    while (jumlah > 1) {

        // Menentukan posisi astronaut yang dieliminasi
        posisi = (posisi + K - 1) % jumlah;

        int yangDieliminasi = astronaut[posisi];

        cout << yangDieliminasi;

        if (jumlah > 2) {
            cout << " -> ";
        }

        // Menggeser astronaut setelah yang dieliminasi
        for (int i = posisi; i < jumlah - 1; i++) {
            astronaut[i] = astronaut[i + 1];
        }

        jumlah--;

        // Mengubah nilai K
        if (yangDieliminasi % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }

        // K minimal 2
        if (K < 2) {
            K = 2;
        }

        // Posisi tetap karena elemen berikutnya
        // otomatis menempati posisi yang sama
        if (posisi >= jumlah) {
            posisi = 0;
        }
    }

    cout << "\nAstronaut terakhir yang bertahan: "
         << astronaut[0] << endl;

    delete[] astronaut;

    return 0;
}