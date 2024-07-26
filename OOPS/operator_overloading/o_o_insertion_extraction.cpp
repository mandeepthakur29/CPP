#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    Person() {}

    Person(const std::string& name, int age) : name(name), age(age) {}

    // Overloading the insertion operator (<<) as a friend function
    friend std::ostream& operator<<(std::ostream& os, const Person& person);

    // Overloading the extraction operator (>>) as a friend function
    friend std::istream& operator>>(std::istream& is, Person& person);
};

// Overloaded insertion operator implementation
std::ostream& operator<<(std::ostream& os, const Person& person) 
{
    os << "Name: " << person.name << ", Age: " << person.age;
    return os;
}

// Overloaded extraction operator implementation
std::istream& operator>>(std::istream& is, Person& person) 
{
    std::cout << "Enter name: ";
    is >> person.name;
    std::cout << "Enter age: ";
    is >> person.age;
    return is;
}

int main() 
{
    Person p("Alice", 30);
    std::cout << "Person details: " << p << std::endl;

    Person newPerson;
    std::cin >> newPerson;
    std::cout << "New person details: " << newPerson << std::endl;

    return 0;
}
