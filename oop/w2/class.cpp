#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Guru {
    private:
        string nip;
        bool validasiNIP(const string& input) {
            // cek apakah panjang NIP 18 karakter
            if (input.length() != 18) { return false; }
            for (char c: input) {
                if (!isdigit(c)) { return false;}
            }
            return true;
        }
    protected:
        string nama;
    public:
        string namaSekolah;
        void tampilkanProfil() {
            cout << "Profil Guru: \n";
            cout << "Nama Guru: " << nama << "\n";
            cout << "NIP: " << nip << "\n";
            cout << "Nama Sekolah: " << namaSekolah << "\n";
        }
        Guru() {} // default constructor
        Guru(const string& na, const string& ni, const string& ns): nama(na), namaSekolah(ns) {
            if(validasiNIP(ni)) {
                nip = ni;
            } else {
                nip = "INVALID";
                cout << "NIP milik " << nama << " Tidak Valid. Harus 18 digit!\n";
            }
        }

};

int main(){
    // guru dengan NIP valid
    Guru guru1("Nate Tan Ahoe", "196706072002121067", "SMA Indonesia Emas 2045");
    guru1.tampilkanProfil();

    cout << "\n";

    // guru dengan NIP tidak valid
    Guru guru2("Bayn Jamien", "0000000", "SMA Indonesia Emas 2045");
    guru2.tampilkanProfil();
    return 0;
}