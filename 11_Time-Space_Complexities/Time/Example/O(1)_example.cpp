// O(1) example------>>>>>>>Constant Time it wil take.

#include <iostream>

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    
    // Accessing the element at index 2
    int element = arr[2];
    
    std::cout << "Element at index 2: " << element << std::endl;

    return 0;
}

// In this example, regardless of the size of the array arr, accessing an element by its index (e.g., arr[2]) takes a constant 
// amount of time. It doesn't matter if the array has 5 elements, 100 elements, or even 1 million elements; accessing an element by 
// index takes the same amount of time. Therefore, the time complexity of accessing an element by its index in an array is O(1).
