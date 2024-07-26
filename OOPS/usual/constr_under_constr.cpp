#include <iostream>
#include <string.h> // Include the header for string manipulation functions

class stu
{
    char name[10], course[20]; // Member variables to store name and course
    float fee; // Member variable to store fee

public:
    // Parameterized constructor for initializing name and course
    stu(const char* name, const char* course)
    {
        // Copy the name and course strings to member variables
        strcpy(this->name, name);
        strcpy(this->course, course);

        // Initialize fee to 0
        fee = 0;
    }

    // Parameterized constructor with fee, using member initializer list to call the other constructor
    stu(const char* name, const char* course, float fee) : stu(name, course)
    {
        // Set the fee to the provided value
        this->fee = fee;
    }

    // Member function to display student details
    void showStuc()
    {
        // Output student details
        std::cout << "Name: " << name << std::endl;
        std::cout << "Course: " << course << std::endl;
        std::cout << "Fee: " << fee << std::endl;
    }
};

int main()
{
    // Create student objects using different constructors
    stu s1("Manu", "CSE"); // Object s1 with default fee
    stu s2("Manu", "CSE", 80000); // Object s2 with specified fee

    // Display student details
    s1.showStuc();
    s2.showStuc();

    return 0;
}
