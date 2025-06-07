#include <iostream>

class Vector2 {
private:
    double x, y;

public:
    Vector2(double x, double y) : x(x), y(y) {}

    // Overloaded subtraction operator (-)
    Vector2 operator-(const Vector2& other) const 
    {
        return Vector2(x - other.x, y - other.y);
    }

    // Method to display vector coordinates
    void display() const 
    {
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
};

int main() {
    Vector2 v1(5.0, 3.0);
    Vector2 v2(2.0, 1.0);

    Vector2 result = v1 - v2; // Using the overloaded subtraction operator

    std::cout << "Resultant vector after subtraction:" << std::endl;
    result.display();

    return 0;
}
