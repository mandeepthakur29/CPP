#include <iostream>

class Shape {
public:
    virtual void draw() const {
        std::cout << "Drawing a shape." << std::endl;
    }
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle." << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a square." << std::endl;
    }
};

int main() 
{
    Shape *shapePtr;
    
    Circle circle;
    Square square;

    shapePtr = &circle;
    shapePtr->draw(); // Calls draw() of Circle

    shapePtr = &square;
    shapePtr->draw(); // Calls draw() of Square

    return 0;
}
