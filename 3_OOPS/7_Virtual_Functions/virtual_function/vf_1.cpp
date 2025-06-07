#include <iostream>

// Base class
class Base 
{
public:
    // Virtual function
    virtual void display() 
    {
        std::cout << "Base class" << std::endl;
    }
};

// Derived class
class Derived : public Base 
{
public:
    // Override the display function
    void display() override 
    {
        std::cout << "Derived class" << std::endl;
    }
};

int main() 
{
    // Base class pointer pointing to a derived class object
    Base *ptr = new Derived();

    // Call the display function
    ptr->display();  // Output will be "Derived class"

    // Don't forget to free the dynamically allocated memory
    delete ptr;

    return 0;
}


// NOTE: 

// In the line Base *ptr = new Derived();, the following occurs:

// new Derived(); : This dynamically allocates memory for a Derived object on the heap and returns a pointer to it. This Derived object is 
//     initialized using its default constructor, if one exists.

// Base *ptr: Declares a pointer ptr of type Base. Since Derived is derived from Base, a pointer of type Base can point to an object of 
//     type Derived.

// So, in summary, this line creates a new Derived object on the heap and assigns its address to a pointer of type Base. This allows you 
//     to treat the Derived object polymorphically as if it were a Base object, enabling you to call member functions of Base through 
//     this pointer, including virtual functions that can be overridden in derived classes.