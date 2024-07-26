#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(42);
    std::weak_ptr<int> weakPtr = sharedPtr; // Creating a weak pointer from a shared pointer

    // Accessing the value using the weak pointer
    if (auto temp = weakPtr.lock()) { // Locking the weak pointer to create a shared_ptr
        std::cout << "Value using weak pointer: " << *temp << std::endl;
    } else {
        std::cout << "Weak Pointer is expired." << std::endl;
    }

    // Resetting the shared pointer
    sharedPtr.reset();

    // Accessing the value again using the weak pointer
    if (auto temp = weakPtr.lock()) { // Locking the weak pointer to create a shared_ptr
        std::cout << "Value using weak pointer: " << *temp << std::endl;
    } else {
        std::cout << "Weak Pointer is expired." << std::endl;
    }

    return 0;
}
