#include <iostream>
#include <queue>
#include <vector>

void heapSort(std::vector<int>& arr) {
    // Create a max heap using priority_queue
    std::priority_queue<int> maxHeap;

    // Push all elements into the max heap
    for (int num : arr) {
        maxHeap.push(num);
    }

    // Extract elements from the max heap and place them back into the array
    int index = 0;
    while (!maxHeap.empty()) {
        arr[index++] = maxHeap.top();
        maxHeap.pop();
    }
}

int main() {
    std::vector<int> arr;

    arr.push_back(54);
    arr.push_back(53);
    arr.push_back(55);
    arr.push_back(52);
    arr.push_back(50);

    // Perform heap sort
    heapSort(arr);

    // Print the sorted array
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}



// arr.push_back(54);
// arr.push_back(53);
// arr.push_back(55);
// arr.push_back(52);
// arr.push_back(50);