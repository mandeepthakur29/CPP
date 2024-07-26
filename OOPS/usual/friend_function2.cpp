#include <iostream>
#include <string>

class Car {
private:
    int a, b;

public:
    Car(int a, int b) : a(a), b(b) {}

    friend void print(Car);
};

// Definition of the friend function
void print(Car car) {
    std::cout << "Values of a and b inside Car object: " << car.a << ", " << car.b << std::endl;
}

int main() {
    // Create a Car object
    Car car(5, 10);

    // Call the friend function to print the values of a and b
    print(car);

    return 0;
}
