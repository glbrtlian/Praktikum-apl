#include <iostream>
#include <string>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool is_valid_passcode(int n) {
    return n > 100 && n <= 99999;
}

bool is_divisible(int n) {
    return n % 2 == 0 && n % 3 == 0 && n % 5 != 0;
}

int main() {
    string username = "Gilbert Finsen Zakaria Lian";
    string password = "2409106110";
    string input_user, input_pass;
    int attempts = 3;

    while (attempts > 0) {
        cout << "Masukkan Username: ";
        getline(cin, input_user);
        cout << "Masukkan Password: ";
        cin >> input_pass;
        cin.ignore();

        if (input_user == username && input_pass == password) {
            cout << "Login berhasil!\n\n";
            break;
        } else {
            attempts--;
            cout << "Login gagal! Sisa percobaan: " << attempts << "\n\n";
        }
    }
    
    if (attempts == 0) {
        cout << "Anda telah dikunci.\n";
        return 0;
    }

    int max_iterations = 5;  // Batas maksimal perulangan
    int iteration_count = 0; // Counter untuk jumlah perulangan

    while (iteration_count < max_iterations) {
        int choice, passcode;
        cout << "\nMenu:\n";
        cout << "1. Cek verifikasi kode sandi bilangan prima\n";
        cout << "2. Cek verifikasi kode sandi habis dibagi 2 dan 3 tetapi tidak habis dibagi 5\n";
        cout << "3. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        if (choice == 3) {
            cout << "Program selesai.\n";
            break;
        }

        cout << "Masukkan kode sandi: ";
        cin >> passcode;

        if (!is_valid_passcode(passcode)) {
            cout << "Kode sandi tidak valid! Harus antara 101 dan 99999.\n";
            continue;
        }

        if (choice == 1) {
            cout << (is_prime(passcode) ? "Kode sandi adalah bilangan prima.\n" : "Kode sandi bukan bilangan prima.\n");
        } else if (choice == 2) {
            cout << (is_divisible(passcode) ? "Kode sandi memenuhi kriteria.\n" : "Kode sandi tidak memenuhi kriteria.\n");
        } else {
            cout << "Opsi tidak valid!\n";
        }

        iteration_count++;  // Tambahkan hitungan perulangan

        if (iteration_count >= max_iterations) {
            cout << "Anda telah mencapai batas maksimal penggunaan program.\n";
            break;
        }
    }

    return 0;
}

