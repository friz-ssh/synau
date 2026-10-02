#include <iostream>
#include <vector>
using namespace std;

class Kendaraan {
    public:
        virtual void jalan() = 0;
};

class Mobil : public Kendaraan {
    public:
        void jalan() override {
            cout << "mobil lagi jalan..vroom vroom...\n";
        }
};

class Sepeda : public Kendaraan {
    public:
        void jalan() override {
            cout << "sepeda lagi jalan..kring kring...\n";
        }
};

int main() {
    vector<Kendaraan*> listKendaraan;

    listKendaraan.push_back(new Mobil());
    listKendaraan.push_back(new Sepeda());

    for(size_t i = 0; i < listKendaraan.size(); i++){
        cout << "Kendaraan " << i + 1 << ": ";
        listKendaraan[i]->jalan();
    }
    return 0;
}