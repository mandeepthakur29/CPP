//Extracting Last Few Characters:

#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // Extract last 6 characters
    std::string substr = str.substr(str.length() - 6);
    std::cout << "Substring: " << substr << std::endl; // Output: "World!"

    return 0;
}