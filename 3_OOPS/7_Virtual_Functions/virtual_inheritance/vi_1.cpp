#include <iostream>

// Base class
class Animal {
public:
    void eat() {
        std::cout << "Animal is eating" << std::endl;
    }
};

// Virtual inheritance
class Dog : virtual public Animal {};

// Virtual inheritance
class Bird : virtual public Animal {};

// Derived class inheriting from both Dog and Bird
class DogBird : public Dog, public Bird {};

int main() {
    DogBird db;
    db.eat();  // This will call the eat() function from Animal class

    return 0;
}

// NOTE:

// Virtual Inheritance: Virtual inheritance is used to resolve ambiguity that arises when a derived class inherits from multiple base 
// classes, and these base classes have a common base class themselves. When a base class is virtually inherited, only one instance of 
// the base class is shared among the derived class and its ancestors.