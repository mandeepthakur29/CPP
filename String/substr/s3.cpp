//Using Negative Index for Extracting from the End:

#include <iostream>
#include <string>

int main() {
    std::string str = "Hello, World!";
    
    // Extract substring starting 7 characters from the end and of length 5
    std::string substr = str.substr(str.length() - 7, 5);
    std::cout << "Substring: " << substr << std::endl; // Output: "World"

    return 0;
}
