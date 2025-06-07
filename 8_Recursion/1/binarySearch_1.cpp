#include <iostream>

// Recursive function to perform binary search on a sorted array
bool binarySearch(int arr[], int start, int end, int key) {
    
    // Base case: If start index exceeds end index, key is not found
    if (start > end) {
        return false;
    }

    // Calculate mid index to divide the search space
    int mid = start + (end - start) / 2;

    // If key is found at mid index, return true
    if (arr[mid] == key) {
        return true;
    }

    // If key is smaller than mid element, search in the left half
    if (arr[mid] > key) {
        return binarySearch(arr, start, mid - 1, key);
    }

    // If key is larger than mid element, search in the right half
    if (arr[mid] < key) {
        return binarySearch(arr, mid + 1, end, key);
    }

    return false; // This line is redundant but kept for completeness
}

int main() {

    // Sorted array to perform binary search
    int arr[6] = {2, 5, 7, 9, 10, 13};
    int size = 6;
    int key = 16;  // Key to search in the array

    // Call binarySearch function and store result
    bool ans = binarySearch(arr, 0, 6, key);

    // Print the result (true if key is found, false otherwise)
    std::cout << std::boolalpha << ans << std::endl;

}
