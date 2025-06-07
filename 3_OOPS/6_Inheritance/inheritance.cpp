#include <iostream>
#include <string>

// Base class (parent class)
class Vehicle {
protected:
    int speed;

public:
    Vehicle(int speed) : speed(speed) {}

    void start() const {
        std::cout << "Vehicle started" << std::endl;
    }

    void stop() const {
        std::cout << "Vehicle stopped" << std::endl;
    }
};

// Derived class (child class)
class Car : public Vehicle {
private:
    std::string model;

public:
    Car(int speed, const std::string& model) : Vehicle(speed), model(model) {}

    void drive() const {
        std::cout << "Car " << model << " is driving at " << speed << " mph" << std::endl;
    }
};

int main() {
    Car myCar(60, "Toyota");

    myCar.start();  // Inherited method from Vehicle class
    myCar.drive();  // Method specific to Car class
    myCar.stop();   // Inherited method from Vehicle class

    return 0;
}
