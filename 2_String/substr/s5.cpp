//Extracting Empty Substring:

#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // Extract an empty substring starting from index 5
    std::string substr = str.substr(5, 0);
    std::cout << "Substring: " << substr << std::endl; // Output: ""

    return 0;
}
