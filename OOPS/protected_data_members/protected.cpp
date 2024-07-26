#include <iostream>

class Base {
private:
    int privateVar;

protected:
    int protectedVar;

public:
    Base() : privateVar(1), protectedVar(2) {}

    void display() {
        std::cout << "Private Var: " << privateVar << std::endl;   // Accessible within the class
        std::cout << "Protected Var: " << protectedVar << std::endl; // Accessible within the class and derived classes
    }
};

class Derived : public Base {
public:
    void modifyVars() 
    {
        //privateVar = 6;  privateVar is not accessible here
        
        protectedVar = 5; // Accessible and modifiable in derived classes
    }
};

int main() {
    Base baseObj;
    baseObj.display();

    Derived derivedObj;
    derivedObj.display(); // Can access protectedVar through Base's display function
    derivedObj.modifyVars(); // Modify protectedVar in derived class
    derivedObj.display(); // Can access protectedVar through Base's display function after modification

    return 0;
}
