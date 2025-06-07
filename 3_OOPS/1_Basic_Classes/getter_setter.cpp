#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructor
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Getter for name
    std::string getName() const {
        return name;
    }

    // Setter for name
    void setName(const std::string& newName) {
        name = newName;
    }

    // Getter for age
    int getAge() const {
        return age;
    }

    // Setter for age
    void setAge(int newAge) {
        age = newAge;
    }
};

int main() {
    // Create a Person object
    Person person("Alice", 30);

    // Display the initial details
    std::cout << "Initial Details:" << std::endl;
    std::cout << "Name: " << person.getName() << ", Age: " << person.getAge() << std::endl;

    // Change the name and age using setter methods
    person.setName("Bob");
    person.setAge(25);

    // Display the updated details
    std::cout << "\nUpdated Details:" << std::endl;
    std::cout << "Name: " << person.getName() << ", Age: " << person.getAge() << std::endl;

    return 0;
}
