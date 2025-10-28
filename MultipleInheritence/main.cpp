#include <iostream>
#include <string>
using namespace std;


class car {
    string wheels;
public:
    car(string wheels) {
        this->wheels = wheels;
    }

    void drive() {
        cout << "I am driving!\n";
    }

    string getWheels() {
        return wheels;
    }

};

class airplane {
    string wings;
public:
    airplane(string wings) {
        this->wings = wings;
    }

    void fly() {
        cout << "I am flying!\n";
    }

    string getWings() {
        return wings;
    }

};

class flyingCar : public car, public airplane {

public:
    flyingCar(string wheels, string wings) : car(wheels), airplane(wings) {

    }
};


int main() {

    flyingCar fc("fc wheels", "fc wings");

    fc.drive();
    fc.fly();

    cout << fc.getWheels() << "\n";
    cout << fc.getWings();




    return 0;
}