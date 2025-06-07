#include <iostream>

int main() {
    int size = 5;
    int *arr = new int[size];  // Dynamically allocate an array of 5 integers
    
    // Initialize the array elements
    for (int i = 0; i < size; ++i) {
        arr[i] = i * 10;  // Set each element to a multiple of 10
    }
    
    // Access and print the array elements
    for (int i = 0; i < size; ++i) 
    {
        std::cout << arr[i] << " ";  // Output: 0 10 20 30 40
    }
    
    // Don't forget to delete the dynamically allocated array to avoid memory leaks
    delete[] arr;
    
    return 0;
}
