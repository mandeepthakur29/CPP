#include <iostream>

// Abstract base class
class Shape {
public:
    // Pure virtual function
    virtual void draw() const = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class 1
class Circle : public Shape {
public:
    // Implementation of the pure virtual function
    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

// Derived class 2
class Rectangle : public Shape {
public:
    // Implementation of the pure virtual function
    void draw() const override {
        std::cout << "Drawing a rectangle" << std::endl;
    }
};

int main() {
    // Shape shape; // Error: Cannot instantiate an abstract class

    Circle circle;
    Rectangle rectangle;

    // Draw shapes
    circle.draw();
    rectangle.draw();

    return 0;
}

// NOTE:

// An abstract base class in C++ is a class that is designed to be used only as a base class and cannot be instantiated directly. 
// It typically contains one or more pure virtual functions, making it an abstract class.
// Means that you cannot create objects of the abstract class itself. Instead, you can only create objects of its derived classes.

// In the context of an abstract base class:

// ->Abstract base classes typically contain one or more pure virtual functions.
// ->Because these functions have no implementation in the base class, the base class is considered incomplete and cannot be used to 
//     create objects.
// ->You can only create objects of concrete classes, i.e., classes that provide implementations for all the pure virtual functions 
//     inherited from the abstract base class.