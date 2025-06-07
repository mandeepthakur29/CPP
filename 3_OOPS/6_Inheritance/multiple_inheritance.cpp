#include <iostream>

// Base class 1
class Base1 
{
public:
    void displayBase1() 
    {
        std::cout << "Base1" << std::endl;
    }
};

// Base class 2
class Base2 
{
public:
    void displayBase2() 
    {
        std::cout << "Base2" << std::endl;
    }
};

// Derived class inherits privately from Base1 and publicly from Base2
class Derived : private Base1, public Base2 
{
public:
    void displayDerived() 
    {
        std::cout << "Derived" << std::endl;
    }
};

int main() {
    Derived derivedObj;

    // Can't access displayBase1() directly due to private inheritance
    // derivedObj.displayBase1(); // This will result in a compilation error

    // Can access displayBase2() directly due to public inheritance
    derivedObj.displayBase2(); // This will print "Base2"

    derivedObj.displayDerived(); // This will print "Derived"

    return 0;
}
