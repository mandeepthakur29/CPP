#include <iostream>

// Base class
class Shape {
public:
    // Pure virtual function
    virtual void draw() const = 0;
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
    Circle circle;
    Rectangle rectangle;

    // Draw shapes
    circle.draw();
    rectangle.draw();

    return 0;
}

// NOTE:

// A pure virtual function in C++ is a virtual function declared within a base class that has no implementation in the base class and must 
// be overridden in derived classes. It is declared with the virtual keyword and assigned the value 0 (zero) at the end, indicating that 
// it is a pure virtual function.