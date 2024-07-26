// If you change the inheritance from public to private in the Car class declaration (class Car : private Vehicle), it means that the members 
// and methods of the Vehicle class will become private members of the Car class. This change affects the accessibility of the inherited members 
// and methods.

// Here's what happens with private inheritance:

// Public members of the base class become private in the derived class: Any public members (methods and variables) of the Vehicle class will become 
// private members of the Car class. This means they cannot be accessed directly from outside the Car class.

// Protected members remain protected: If there are any protected members in the base class, they will remain protected in the derived class. 
// They can be accessed by member functions of the derived class, but not by code outside the class.

// Inheritance is still present: Despite the change in access level, inheritance still occurs. This means that Car objects will inherit the 
// properties and behaviors of Vehicle, but they will be hidden as private members.

// Derived class objects cannot be used as base class objects: Objects of the Car class cannot be used where objects of the Vehicle class are 
// expected, as the inheritance is private.

// In summary, with private inheritance, the derived class (Car) can access the members of the base class (Vehicle), but those members are 
// considered private and cannot be accessed from outside the Car class.

#include <iostream>

// Base class
class Vehicle {
public:
    void start() {
        std::cout << "Vehicle started." << std::endl;
    }
};

// Derived class with private inheritance
class Car : private Vehicle {
private:
    int numWheels;

public:
    Car(int wheels) : numWheels(wheels) {}

    void drive() {
        std::cout << "Car with " << numWheels << " wheels is being driven." << std::endl;
        start();  // Accessing the inherited member function
    }
};

int main() {
    Car car(4); // Car with 4 wheels
    // car.start();  // Error: 'start' is a private member of 'Vehicle'
    car.drive();    // This works because drive() is a public member of Car and calls start() internally
    return 0;
}
