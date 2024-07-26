#include <iostream>

class Test 
{
private:
    double x, y;

public:
    // Constructor
    Test(double x, double y) : x(x), y(y) {}

    // Method for vector addition
    Test Add(const Test &other) const 
    {
        return Test(x + other.x, y + other.y);
    }

    // Operator overloading for vector addition
    Test operator+(const Test &other) const 
    {
        return Add(other);
    }

    // In this definition, this object (which represents v1) is implicitly passed as the left operand, and the other object 
    // (which represents v2) is explicitly passed as the right operand.

    // So, in essence, when you write v1 + v2, the operator+ function is called with v1 as the left operand and v2 as the right operand.


    // Method to display vector coordinates
    void display() const 
    {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() 
{
    Test v1(1.5, 2.5);
    Test v2(2.0, 3.0);

    // Method-based addition
    Test sum_method = v1.Add(v2);
    std::cout << "Sum using method-based addition: ";
    sum_method.display();

    // Operator overloading addition
    Test sum_operator = v1 + v2;
    std::cout << "Sum using operator overloading: ";
    sum_operator.display();

    return 0;
}
