#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Fungsi untuk login
bool login() {
    string nama, nim;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "Nama: ";
        getline(cin >> ws, nama); // Membaca nama dengan spasi
        cout << "NIM: ";
        getline(cin, nim);

        // Ganti dengan nama dan NIM yang diinginkan
        if (nama == "Lian" && nim == "110") {
            return true;
        } else {
            percobaan++;
            cout << "Login gagal. Sisa percobaan: " << 3 - percobaan << endl;
        }
    }
    return false;
}

int main() {
    if (!login()) {
        cout << "Akses ditolak." << endl;
        return 0;
    }

    const int MAX_ASET = 100;
    string namaAset[MAX_ASET];
    int jumlahAset[MAX_ASET];
    double hargaAset[MAX_ASET];
    int jumlahAsetTersimpan = 0;

    int pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Aset\n";
        cout << "2. Lihat Daftar Aset\n";
        cout << "3. Ubah Aset\n";
        cout << "4. Hapus Aset\n";
        cout << "5. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan newline

        switch (pilihan) {
            case 1: { // Tambah Aset
                if (jumlahAsetTersimpan < MAX_ASET) {
                    cout << "Nama Aset: ";
                    getline(cin, namaAset[jumlahAsetTersimpan]);
                    cout << "Jumlah: ";
                    cin >> jumlahAset[jumlahAsetTersimpan];
                    cout << "Harga: ";
                    cin >> hargaAset[jumlahAsetTersimpan];
                    jumlahAsetTersimpan++;
                    cout << "Aset berhasil ditambahkan." << endl;
                } else {
                    cout << "Daftar aset penuh." << endl;
                }
                break;
            }
            case 2: { // Lihat Daftar Aset
                if (jumlahAsetTersimpan > 0) {
                    cout << "\nDaftar Aset:\n";
                    cout << setw(5) << "No" << setw(20) << "Nama Aset" << setw(10) << "Jumlah" << setw(15) << "Harga" << endl;
                    cout << "----------------------------------------------------" << endl;
                    for (int i = 0; i < jumlahAsetTersimpan; i++) {
                        cout << setw(5) << i + 1 << setw(20) << namaAset[i] << setw(10) << jumlahAset[i] << setw(15) << hargaAset[i] << endl;
                    }
                } else {
                    cout << "Daftar aset kosong." << endl;
                }
                break;
            }
            case 3: { // Ubah Aset
                int nomor;
                cout << "Masukkan nomor aset yang ingin diubah: ";
                cin >> nomor;
                if (nomor > 0 && nomor <= jumlahAsetTersimpan) {
                    nomor--; // Sesuaikan dengan indeks array
                    cout << "Nama Aset Baru: ";
                    getline(cin >> ws, namaAset[nomor]);
                    cout << "Jumlah Baru: ";
                    cin >> jumlahAset[nomor];
                    cout << "Harga Baru: ";
                    cin >> hargaAset[nomor];
                    cout << "Aset berhasil diubah." << endl;
                } else {
                    cout << "Nomor aset tidak valid." << endl;
                }
                break;
            }
            case 4: { // Hapus Aset
                int nomor;
                cout << "Masukkan nomor aset yang ingin dihapus: ";
                cin >> nomor;
                if (nomor > 0 && nomor <= jumlahAsetTersimpan) {
                    nomor--; // Sesuaikan dengan indeks array
                    for (int i = nomor; i < jumlahAsetTersimpan - 1; i++) {
                        namaAset[i] = namaAset[i + 1];
                        jumlahAset[i] = jumlahAset[i + 1];
                        hargaAset[i] = hargaAset[i + 1];
                    }
                    jumlahAsetTersimpan--;
                    cout << "Aset berhasil dihapus." << endl;
                } else {
                    cout << "Nomor aset tidak valid." << endl;
                }
                break;
            }
            case 5: { // Keluar
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid." << endl;
            }
        }
    } while (pilihan != 5);

    return 0;
}
