//Extracting a Substring from a Position:

#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // Extract substring starting from index 7
    std::string substr1 = str.substr(7);
    std::cout << "Substring 1: " << substr1 << std::endl; // Output: "World!"

    // Extract substring starting from index 0 (entire string)
    std::string substr2 = str.substr(0);
    std::cout << "Substring 2: " << substr2 << std::endl; // Output: "Hello, World!"

    return 0;
}
