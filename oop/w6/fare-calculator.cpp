#include <iostream>
using namespace std;

class FareCalculator{
    public:
        double calculateFare(double km){
            return 2500.0 * km;
        }
        double calculateFare(double km, int min){
            return 2500.0 * km + 500.0 * min;
        }
        double calculateFare(double km, int min, double surge){
            return 2500.0 * km + 500.0 * min * surge;
        }
};

class Ride {
    public:
        virtual double fare(double km) = 0;
};

class MotorBike : public Ride {
    public:
        double fare(double km) override {
            return 2500.0 * km;
        }
};

class Car : public Ride {
    public:
        double fare(double km) override {
            return 4000.0 * km;
        }
};

class CarXL : public Ride {
    public:
        double fare(double km) override final {
            return 6000.0 * km + 10000.0;
        }
};

int main() {
    FareCalculator calc;

    double fare1 = calc.calculateFare(10.0);
    double fare2 = calc.calculateFare(10.0,10);
    double fare3 = calc.calculateFare(10.0,50,1.0);
    cout << fare1 << endl;
    cout << fare2 << endl;
    cout << fare3 << endl;

    Ride *ride1 = new MotorBike();
    cout << "Fare for 10 KM Motorbike ride: " << ride1->fare(10) << "\n";
    Ride *ride2 = new Car();
    cout << "Fare for 10 KM Car ride: " << ride2->fare(10) << "\n";
    Ride *ride3 = new CarXL();
    cout << "Fare for 10 KM CarXL ride: " << ride3->fare(10) << "\n";
    return 0;
}