#include <iostream>

int main()
{
    int arr[10];
    //arr = arr +1; //ERROR, but...

    int *ptr = &arr[0];
    std::cout<< ptr << std::endl;
    ptr = ptr + 1; //this work, why?
    std::cout<< ptr << std::endl;
}

// Arrays: When you declare an array, such as int arr[10];, arr represents the memory address of the first element of the array. 
//         In C++, the name of an array is implicitly converted to a pointer to its first element in most expressions. However, 
//         this conversion does not make the array itself a modifiable pointer.

// Pointers: On the other hand, pointers are variables that hold memory addresses. You can perform arithmetic operations on pointers, 
//           such as addition (ptr = ptr + 1;), which increments the pointer to point to the next memory location. This is valid 
//           because pointers are designed to be modifiable.

//In short, arithmetic operations are valid in pointers, but not in "arr".