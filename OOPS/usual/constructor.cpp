#include <iostream>
#include <conio.h>

class Circle
{
    float r;

    public:
        Circle()        // Default constructor
        {
            r = 5;
        }

        Circle(float r)     // Parameterized constructor
        {
            this->r = r;
        }

        void showArea()
        {
            std::cout << "Area = " << 3.14 * r * r << std::endl;
        }
};

int main()
{
    Circle a; //it will call Default constructor

    Circle b(2);  //It will call Parametrized constructor

    a.showArea();
    b.showArea();

    return 0;
}