#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

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

// Overloading tampilkan aset
void tampilkanAset(const Aset &aset, int index) {
    cout << setw(5) << index + 1 << setw(20) << aset.nama
         << setw(10) << aset.jumlah << setw(15) << aset.harga << endl;
}
void tampilkanAset(const Aset &aset) {
    cout << "Aset: " << aset.nama << ", Jumlah: " << aset.jumlah
         << ", Harga: " << aset.harga << endl;
}

// Fungsi rekursif total nilai aset
double hitungTotalNilaiAset(const Aset daftar[], int jumlah) {
    if (jumlah == 0) return 0;
    return (daftar[jumlah - 1].jumlah * daftar[jumlah - 1].harga) +
           hitungTotalNilaiAset(daftar, jumlah - 1);
}

// ? Fungsi pointer (parameter dereference *)
void tampilkanDetailAset(Aset *aset) {
    cout << "\n[Detail Aset]\n";
    cout << "Nama  : " << aset->nama << endl;
    cout << "Jumlah: " << aset->jumlah << endl;
    cout << "Harga : " << aset->harga << endl;
}

// ? Fungsi pointer (parameter address-of & -> dereference *)
void tambahJumlah(int *jumlah, int penambahan) {
    *jumlah += penambahan;
}

// ? Fungsi inisialisasi aset (pakai pointer)
void inisialisasiAset(Aset *aset, string nama, int jumlah, double harga) {
    aset->nama = nama;
    aset->jumlah = jumlah;
    aset->harga = harga;
}

// Registrasi user
void registrasi(User users[], int &totalUsers) {
    if (totalUsers < 100) {
        cout << "Nama: ";
        getline(cin >> ws, users[totalUsers].nama);
        cout << "NIM: ";
        getline(cin, users[totalUsers].nim);
        cout << "Registrasi berhasil. Silakan login." << endl;
        totalUsers++;
    } else {
        cout << "User telah penuh." << endl;
    }
}

// Login user
int login(User users[], int totalUsers) {
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

// Tambah aset
void tambahAset(User &user) {
    if (user.jumlahAsetTersimpan < 100) {
        string nama;
        int jumlah;
        double harga;

        cout << "Nama Aset: ";
        getline(cin >> ws, nama);
        cout << "Jumlah: ";
        cin >> jumlah;
        cout << "Harga: ";
        cin >> harga;

        // ? Gunakan inisialisasi aset dengan pointer
        inisialisasiAset(&user.daftarAset[user.jumlahAsetTersimpan], nama, jumlah, harga);

        user.jumlahAsetTersimpan++;
        cout << "Aset berhasil ditambahkan." << endl;
    } else {
        cout << "Daftar aset penuh." << endl;
    }
}

// Lihat aset
void lihatAset(User &user) {
    if (user.jumlahAsetTersimpan > 0) {
        cout << "\nDaftar Aset:\n";
        cout << setw(5) << "No" << setw(20) << "Nama Aset" << setw(10)
             << "Jumlah" << setw(15) << "Harga" << endl;
        cout << "----------------------------------------------------" << endl;
        for (int i = 0; i < user.jumlahAsetTersimpan; i++) {
            tampilkanAset(user.daftarAset[i], i);
        }

        double total = hitungTotalNilaiAset(user.daftarAset, user.jumlahAsetTersimpan);
        cout << "Total nilai aset: " << total << endl;

        // ? Tampilkan detail salah satu aset (optional)
        int pilih;
        cout << "\nIngin lihat detail aset tertentu? (nomor atau 0 untuk lewati): ";
        cin >> pilih;
        if (pilih > 0 && pilih <= user.jumlahAsetTersimpan) {
            tampilkanDetailAset(&user.daftarAset[pilih - 1]);
        }
    } else {
        cout << "Daftar aset kosong." << endl;
    }
}

// Ubah aset
void ubahAset(User &user) {
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

        // ? Tambahan: Tambah jumlah dengan pointer
        int tambahan;
        cout << "Tambahan Jumlah (boleh 0): ";
        cin >> tambahan;
        tambahJumlah(&user.daftarAset[nomor].jumlah, tambahan); // <--- pointer

        cout << "Aset berhasil diubah." << endl;
    } else {
        cout << "Nomor aset tidak valid." << endl;
    }
}

// Hapus aset
void hapusAset(User &user) {
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
}

// Menu utama user
void menuAset(User &user) {
    int pilihan;
    do {
        cout << "\nMenu:\n1. Tambah Aset\n2. Lihat Daftar Aset\n3. Ubah Aset\n4. Hapus Aset\n5. Logout\nPilihan Anda: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1: tambahAset(user); break;
            case 2: lihatAset(user); break;
            case 3: ubahAset(user); break;
            case 4: hapusAset(user); break;
            case 5: cout << "Logout berhasil." << endl; break;
            default: cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 5);
}

// Main program
int main() {
    int pilihan;
    do {
        cout << "\n1. Registrasi\n2. Login\n3. Keluar\nPilihan: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) registrasi(users, totalUsers);
        else if (pilihan == 2) {
            int userIndex = login(users, totalUsers);
            if (userIndex != -1) menuAset(users[userIndex]);
        }
    } while (pilihan != 3);

    cout << "Program selesai." << endl;
    return 0;
}

