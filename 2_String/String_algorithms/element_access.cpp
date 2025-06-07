#include <iostream>
#include <string>

int main() {
    char seventhChar;
    char tenthChar;

    // Define a string
    std::string str = "Hello, World!";

    // Using operator[]
    // operator[] provides access to individual characters of the string using array syntax.
    // It does not perform bounds checking.
    char firstChar = str[0]; // Accessing the first character 'H'
    char fifthChar = str[5]; // Accessing the sixth character ' '

    // Using at()
    // at() provides access to individual characters of the string using array syntax.
    // It performs bounds checking and throws an out_of_range exception if the index is out of bounds.
    try {
        seventhChar = str.at(6); // Accessing the seventh character ','
        tenthChar = str.at(9);   // Accessing the tenth character 'l'
    } catch(const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << std::endl;
    }

    // Using back()
    // back() returns a reference to the last character of the string.
    char lastChar = str.back(); // Accessing the last character '!'
    
    // Using front()
    // front() returns a reference to the first character of the string.
    char firstCharAgain = str.front(); // Accessing the first character 'H'

    // Output the results
    std::cout << "Using operator[]:" << std::endl;
    std::cout << "First character: " << firstChar << std::endl;
    std::cout << "Fifth character: " << fifthChar << std::endl;

    std::cout << "\nUsing at():" << std::endl;
    std::cout << "Seventh character: " << seventhChar << std::endl;
    std::cout << "Tenth character: " << tenthChar << std::endl;

    std::cout << "\nUsing back():" << std::endl;
    std::cout << "Last character: " << lastChar << std::endl;

    std::cout << "\nUsing front():" << std::endl;
    std::cout << "First character: " << firstCharAgain << std::endl;

    return 0;
}
