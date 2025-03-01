#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int maximumFrequency(std::vector<int> &arr, int n) {
    // Create an unordered map to count the frequency of each element
    std::unordered_map<int, int> count;

    // Variables to track the maximum frequency and the element with maximum frequency
    int maxFreq = 0;
    int maxAns = 0;

    // First pass: Count the frequency of each element and track the maximum frequency
    for (int i = 0; i < n; i++) {
        count[arr[i]]++; // Increment the frequency of the current element
        maxFreq = std::max(maxFreq, count[arr[i]]); // Update maxFreq if the current element's frequency is higher
    }

    // Second pass: Find the element with the maximum frequency that appears first in the array
    for (int i = 0; i < n; i++) {
        if (maxFreq == count[arr[i]]) { // If current element's frequency matches maxFreq
            maxAns = arr[i]; // Set it as the result
            break; // Exit the loop as we want the first occurrence
        }
    }

    return maxAns; // Return the element with the maximum frequency
}

int main() {
    // Example input
    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    
    int n = arr.size();

    // Call the function and print the result
    int result = maximumFrequency(arr, n);
    std::cout << "The element with the maximum frequency is: " << result << std::endl;

    return 0;
}
