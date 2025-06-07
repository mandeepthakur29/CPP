#include <iostream>
#include <algorithm>

// Class to represent a Max Heap
class heap {
    public:
        int arr[100];  // Array to store heap elements. Size is fixed to 100 for simplicity.
        int size;      // Variable to keep track of the number of elements in the heap.

    // Constructor to initialize the heap
    heap() {
        arr[0] = -1;  // Initialize the first element as -1 (not used). Heap is 1-based index.
        size = 0;     // Initially, the heap has no elements.
    }

    // Function to insert a new value into the heap
    void insert(int val) {
        // Increase the size of the heap as we're adding a new element
        size = size + 1;
        int index = size;   // Index where the new element will be placed
        arr[index] = val;   // Place the new element at the end of the heap

        // Bubble up the new element to restore the heap property
        while(index > 1) {  // Continue until the element reaches the root
        
            int parent = index / 2;  // Find the parent index of the current element

            // If the parent is smaller than the current element, swap them
            if(arr[parent] < arr[index]) {
                std::swap(arr[parent], arr[index]);
                index = parent;  // Move up to the parent's index
            } else {
                // If the parent is larger, the heap property is restored, stop
                return;
            }
        }
    }

    // Function to print all elements of the heap
    void print() {
        for(int i = 1; i <= size; i++) {
            std::cout << arr[i] << " ";  // Print each element from the first to the last
        }
        std::cout << std::endl;  // Print a newline after printing all elements
    }
};

int main() {
    heap h;  // Create a new heap object

    // Insert elements into the heap
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    // Print the elements of the heap
    h.print();  // Expected output: 55 54 53 50 52

    return 0;
}
