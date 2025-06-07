//Also known as Max Heap (Maxi)


#include <iostream>
#include <queue>

int main() 
{
    // Creating a priority queue of integers
    std::priority_queue<int> pq;

    // Inserting elements into the priority queue
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(25);

    std::cout << "Priority Queue: ";
    while (!pq.empty()) 
    {
        std::cout << pq.top() << " ";
        pq.pop(); 
    }

    return 0;
}
