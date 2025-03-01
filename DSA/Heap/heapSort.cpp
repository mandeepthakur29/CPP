#include <iostream>
#include <algorithm>

// Function to heapify a subtree rooted at index 'i' in a max-heap
void heapify(int arr[], int n, int i)
{
    int largest = i;       // Initialize largest as root
    int left = 2 * i;      // Left child index (2*i)
    int right = 2 * i + 1; // Right child index (2*i + 1)

    // If the left child exists and is greater than the root (arr[i])
    if (left < n && arr[largest] < arr[left]) {
        largest = left;    // Update largest to be the left child
    }
    
    // If the right child exists and is greater than the current largest
    if (right < n && arr[largest] < arr[right]) {
        largest = right;   // Update largest to be the right child
    }

    // If the largest is not the root, a swap is needed
    if (largest != i) {
        std::swap(arr[largest], arr[i]); // Swap the root with the largest element

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

int main() {
    // Initialize the array with a dummy value at index 0 (not used)
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    
    // The actual size of the heap (number of elements to be heapified)
    int n = 5;

    // Build a max-heap by applying heapify starting from the last non-leaf node
    for (int i = n / 2; i > 0; i--) {
        heapify(arr, n, i);
    }

    // Print the max-heapified array
    std::cout << "Max-Heap array:" << std::endl;
    for (int i = 1; i <= n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
