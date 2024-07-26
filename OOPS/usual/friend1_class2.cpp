//2 class and 1 friend function example

#include <iostream>

// Forward declaration of ClassB to resolve the circular dependency
class ClassB;

class ClassA {
private:
    int valueA;

public:
    ClassA(int value) : valueA(value) {}

    // Declare the friend function with ClassB as a parameter
    friend void compareValues(const ClassA& objA, const ClassB& objB);

    // Method to display the value of ClassA
    void display() const {
        std::cout << "Value of ClassA: " << valueA << std::endl;
    }
};

class ClassB {
private:
    int valueB;

public:
    ClassB(int value) : valueB(value) {}

    // Declare the friend function with ClassA as a parameter
    friend void compareValues(const ClassA& objA, const ClassB& objB);

    // Method to display the value of ClassB
    void display() const {
        std::cout << "Value of ClassB: " << valueB << std::endl;
    }
};

// Friend function definition to compare values between ClassA and ClassB objects
void compareValues(const ClassA& objA, const ClassB& objB) {
    if (objA.valueA > objB.valueB) {
        std::cout << "Value of ClassA is bigger." << std::endl;
    } else if (objA.valueA < objB.valueB) {
        std::cout << "Value of ClassB is bigger." << std::endl;
    } else {
        std::cout << "Both values are equal." << std::endl;
    }
}

int main() {
    // Create objects of ClassA and ClassB
    ClassA objA(100);
    ClassB objB(200);

    // Display values of both objects
    std::cout << "Values of objects:" << std::endl;
    objA.display();
    objB.display();

    // Call the friend function to compare values
    compareValues(objA, objB);

    return 0;
}
