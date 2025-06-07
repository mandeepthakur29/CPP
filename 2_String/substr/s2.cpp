//Extracting a Substring with a Specified Length:

#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // Extract substring of length 5 starting from index 7
    std::string substr = str.substr(7, 5);
    std::cout << "Substring: " << substr << std::endl; // Output: "World"

    return 0;
}
