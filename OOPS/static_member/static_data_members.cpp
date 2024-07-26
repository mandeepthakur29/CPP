#include <iostream>

class MyClass {
private:
    static int count; //Declared

public:
    MyClass() {
        count++; // Increment count when a new object is created
    }

    // Static method to get the count of objects
    static int getCount() {
        return count;
    }
};

// Initialize the static data member outside the class definition
int MyClass::count = 0; //Defined- Always defined outside the class

int main() {
    // Create objects of MyClass
    MyClass obj1;
    MyClass obj2;
    MyClass obj3;

    // Print the count of objects using the static method
    std::cout << "Number of objects created: " << MyClass::getCount() << std::endl;

    return 0;
}
