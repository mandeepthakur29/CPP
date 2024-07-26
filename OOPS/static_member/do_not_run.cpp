//Example using a Simple Data Member:

#include <iostream>

class MyClass {
private:
    int count; // Simple data member to count the number of objects

public:
    MyClass() {
        count++; // Increment count when a new object is created
    }

    int getCount() const {
        return count;
    }
};

int main() {
    MyClass obj1;
    MyClass obj2;
    MyClass obj3;

    std::cout << "Number of objects created: " << obj1.getCount() << std::endl;

    return 0;
}


//Example using a Static Data Member:

#include <iostream>

class MyClass {
private:
    static int count; // Static data member to count the number of objects

public:
    MyClass() {
        count++; // Increment count when a new object is created
    }

    static int getCount() {
        return count;
    }
};

// Initialize the static data member outside the class definition
int MyClass::count = 0;

int main() {
    MyClass obj1;
    MyClass obj2;
    MyClass obj3;

    std::cout << "Number of objects created: " << MyClass::getCount() << std::endl;

    return 0;
}


// Why We Need Static Data Members:

// Resource Sharing: Static data members allow sharing of a common resource among all instances of a class. This is useful for maintaining global state or shared resources.
// Memory Efficiency: Using a static data member reduces memory consumption as it's shared among all instances, rather than each instance having its own copy.
// Synchronization: It helps in synchronizing access to shared resources in multithreaded environments.
// Maintaining Global State: Useful for scenarios like keeping track of the total number of instances, managing global configurations, etc.

// In summary, static data members are essential for scenarios where you need to maintain a common state or resource shared among all instances of a class. They provide memory efficiency and facilitate resource sharing and synchronization.