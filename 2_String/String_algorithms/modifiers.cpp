#include <iostream>
#include <string>

int main() {
    // Define a string
    std::string str = "Hello";

    // operator+=: Append characters to the end of the string
    str += " World";

    // append: Append characters to the end of the string
    str.append("!");

    // push_back: Append a single character to the end of the string
    str.push_back(' ');

    // assign: Assign a new value to the string
    std::string anotherString = "New String";
    str.assign(anotherString);

    // insert: Insert characters into the string at a specific position
    str.insert(0, "Prefix: ");

    // erase: Erase characters from the string at a specific position
    str.erase(7, 7); // Erase "String" part

    // replace: Replace characters in the string with new characters
    str.replace(7, 0, "Replaced"); // Replace nothing with "Replaced"

    // swap: Swap the contents of two strings
    std::string temp = "Temporary";
    std::string().swap(temp); // Clear temp string
    temp.swap(str);

    // pop_back: Remove the last character from the string
    str.pop_back(); // Remove the last character

    // Output the final string
    std::cout << "Final String: " << str << std::endl;

    return 0;
}
