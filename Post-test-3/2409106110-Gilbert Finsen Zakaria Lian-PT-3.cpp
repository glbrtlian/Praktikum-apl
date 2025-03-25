#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Nested Struct untuk User dan Aset
struct Aset {
    string nama;
    int jumlah;
    double harga;
};

struct User {
    string nama;
    string nim;
    Aset daftarAset[100];
    int jumlahAsetTersimpan = 0;
};

User users[100];
int totalUsers = 0;

int registrasi() {
    if (totalUsers < 100) {
        cout << "Nama: ";
        getline(cin >> ws, users[totalUsers].nama);
        cout << "NIM: ";
        getline(cin, users[totalUsers].nim);
        cout << "Registrasi berhasil. Silakan login." << endl;
        totalUsers++;
        return 1;
    } else {
        cout << "User telah penuh." << endl;
        return 0;
    }
}

int login() {
    string nama, nim;
    int percobaan = 0;

    while (percobaan < 3) {
        cout << "Nama: ";
        getline(cin >> ws, nama);
        cout << "NIM: ";
        getline(cin, nim);

        for (int i = 0; i < totalUsers; i++) {
            if (users[i].nama == nama && users[i].nim == nim) {
                cout << "Login berhasil!" << endl;
                return i;
            }
        }
        percobaan++;
        cout << "Login gagal. Sisa percobaan: " << 3 - percobaan << endl;
    }
    cout << "Akses ditolak." << endl;
    return -1;
}

int menuAset(User &user) {
    int pilihan;
    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Aset\n";
        cout << "2. Lihat Daftar Aset\n";
        cout << "3. Ubah Aset\n";
        cout << "4. Hapus Aset\n";
        cout << "5. Logout\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: {
                if (user.jumlahAsetTersimpan < 100) {
                    cout << "Nama Aset: ";
                    getline(cin, user.daftarAset[user.jumlahAsetTersimpan].nama);
                    cout << "Jumlah: ";
                    cin >> user.daftarAset[user.jumlahAsetTersimpan].jumlah;
                    cout << "Harga: ";
                    cin >> user.daftarAset[user.jumlahAsetTersimpan].harga;
                    user.jumlahAsetTersimpan++;
                    cout << "Aset berhasil ditambahkan." << endl;
                } else {
                    cout << "Daftar aset penuh." << endl;
                }
                break;
            }
            case 2: {
                if (user.jumlahAsetTersimpan > 0) {
                    cout << "\nDaftar Aset:\n";
                    cout << setw(5) << "No" << setw(20) << "Nama Aset" << setw(10) << "Jumlah" << setw(15) << "Harga" << endl;
                    cout << "----------------------------------------------------" << endl;
                    for (int i = 0; i < user.jumlahAsetTersimpan; i++) {
                        cout << setw(5) << i + 1 << setw(20) << user.daftarAset[i].nama << setw(10) << user.daftarAset[i].jumlah << setw(15) << user.daftarAset[i].harga << endl;
                    }
                } else {
                    cout << "Daftar aset kosong." << endl;
                }
                break;
            }
            case 3: {
                int nomor;
                cout << "Masukkan nomor aset yang ingin diubah: ";
                cin >> nomor;
                if (nomor > 0 && nomor <= user.jumlahAsetTersimpan) {
                    nomor--;
                    cout << "Nama Aset Baru: ";
                    getline(cin >> ws, user.daftarAset[nomor].nama);
                    cout << "Jumlah Baru: ";
                    cin >> user.daftarAset[nomor].jumlah;
                    cout << "Harga Baru: ";
                    cin >> user.daftarAset[nomor].harga;
                    cout << "Aset berhasil diubah." << endl;
                } else {
                    cout << "Nomor aset tidak valid." << endl;
                }
                break;
            }
            case 4: {
                int nomor;
                cout << "Masukkan nomor aset yang ingin dihapus: ";
                cin >> nomor;
                if (nomor > 0 && nomor <= user.jumlahAsetTersimpan) {
                    nomor--;
                    for (int i = nomor; i < user.jumlahAsetTersimpan - 1; i++) {
                        user.daftarAset[i] = user.daftarAset[i + 1];
                    }
                    user.jumlahAsetTersimpan--;
                    cout << "Aset berhasil dihapus." << endl;
                } else {
                    cout << "Nomor aset tidak valid." << endl;
                }
                break;
            }
            case 5: {
                cout << "Logout berhasil." << endl;
                return 0;
            }
            default: {
                cout << "Pilihan tidak valid." << endl;
            }
        }
    } while (pilihan != 5);
    return 0;
}

int main() {
    int pilihan;
    do {
        cout << "\n1. Registrasi\n2. Login\n3. Keluar\nPilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) registrasi();
        else if (pilihan == 2) {
            int userIndex = login();
            if (userIndex != -1) menuAset(users[userIndex]);
        }
    } while (pilihan != 3);

    cout << "Program selesai." << endl;
    return 0;
}

