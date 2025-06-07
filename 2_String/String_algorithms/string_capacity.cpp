#include <iostream>
#include <string>

int main() {
    // Define a string
    std::string str = "Hello, World!";

    // Size and Length: Both return the number of characters in the string
    std::cout << "Size of string: " << str.size() << std::endl;   // Output: 13
    std::cout << "Length of string: " << str.length() << std::endl; // Output: 13

    // Max Size: Returns the maximum number of characters the string can hold
    std::cout << "Max size of string: " << str.max_size() << std::endl;

    // Resize: Resizes the string to the specified length
    str.resize(10); // Resize string to 10 characters
    std::cout << "Resized string: " << str << std::endl; // Output: "Hello, Wor"
    
    // Capacity: Returns the size of the storage space currently allocated for the string
    std::cout << "Capacity of string: " << str.capacity() << std::endl;

    // Reserve: Requests that the string capacity be at least enough to contain n characters
    str.reserve(20); // Reserve space for at least 20 characters
    std::cout << "Capacity after reserve: " << str.capacity() << std::endl;

    // Clear: Clears the contents of the string, making it an empty string
    str.clear();
    std::cout << "String after clear: " << str << std::endl; // Output: ""

    // Empty: Checks if the string is empty
    if (str.empty()) {
        std::cout << "String is empty." << std::endl;
    } else {
        std::cout << "String is not empty." << std::endl;
    }

    // Shrink to Fit: Reduces the capacity of the string to fit its size
    str.shrink_to_fit();
    std::cout << "Capacity after shrink to fit: " << str.capacity() << std::endl;

    return 0;
}
