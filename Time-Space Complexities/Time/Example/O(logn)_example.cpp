//Sure, let's consider the binary search algorithm as an example of an algorithm with O(log n) time complexity.

int binarySearch(int arr[], int target, int left, int right) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        // Check if the target is at the middle
        if (arr[mid] == target) {
            return mid;
        }
        
        // If the target is smaller, search in the left half
        if (arr[mid] > target) {
            right = mid - 1;
        }
        // If the target is larger, search in the right half
        else {
            left = mid + 1;
        }
    }
    
    // If the target is not found, return -1
    return -1;
}

// The time complexity of binary search is O(log n), where n is the number of elements in the array. This means that the time taken 
// by binary search grows logarithmically with the size of the input array. As a result, even for large arrays, binary search 
// can find the target element efficiently with a relatively small number of comparisons.
