#include <iostream>
#include <string>

int main() {
    // Create a string
    std::string str = "Hello, World!";

    // c_str(): Convert string to C-style string (const char*)
    const char* cstr = str.c_str(); // cstr now points to the C-style string equivalent of str
    std::cout << "C-style string: " << cstr << std::endl;

    // data(): Access the raw data of the string
    const char* data = str.data(); // data now points to the raw data of str
    std::cout << "Raw data: " << data << std::endl;

    // get_allocator(): Get the allocator used by the string
    std::allocator<char> alloc = str.get_allocator(); // alloc now holds the allocator used by str
    // Note: This example doesn't show usage of the allocator but demonstrates how to obtain it.

    // copy(): Copy a substring of the string into another string
    std::string copyStr;
    int count = 5;
    copyStr.resize(count); // Resize the destination string
    str.copy(&copyStr[0], count, 0); // Copy first 5 characters of str into copyStr
    std::cout << "Copied string: " << copyStr << std::endl;

    // find(): Find the first occurrence of a substring
    size_t pos = str.find("World"); // Find the position of "World" in str
    if (pos != std::string::npos) {
        std::cout << "Substring found at position: " << pos << std::endl;
    } else {
        std::cout << "Substring not found" << std::endl;
    }

    // rfind(): Find the last occurrence of a substring
    size_t rpos = str.rfind("o"); // Find the position of last occurrence of 'o' in str
    if (rpos != std::string::npos) {
        std::cout << "'o' found at position: " << rpos << std::endl;
    } else {
        std::cout << "'o' not found" << std::endl;
    }

    // find_first_of(): Find the first occurrence of any character from a set of characters
    size_t fpos = str.find_first_of("aeiou"); // Find the position of first vowel in str
    if (fpos != std::string::npos) {
        std::cout << "First vowel found at position: " << fpos << std::endl;
    } else {
        std::cout << "No vowel found" << std::endl;
    }

    // find_last_of(): Find the last occurrence of any character from a set of characters
    size_t lpos = str.find_last_of("aeiou"); // Find the position of last vowel in str
    if (lpos != std::string::npos) {
        std::cout << "Last vowel found at position: " << lpos << std::endl;
    } else {
        std::cout << "No vowel found" << std::endl;
    }

    // find_first_not_of(): Find the first occurrence of any character not present in a set of characters
    size_t fnpos = str.find_first_not_of("a-zA-Z, "); // Find the position of first non-alphabetic character in str
    if (fnpos != std::string::npos) {
        std::cout << "First non-alphabetic character found at position: " << fnpos << std::endl;
    } else {
        std::cout << "No non-alphabetic character found" << std::endl;
    }

    // find_last_not_of(): Find the last occurrence of any character not present in a set of characters
    size_t lnpos = str.find_last_not_of("a-zA-Z, "); // Find the position of last non-alphabetic character in str
    if (lnpos != std::string::npos) {
        std::cout << "Last non-alphabetic character found at position: " << lnpos << std::endl;
    } else {
        std::cout << "No non-alphabetic character found" << std::endl;
    }

    // substr(): Extract a substring from the string
    std::string substr = str.substr(7, 5); // Extract substring starting from index 7 of length 5
    std::cout << "Substring: " << substr << std::endl;

    // compare(): Compare two strings lexicographically
    std::string otherStr = "Hello, Universe!";
    int result = str.compare(otherStr); // Compare str with otherStr
    if (result < 0) {
        std::cout << "str comes before otherStr" << std::endl;
    } else if (result > 0) {
        std::cout << "str comes after otherStr" << std::endl;
    } else {
        std::cout << "str and otherStr are equal" << std::endl;
    }

    return 0;
}
