#include <iostream>

class Point 
{
private:
    int x;
    int y;

public:
    Point(int x, int y) : x(x), y(y) {}

    // Declare the friend function to overload the + operator
    friend Point operator+(const Point& p1, const Point& p2);

    // Method to display the point coordinates
    void display() const 
    {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};

// Define the friend function to overload the + operator
Point operator+(const Point& p1, const Point& p2) 
{
    // Add the corresponding coordinates of the two points
    int newX = p1.x + p2.x;
    int newY = p1.y + p2.y;
    // Create a new Point object with the sum of coordinates
    Point sum(newX, newY);
    return sum;
}

int main() 
{
    // Create two Point objects
    Point p1(3, 4);
    Point p2(5, 2);

    // Add the two Point objects using operator overloading
    Point sum = p1 + p2;

    // Display the result
    std::cout << "Sum of points: ";
    sum.display();

    return 0;
}
