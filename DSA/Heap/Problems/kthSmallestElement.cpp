#include <iostream>
#include <queue>

int kthSmallestElement(int arr[], int l, int r, int k) {
    // Create a max heap using priority_queue
    std::priority_queue<int> pq;

    // Insert the first 'k' elements into the max heap
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // Iterate through the remaining elements
    for (int i = k; i <= r; i++) {
        // If the current element is smaller than the largest element in the heap
        if (arr[i] < pq.top()) {
            // Remove the largest element from the heap
            pq.pop();
            // Push the current element into the heap
            pq.push(arr[i]);
        }
    }

    // The root of the heap is the k-th smallest element
    int ans = pq.top();
    return ans;
}

int main() {
    // Example array
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // Find the 3rd smallest element

    int result = kthSmallestElement(arr, 0, n - 1, k);

    // Print the k-th smallest element
    std::cout << "The " << k << "rd smallest element is " << result << std::endl;

    return 0;
}
