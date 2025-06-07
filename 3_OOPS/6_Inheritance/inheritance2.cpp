#include <iostream>
using namespace std;

// Base class
class Base {
private:
    int privateVar;

public:
    Base(int val) : privateVar(val) {}

    // Method to access privateVar
    int getPrivateVar() const 
    {
        return privateVar;
    }
};

// Derived class
class Derived : public Base {
public:
    Derived(int val) : Base(val) {}

    // Trying to access privateVar from the derived class
    void displayPrivateVar() const {
        // Error: 'int Base::privateVar' is private within this context
        // cout << privateVar << endl; // This line will cause a compilation error
        cout << "Accessing privateVar through getPrivateVar(): " << getPrivateVar() << endl;
    }
};

int main() {
    Derived derived(5);
    derived.displayPrivateVar(); // Accessing privateVar through a public method in the base class
    return 0;
}

//NOTE: Private member variable of Base class are not asseccible in derived class.