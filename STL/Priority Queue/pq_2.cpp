#include <iostream>
#include <queue>

int main() 
{
    // Creating a min heap with custom comparison function
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    // Inserting elements into the min heap
    minHeap.push(10);
    minHeap.push(30);
    minHeap.push(20);
    minHeap.push(5);
    minHeap.push(25);

    // Printing the elements of the min heap
    std::cout << "Min Heap: ";
    while (!minHeap.empty()) 
    {
        std::cout << minHeap.top() << " ";
        minHeap.pop(); // Removing the top element
    }
    std::cout << std::endl;

    return 0;
}

// when you want to create a min heap, you need to explicitly specify std::greater as the comparison function. This is because the default comparison 
// function std::less sorts elements in ascending order, which is not suitable for creating a min heap.
