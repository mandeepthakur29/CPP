#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructor with default arguments
    Person(const std::string& name = "Unknown", int age = 0) : name(name), age(age) {}

    // Method to display person details
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Creating objects using the constructor with default arguments
    Person person1; // No arguments provided, default values used
    Person person2("Alice", 30); // Arguments provided, custom values used

    // Displaying details of both persons
    std::cout << "Details of person1:" << std::endl;
    person1.display();

    std::cout << "\nDetails of person2:" << std::endl;
    person2.display();

    return 0;
}
