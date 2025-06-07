#include <iostream>

// Base class 1
class Base1 {
protected:
    int protectedVar1;

public:
    Base1() : protectedVar1(10) {}

    void displayBase1() {
        std::cout << "Base1: ProtectedVar1 = " << protectedVar1 << std::endl;
    }
};

// Base class 2
class Base2 {
protected:
    int protectedVar2;

public:
    Base2() : protectedVar2(20) {}

    void displayBase2() {
        std::cout << "Base2: ProtectedVar2 = " << protectedVar2 << std::endl;
    }
};

// Derived class inherits from Base1 and Base2
class Derived : private Base1, public Base2 {
private:
    int privateVar;

public:
    Derived() : privateVar(30) {}

    void displayDerived() {
        std::cout << "Derived: PrivateVar = " << privateVar << std::endl;
    }

    void displayAll() {
        displayBase1(); // Accessible due to private inheritance
        displayBase2(); // Accessible due to public inheritance
        std::cout << "Derived: PrivateVar = " << privateVar << std::endl;
    }
};

int main() {
    Derived derivedObj;

    // Can't access protectedVar1 directly as it's inherited privately
    // derivedObj.protectedVar1 = 100; // Error: 'int Base1::protectedVar1' is protected within this context

    // Can access protectedVar2 as it's inherited publicly
    derivedObj.displayBase2();

    derivedObj.displayDerived();
    derivedObj.displayAll();

    return 0;
}
