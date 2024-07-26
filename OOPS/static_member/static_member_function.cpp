#include <iostream>

class MyClass {
private:
    static int count; // Static data member to count the number of objects

public:
    // Constructor
    MyClass() {
        count++; // Increment count when a new object is created
    }

    // Static member function to get the count of objects
    static int getCount() {
        return count;
    }
};

// Initialize the static data member outside the class definition
int MyClass::count = 0;

int main() {
    // Create objects of MyClass
    MyClass obj1;
    MyClass obj2;
    MyClass obj3;

    // Call the static member function using the class name
    std::cout << "Number of objects created: " << MyClass::getCount() << std::endl;

    return 0;
}

// Static member functions in C++ belong to the class rather than individual objects. They can be called using the class name without needing an 
// object. 