#include <iostream>
#include <string>

class Car {
private:
    std::string model;
    int year;

public:
    Car(std::string model, int year) : model(model), year(year) {}

    // Declaring the operator<< as a friend function of the Car class
    friend std::ostream& operator<<(std::ostream& os, const Car& car);
};

// Definition of the friend function operator<<
std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << "Car Model: " << car.model << ", Year: " << car.year;
    return os;
}

int main() {
    Car myCar("Toyota Camry", 2022);

    // Using the overloaded operator<< to output the car information
    std::cout << "My Car Details: " << myCar << std::endl;

    return 0;
}

//NOTE: Friend declaration can be in Private, Public or Protected inside the class. But, Definition of friend function should be outside the class.
