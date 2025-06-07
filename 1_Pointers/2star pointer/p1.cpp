#include <iostream>

int main() {
    int num = 5; // Integer variable
    int *ptr = &num; // Single pointer storing the memory address of num

    // Displaying the value and address of num using single pointer
    std::cout << "Value of num: " << num << std::endl;
    std::cout << "Address of num: " << &num << std::endl;
    std::cout << "Value stored in ptr (address of num): " << ptr << std::endl;
    std::cout << "Dereferenced value using ptr: " << *ptr << std::endl;
    std::cout << std::endl;

    int **ptr_to_ptr = &ptr; // Double pointer storing the memory address of ptr

    // Displaying the value and address of ptr using double pointer
    std::cout << "Value stored in ptr_to_ptr (address of ptr): " << ptr_to_ptr << std::endl;
    std::cout << "Dereferenced value using ptr_to_ptr (address of num): " << *ptr_to_ptr << std::endl;
    std::cout << "Dereferenced value using double dereference **ptr_to_ptr (value of num): " << **ptr_to_ptr << std::endl;

    return 0;
}
