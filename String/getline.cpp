#include <iostream>

int main() {
    const int MAX_LENGTH = 100;
    char name[MAX_LENGTH];

    // Read a line of text from standard input
    std::cout << "Enter a sentence: ";
    std::cin.getline(name, MAX_LENGTH);

    // Output the line
    std::cout << "You entered: " << name << std::endl;

    return 0;
}
