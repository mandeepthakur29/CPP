#include <iostream>

int main() {
    int original_variable = 42;

    // Creating a reference variable
    int& reference_variable = original_variable;

    // Using the reference variable
    reference_variable = 100;

    std::cout << "Original variable value: " << original_variable << std::endl;
    std::cout << "Reference variable value: " << reference_variable << std::endl;

    return 0;
}

// A reference variable in C++ is an alias or alternative name for an existing variable. It provides a way to access the same 
// memory location as another variable using a different name. Unlike pointers, which store memory addresses, references are 
// automatically dereferenced, and you can work with them as if you were directly accessing the original variable.