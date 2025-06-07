#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructor
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Copy constructor
    Person(const Person& old) : name(old.name), age(old.age) 
    {
        std::cout << "Copy constructor called" << std::endl;
    }

    // Method to display person details
    void display() const 
    {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Create a Person object
    Person person1("Alice", 30);

    // Use the copy constructor to create another Person object
    Person person2 = person1;

    // Display details of both objects
    std::cout << "Details of person1:" << std::endl;
    person1.display();

    std::cout << "\nDetails of person2 (copied from person1):" << std::endl;
    person2.display();

    return 0;
}