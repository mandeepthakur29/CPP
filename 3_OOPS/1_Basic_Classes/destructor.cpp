#include <iostream>
#include <string>

class Sample {
private:
    int a, b; // Private member variables

public:
   Sample() // Constructor definition
   {
        a = 10; // Initialize member variable 'a' with value 10
        b = 20; // Initialize member variable 'b' with value 20
   }

   ~Sample() // Destructor definition
   {
        std::cout << "a = " << a << std::endl; // Output the value of 'a' to console
        std::cout << "b = " << b << std::endl; // Output the value of 'b' to console
   }
};

int main() 
{
    Sample s;  // Creating an object of class Sample, which invokes the constructor

    return 0; // Return 0 to indicate successful completion of the program
}
